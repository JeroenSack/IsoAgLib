/***************************************************************************
                          base_c.h  - working on Base Data Msg Type 1, 2
                                      and Calendar; stores, updates  and
                                      delivers all base data informations
                                      from CANCustomer_c derived for CAN
                                      sending and receiving interaction;
                                      from ElementBase_c derived for
                                      interaction with other IsoAgLib objects
                             -------------------
    begin                 Fri Apr 07 2000
    copyright            : (C) 2000 - 2004 by Dipl.-Inform. Achim Spangler
    email                : a.spangler@osb-ag:de
 ***************************************************************************/

/***************************************************************************
 *                                                                         *
 * This file is part of the "IsoAgLib", an object oriented program library *
 * to serve as a software layer between application specific program and   *
 * communication protocol details. By providing simple function calls for  *
 * jobs like starting a measuring program for a process data value on a    *
 * remote ECU, the main program has not to deal with single CAN telegram   *
 * formatting. This way communication problems between ECU's which use     *
 * this library should be prevented.                                       *
 * Everybody and every company is invited to use this library to make a    *
 * working plug and play standard out of the printed protocol standard.    *
 *                                                                         *
 * Copyright (C) 2000 - 2004 Dipl.-Inform. Achim Spangler                  *
 *                                                                         *
 * The IsoAgLib is free software; you can redistribute it and/or modify it *
 * under the terms of the GNU General Public License as published          *
 * by the Free Software Foundation; either version 2 of the License, or    *
 * (at your option) any later version.                                     *
 *                                                                         *
 * This library is distributed in the hope that it will be useful, but     *
 * WITHOUT ANY WARRANTY; without even the implied warranty of              *
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the GNU       *
 * General Public License for more details.                                *
 *                                                                         *
 * You should have received a copy of the GNU General Public License       *
 * along with IsoAgLib; if not, write to the Free Software Foundation,     *
 * Inc., 59 Temple Place, Suite 330, Boston, MA  02111-1307  USA           *
 *                                                                         *
 * As a special exception, if other files instantiate templates or use     *
 * macros or inline functions from this file, or you compile this file and *
 * link it with other works to produce a work based on this file, this file*
 * does not by itself cause the resulting work to be covered by the GNU    *
 * General Public License. However the source code for this file must still*
 * be made available in accordance with section (3) of the                 *
 * GNU General Public License.                                             *
 *                                                                         *
 * This exception does not invalidate any other reasons why a work based on*
 * this file might be covered by the GNU General Public License.           *
 *                                                                         *
 * Alternative licenses for IsoAgLib may be arranged by contacting         *
 * the main author Achim Spangler by a.spangler@osb-ag:de                  *
 ***************************************************************************/

 /**************************************************************************
 *                                                                         *
 *     ###    !!!    ---    ===    IMPORTANT    ===    ---    !!!    ###   *
 * Each software module, which accesses directly elements of this file,    *
 * is considered to be an extension of IsoAgLib and is thus covered by the *
 * GPL license. Applications must use only the interface definition out-   *
 * side :impl: subdirectories. Never access direct elements of __IsoAgLib  *
 * and __HAL namespaces from applications which shouldnt be affected by    *
 * the license. Only access their interface counterparts in the IsoAgLib   *
 * and HAL namespaces. Contact a.spangler@osb-ag:de in case your applicat- *
 * ion really needs access to a part of an internal namespace, so that the *
 * interface might be extended if your request is accepted.                *
 *                                                                         *
 * Definition of direct access:                                            *
 * - Instantiation of a variable with a datatype from internal namespace   *
 * - Call of a (member-) function                                          *
 * Allowed is:                                                             *
 * - Instatiation of a variable with a datatype from interface namespace,  *
 *   even if this is derived from a base class inside an internal namespace*
 * - Call of member functions which are defined in the interface class     *
 *   definition ( header )                                                 *
 *                                                                         *
 * Pairing of internal and interface classes:                              *
 * - Internal implementation in an :impl: subdirectory                     *
 * - Interface in the parent directory of the corresponding internal class *
 * - Interface class name IsoAgLib::iFoo_c maps to the internal class      *
 *   __IsoAgLib::Foo_c                                                     *
 *                                                                         *
 * AS A RULE: Use only classes with names beginning with small letter :i:  *
 ***************************************************************************/
#ifndef BASE_H
#define BASE_H

/* *************************************** */
/* ********** include headers ************ */
/* *************************************** */
//#include <Application_Config/isoaglib_config.h>
#include <IsoAgLib/typedef.h>
#include "../ibasetypes.h"
#include <IsoAgLib/driver/system/impl/system_c.h>
#include <IsoAgLib/util/impl/singleton.h>
#include <IsoAgLib/util/impl/cancustomer_c.h>
#include <IsoAgLib/util/impl/elementbase_c.h>
#include <IsoAgLib/util/impl/getypos_c.h>

#include "basepkg_c.h"

// Begin Namespace __IsoAgLib
namespace __IsoAgLib {



class Base_c;
typedef SINGLETON(Base_c) SingletonBase_c;
/**
  working on Base Data Msg Type 1, 2 and Calendar;
  stores, updates  and delivers all base data informations;
  Derive from ElementBase_c to register in Scheduler_c for timeEvent trigger
  Derive from CANCustomer to register FilterBox'es in CANIO_c to receive CAN messages
  Derive from SINGLETON to create a Singleton which manages one global accessible singleton
   per IsoAgLib instance (if only one IsoAgLib instance is defined in application config, no overhead is produced).
  *@author Dipl.-Inform. Achim Spangler
*/
class Base_c : public ElementBase_c, public CANCustomer_c, public SingletonBase_c {
public: // Public methods
	/* ********************************************* */
  /** \name Management Functions for class Base_c  */
	/*@{*/

  /**
    initialise element which can't be done during construct;
    above all create the needed FilterBox_c instances, to receive
    the needed CAN msg with base msg type 1,2 and calendar

    possible errors:
        * dependant error in CANIO_c problems during insertion of new FilterBox_c entries for IsoAgLibBase
    @param rpc_gtp optional pointer to the GETY_POS variable of the responsible member instance (pointer enables automatic value update if var val is changed)
		@param rt_mySendSelection optional Bitmask of base data to send ( default send nothing )
  */
  void init(GetyPos_c* rpc_gtp = NULL, IsoAgLib::BaseDataGroup_t rt_mySendSelection = IsoAgLib::BaseDataNothing );

  /** every subsystem of IsoAgLib has explicit function for controlled shutdown
    */
  void close( void );

  /**
    functions with actions, which must be performed periodically
    -> called periodically by Scheduler_c
    ==> sends base msg if configured in the needed rates

    possible errors:
        * dependant error in CANIO_c on CAN send problems
    @see CANPkg_c::getData
    @see CANPkgExt_c::getData
    @see CANIO_c::operator<<
    @return true -> all planned activities performed in allowed time
  */
  bool timeEvent( void );
	/** check if filter boxes shall be created - create only ISO or DIN filters based
			on active local idents which has already claimed an address
			--> avoid to much Filter Boxes
		*/
	void checkCreateReceiveFilter( void );

  /**
    config the Base_c object after init -> set pointer to gtp and
    config send/receive of different base msg types
    @param rpc_gtp pointer to the GETY_POS variable of the responsible member instance (pointer enables automatic value update if var val is changed)
		@param rt_mySendSelection optional Bitmask of base data to send ( default send nothing )
  */
  void config(GetyPos_c* rpc_gtp, IsoAgLib::BaseDataGroup_t rt_mySendSelection);

  /** destructor for Base_c which has nothing to do */
  virtual ~Base_c() { close();};
  /**
    process received base msg and store updated value for later reading access;
    called by FilterBox_c::processMsg after receiving a msg

    possible errors:
        * Err_c::lbsBaseSenderConflict base msg recevied from different member than before
    @see CANIO_c::processMsg
  */
  virtual bool processMsg();

  #ifdef USE_ISO_11783
  /**
    process a ISO11783 base information PGN
  */
  bool isoProcessMsg();
  /**
    send a ISO11783 base information PGN
  */
  bool isoTimeEvent( void );
  /**
    send ISO11783 calendar PGN
    @param rc_gtp GETY_POS code off calling item which wants to send
    @parm ri32_time timestamp where calendar was last sent (default autodetect)

    possible errors:
        * dependant error in CANIO_c on CAN send problems
    @see CANPkg_c::getData
    @see CANPkgExt_c::getData
    @see CANIO_c::operator<<
  */
  void isoSendCalendar(GetyPos_c rc_gtp);
  #endif
	/*@}*/

  /* ******************************************* */
  /** \name Set Values for periodic send on BUS  */
	/*@{*/

  /**
    set the value of real speed (measured by radar)
    @param ri16_val value to store as real radar measured speed
  */
  void setSpeedReal(int16_t ri16_val) {i16_speedReal = ri16_val;};
  /**
    set the value of theoretical speed (calculated from gear)
    @param ri16_val value to store as theoretical gear calculated speed
  */
  void setSpeedTheor(int16_t ri16_val) {i16_speedTheor = ri16_val;};

  /**
    set the real (radar measured) driven distance with int16_t val
    @param ri16_val value to store as real radar measured distance
  */
  void setDistReal(int16_t ri16_val)
  { // use function to detect and handle 16bit integer overflows
    setOverflowSecure(i32_distReal, i16_lastDistReal, ri16_val);
  };

  /**
    set the real (radar measured) driven distance with int32_t val
    @param rreflVal value to store as real radar measured distance
  */
  void setDistReal(const int32_t& rreflVal);

  /**
    set the theoretical (gear calculated) driven distance with int16_t val
    @param ri16_val value to store as theoretical (gear calculated) driven distance
  */
  void setDistTheor(int16_t ri16_val)
  { // use function to detect and handle 16bit integer overflows
    setOverflowSecure(i32_distTheor, i16_lastDistTheor, ri16_val);
  };
  /**
    set the theoretical (gear calculated) driven distance with int32_t val
    @param rreflVal value to store as theoretical (gear calculated) driven distance
  */
  void setDistTheor(const int32_t& rreflVal);

  /**
    set rear PTO
    @param ri16_val value to store as the speed of the rear PTO
  */
  void setPtoRear(int16_t ri16_val){i16_ptoRear = ri16_val;};
  /**
    set front PTO
    @param ri16_val value to store as the speed of the front PTO
  */
  void setPtoFront(int16_t ri16_val){i16_ptoFront = ri16_val;};

	#ifdef USE_DIN_9684
  /** deliver rear left draft */
  void setRearLeftDraft( int16_t ri16_val ) { i16_rearLeftDraft = ri16_val;};
  /** deliver rear right draft */
  void setRearRightDraft( int16_t ri16_val ) { i16_rearRightDraft = ri16_val;};
  /** deliver rear total draft Newton */
  void setRearDraftNewton( int16_t ri16_val ) { i16_rearDraftNewton = ri16_val;};
  /** deliver rear total draft Percent */
  void setRearDraftNominal( uint8_t rui8_val ) { ui8_rearDraftNominal = rui8_val;};
  /** deliver fuel consumption L/h */
  void setFuelRate( int16_t ri16_val ) { i16_fuelRate = ri16_val;};
  /** deliver fuel temperature �C */
  void setFuelTemperature( uint8_t rui8_val ) { ui8_fuelTemperature = rui8_val;};
	#endif
  #ifdef USE_ISO_11783
  /** set front hitch draft
    * @return front hitch draft [-320.000N;322.550N]; 1N/bit
    */
  void setHitchFrontDraft(int32_t ri32_val)
    { i16_frontDraft = ((ri32_val + 320000) / 10);};
  /** set rear hitch draft
    * @return rear hitch draft [-320.000N;322.550N]; 1N/bit
    */
  void setHitchRearDraft(int32_t ri32_val)
    { i16_rearDraft = ((ri32_val + 320000) / 10);};
  /** set front hitch nominal link force
    * @return front nominal link force [-100%;100%]; 1 promille per bit
    */
  void setHitchFrontLowerLinkForce(int16_t ri16_val)
    { ui8_frontLinkForce = ((ri16_val + 1000) / 8);};
  /** set rear hitch nominal link force
    * @return rear nominal link force [-100%;100%]; 1 promille per bit
    */
  void setHitchRearLowerLinkForce(int16_t ri16_val)
    { ui8_rearLinkForce = ((ri16_val + 1000) / 8);};
  /** set explicit information whether front PTO is engaged
    * @param rt_val IsoActive -> PTO is engaged
    */
  void setPtoFrontEngaged(IsoAgLib::IsoActiveFlag_t rt_val) { t_frontPtoEngaged = rt_val;};
  /** set explicit information whether rear PTO is engaged
    * @param rt_val IsoActive -> PTO is engaged
    */
  void setPtoRearEngaged(IsoAgLib::IsoActiveFlag_t rt_val) { t_rearPtoEngaged = rt_val;};
  /** set std RPM of front PTO (1000 n/min; 540 n/min)
    * @param rt_val IsoActive == 1000 n/min; false == 540 n/min
    */
  void setPtoFront1000(IsoAgLib::IsoActiveFlag_t rt_val) { t_frontPto1000 = rt_val;};
  /** set std RPM of rear PTO (1000 n/min; 540 n/min)
    * @param rt_val IsoActive == 1000 n/min; false == 540 n/min
    */
  void setPtoRear1000(IsoAgLib::IsoActiveFlag_t rt_val) { t_rearPto1000 = rt_val;};
  /** set economy mode of front PTO
    * @param rt_val IsoActive -> front PTO is in economy mode
    */
  void setPtoFrontEconomy(IsoAgLib::IsoActiveFlag_t rt_val) { t_frontPtoEconomy = rt_val;};
  /** set economy mode of rear PTO
    * @param rt_val IsoActive -> rear PTO is in economy mode
    */
  void setPtoRearEconomy(IsoAgLib::IsoActiveFlag_t rt_val) { t_rearPtoEconomy = rt_val;};

  /**
    * set the ISO key switch state of the tractor
    * @param rt_val IsoActive -> key switch ON
    */
  void setKeySwitch(IsoAgLib::IsoActiveFlag_t rt_val) { t_keySwitch = rt_val;};
  /** set the maximum power time of the tractor in [min]
    * @return maximum power time of the tractor in [min]
    */
  void setMaxPowerTime(uint8_t rui8_val) { ui8_maxPowerTime = rui8_val;};
  /** force maintain power from tractor
    * @param rb_ecuPower true -> maintain ECU power
    * @param rb_actuatorPower -> maintain actuator power
    * @param rt_implTransport IsoActive -> implement is in transport state
    * @param rt_implPark IsoActive -> implement is in park state
    * @param rt_implWork IsoActive -> implement is in work state
    */
  void forceMaintainPower( bool rb_ecuPower, bool rb_actuatorPower, IsoAgLib::IsoActiveFlag_t rt_implTransport,
    IsoAgLib::IsoActiveFlag_t rt_implPark, IsoAgLib::IsoActiveFlag_t rt_implWork);

  #endif
  /**
    set engine speed
    @param ri16_val value to store as engine rpm value
  */
  void setEngine(int16_t ri16_val){i16_engine = ri16_val;};

  /**
    set rear hitch
    @param rb_val uint8_t value to store as position of rear hitch
  */
  void setHitchRear(uint8_t rb_val){ b_hitchRear = rb_val;};
  /**
    set front hitch
    @param rb_val uint8_t value to store as position of front hitch
  */
  void setHitchFront(uint8_t rb_val){ b_hitchFront = rb_val;};

  /**
    set the calendar value
    @param ri16_year value to store as year
    @param rb_month value to store as month
    @param rb_day value to store as day
    @param rb_hour value to store as hour
    @param rb_minute value to store as minute
    @param rb_second value to store as second
  */
  void setCalendar(int16_t ri16_year, uint8_t rb_month, uint8_t rb_day, uint8_t rb_hour, uint8_t rb_minute, uint8_t rb_second);

	/*@}*/

	/* ****************************************************** */
  /** \name Retrieve Values which are sent from other ECUs  */
	/*@{*/

  /**
    get the value of real speed (measured by radar)
    @return actual radar measured speed value
  */
  int16_t speedReal() const { return i16_speedReal;};
  /**
    get the value of theoretical speed (calculated from gear)
    @return theoretical gear calculated speed value
  */
  int16_t speedTheor() const { return i16_speedTheor;};

  /**
    get the real driven distance with int16_t val
    @return actual radar measured driven distance value
  */
  int32_t distReal() const { return i32_distReal;};
  /**
    get the real driven distance with int16_t val
    @return actual gear calculated driven distance value
  */
  int32_t distTheor() const { return i32_distTheor;};

  /**
    get rear pto
    @return actual rpm speed of rear PTO
  */
  int16_t ptoRear() const { return i16_ptoRear;};
  /**
    get front pto
    @return actual rpm speed of front PTO
  */
  int16_t ptoFront() const { return i16_ptoFront;};

  /**
    get engine speed
    @return actual engine rpm speed value
  */
  int16_t engine() const { return i16_engine;};

  /**
    get rear hitch
    @return actual position of rear hitch
  */
  uint8_t hitchRear() const {return  b_hitchRear;};
  /**
    get front hitch
    @return actual position of front hitch
  */
  uint8_t hitchFront() const {return  b_hitchFront;};

  /** check if a calendar information was received since init */
  bool isCalendarReceived() const
  { // check if default data from init is still in vars
    return ( ( bit_calendar.day == 1 ) && ( bit_calendar.month == 1 ) && ( bit_calendar.year == 0 )
          && ( bit_calendar.second == 0 ) && ( bit_calendar.minute == 0 ) && ( bit_calendar.hour == 0 ) )?false:true;};
  /**
    get the calendar year value
    @return actual calendar year value
  */
  int16_t year() const {return bit_calendar.year;};
  /**
    set the calendar year value
    @param rui16_year actual calendar year value
  */
  void setYear(uint16_t rui16_year){i32_lastCalendarSet = System_c::getTime();bit_calendar.year = rui16_year;};
  /**
    get the calendar month value
    @return actual calendar month value
  */
  uint8_t month() const {return bit_calendar.month;};
  /**
    set the calendar month value
    @param rb_month actual calendar month value
  */
  void setMonth(uint8_t rb_month){i32_lastCalendarSet = System_c::getTime();bit_calendar.month = rb_month;};
  /**
    get the calendar day value
    @return actual calendar day value
  */
  uint8_t day() const {return bit_calendar.day + (calendarSetAge() / 86400000);};
  /**
    set the calendar day value
    @param rb_day actual calendar day value
  */
  void setDay(uint8_t rb_day){i32_lastCalendarSet = System_c::getTime();bit_calendar.day = rb_day;};
  /**
    get the calendar hour value
    @return actual calendar hour value
  */
  uint8_t hour() const {return ((bit_calendar.hour + (calendarSetAge() / 3600000))%24);};
  /**
    set the calendar hour value
    @param rb_hour actual calendar hour value
  */
  void setHour(uint8_t rb_hour){i32_lastCalendarSet = System_c::getTime();bit_calendar.hour = rb_hour;};
  /**
    get the calendar minute value
    @return actual calendar minute value
  */
  uint8_t minute() const {return ((bit_calendar.minute + (calendarSetAge() / 60000))%60);};
  /**
    set the calendar minute value
    @param rb_minute actual calendar minute value
  */
  void setMinute(uint8_t rb_minute){i32_lastCalendarSet = System_c::getTime();bit_calendar.minute = rb_minute;};
  /**
    get the calendar second value
    @return actual calendar second value
  */
  uint8_t second() const {return ((bit_calendar.second + (calendarSetAge() / 1000))%60);};
  /**
    set the calendar second value
    @param rb_second actual calendar second value
  */
  void setSecond(uint8_t rb_second){i32_lastCalendarSet = System_c::getTime();bit_calendar.second = rb_second;};

  /**
    deliver the gtp of the sender of the base data

    possible errors:
        * Err_c::range rui8_typeNr doesn't match valid base msg type number
    @param rt_typeGrp base msg type no of interest: BaseDataGroup1 | BaseDataGroup2 | BaseDataCalendar
    @return GETY_POS code of member who is sending the intereested base msg type
  */
  GetyPos_c senderGtp(IsoAgLib::BaseDataGroup_t rt_typeGrp);

	#ifdef USE_DIN_9684
  /** deliver rear left draft */
  int rearLeftDraft() const { return i16_rearLeftDraft;};
  /** deliver rear right draft */
  int rearRightDraft() const { return i16_rearRightDraft;};
  /** deliver rear total draft Newton */
  int rearDraftNewton() const { return i16_rearDraftNewton;};
  /** deliver rear total draft Percent */
  int rearDraftNominal() const { return ui8_rearDraftNominal;};
  /** deliver fuel consumption L/h */
  int fuelRate() const { return i16_fuelRate;};
  /** deliver fuel temperature �C */
  int fuelTemperature() const { return ui8_fuelTemperature;};
	#endif
	#ifdef USE_ISO_11783
  /** deliver front hitch draft
    * @return front hitch draft [-320.000N;322.550N]; 1N/bit
    */
  int32_t hitchFrontDraft() const { return ((i16_frontDraft * 10) - 320000);};
  /** deliver rear hitch draft
    * @return rear hitch draft [-320.000N;322.550N]; 1N/bit
    */
  int32_t hitchRearDraft() const { return ((i16_rearDraft * 10) - 320000);};
  /** deliver front hitch nominal link force
    * @return front nominal link force [-100%;100%]; 1 promille per bit
    */
  int16_t hitchFrontLowerLinkForce() const
    { return ((static_cast<int16_t>(ui8_frontLinkForce) * 8) - 1000);};
  /** deliver rear hitch nominal link force
    * @return rear nominal link force [-100%;100%]; 1 promille per bit
    */
  int16_t hitchRearLowerLinkForce() const
    { return ((static_cast<int16_t>(ui8_rearLinkForce) * 8) - 1000);};
  /** deliver explicit information whether front PTO is engaged
    * @return IsoActive -> PTO is engaged
    */
  IsoAgLib::IsoActiveFlag_t ptoFrontEngaged() const { return t_frontPtoEngaged;};
  /** deliver explicit information whether rear PTO is engaged
    * @return IsoActive -> PTO is engaged
    */
  IsoAgLib::IsoActiveFlag_t ptoRearEngaged() const { return t_rearPtoEngaged;};
  /** deliver std RPM of front PTO (1000 n/min; 540 n/min)
    * @return IsoActive == 1000 n/min; false == 540 n/min
    */
  IsoAgLib::IsoActiveFlag_t ptoFront1000() const { return t_frontPto1000;};
  /** deliver std RPM of rear PTO (1000 n/min; 540 n/min)
    * @return IsoActive == 1000 n/min; false == 540 n/min
    */
  IsoAgLib::IsoActiveFlag_t ptoRear1000() const { return t_rearPto1000;};
  /** deliver economy mode of front PTO
    * @return IsoActive -> front PTO is in economy mode
    */
  IsoAgLib::IsoActiveFlag_t ptoFrontEconomy() const { return t_frontPtoEconomy;};
  /** deliver economy mode of rear PTO
    * @return IsoActive -> rear PTO is in economy mode
    */
  IsoAgLib::IsoActiveFlag_t ptoRearEconomy() const { return t_rearPtoEconomy;};

  /**
    * deliver the ISO key switch state of the tractor
    * @return IsoActive -> key switch ON
    */
  IsoAgLib::IsoActiveFlag_t keySwitch() const { return t_keySwitch;};
  /** deliver the maximum power time of the tractor in [min]
    * @return maximum power time of the tractor in [min]
    */
  uint8_t maxPowerTime() const { return ui8_maxPowerTime;};

  /** deliver last receive time of maintain power request
    * @return time in [ms] since system start -> comparable to system time
    */
  int32_t lastMaintainPowerRequest() const
    { return ui32_lastMaintainPowerRequest;};

  /** check whether maintenance of ECU power was requested */
  bool maintainEcuPower() const { return b_maintainEcuPower;};

  /** check whether maintenance of actuator power was requested */
  bool maintainActuatorPower() const { return b_maintainActuatorPower;};
  /** check whether maintenance of power
    * for implement in transport state was requested */
  bool maintainPowerForImplInTransport() const
    { return b_maintainPowerForImplInTransport;};
  /** check whether maintenance of power
    * for implement in park state was requested */
  bool maintainPowerForImplInPark() const
    { return b_maintainPowerForImplInPark;};
  /** check whether maintenance of power
    * for implement in work state was requested */
  bool maintainPowerForImplInWork() const
    { return b_maintainPowerForImplInWork;};

	/** deliver raw GPS Latitude */
	int32_t getGpsLatitudeRaw( void ) const { return i32_latitudeRaw; };
	/** deliver raw GPS Longitude */
	int32_t getGpsLongitudeRaw( void ) const { return i32_longitudeRaw; };
	#if defined(USE_FLOAT_DATA_TYPE) || defined(USE_GPS)
	/** deliver Minute GPS Latitude */
	float getGpsLatitudeMinute( void ) const { return ( ( float( i32_latitudeRaw ) / 1000000.0 ) - 210.0 ); };
	/** deliver Minute GPS Longitude */
	float getGpsLongitudeMinute( void ) const { return ( ( float( i32_longitudeRaw ) / 1000000.0 ) - 210.0 ); };
	#endif
	/** deliver GPS altitude - ?? [cm] ??
		\todo check for correct altitude unit
		*/
	uint32_t getGpsAltitude( void ) const { return ui32_altitude; };
	/** deliver GPS receive qualitiy
		\todo probably wrong decoded -> please correct decoding in case you have better sources
	*/
	IsoAgLib::IsoGpsRecMode_t getGpsMode( void ) const { return t_gpsMode;};
	/** deliver GPS speed
		\todo probably wrong decoded -> please correct decoding in case you have better sources
		*/
	int16_t getGpsSpeed( void ) const { return i16_speedGps;};
	/** deliver GPS Heading
		\todo probably wrong decoded -> please correct decoding in case you have better sources
		*/
	int16_t getGpsHeading( void ) const { return i16_headingGps; };

	#endif

	/*@}*/


private:
  // Private methods
  friend class SINGLETON(Base_c);
  /**
    HIDDEN constructor for a Base_c object instance which can optional
    set the configuration for send/receive for base msg type 1,2
    and calendar
    NEVER instantiate a variable of type Base_c within application
    only access Base_c via getBaseInstance() or getBaseInstance( int riLbsBusNr ) in case more than one ISO11783 or DIN9684 BUS is used for IsoAgLib
    @param rpc_gtp optional pointer to the GETY_POS variable of the responsible member instance (pointer enables automatic value update if var val is changed)
		@param rt_mySendSelection optional Bitmask of base data to send ( default send nothing )
  */
  Base_c(GetyPos_c* rpc_gtp = NULL, IsoAgLib::BaseDataGroup_t rt_mySendSelection = IsoAgLib::BaseDataNothing )
		{ init( rpc_gtp, rt_mySendSelection );};
  /**
    deliver reference to data pkg
    @return reference to the member BasePkg_c, which encapsulates the CAN send structure
  */
  BasePkg_c& data(){return c_data;};
  /**
    deliver reference to data pkg as reference to CANPkgExt_c
    to implement the base virtual function correct
  */
  CANPkgExt_c& dataBase();

  /**
    update distance values ; react on int16_t overflow
    @param reflVal to be updated value as int32_t variable
    @param refiVal to be updated value as 16bit int16_t variable
    @param rrefiNewVal new value given as reference to 16bit int
  */
  static void setOverflowSecure(int32_t& reflVal, int16_t& refiVal, const int16_t& rrefiNewVal);

  /**
    get int16_t overflowed val from long
    @param rreflVal value as int32_t (32bit) variable
    @return 16bit int16_t calculated with counting overflow from 32767 to (-32766)
  */
  static int16_t long2int(const int32_t& rreflVal);

  /**
    deliver time between now and last calendar set in [msec]
    @return msec since last calendar set
  */
  int32_t calendarSetAge() const {return (System_c::getTime() - i32_lastCalendarSet);};

private:
  // Private attributes
  /** temp data where received data is put */
  BasePkg_c c_data;
  /** last time of base_1 msg [100ms] */
  uint8_t ui8_lastBase1;
  /** last time of base_2 msg [100ms] */
  uint8_t ui8_lastBase2;
  /** last time of base_3 msg [100ms] */
  uint8_t ui8_lastBase3;
  /** last time of fuel msg [100ms] */
  uint8_t ui8_lastFuel;
  /** last time of calendar msg [100ms] */
  uint8_t ui8_lastCalendar;
  /**
    last timestamp where calendar was set
    -> use this to calculate new time
  */
  int32_t i32_lastCalendarSet;
	#ifdef USE_DIN_9684
	/** flag to detect, if receive filters for DIN are created */
	bool b_dinFilterCreated;
  /** NEW from AGCO Fendt Vario: rear left draft */
  int16_t i16_rearLeftDraft;
  /** NEW from AGCO Fendt Vario: rear right draft */
  int16_t i16_rearRightDraft;
  /** NEW from AGCO Fendt Vario: rear total draft Newton */
  int16_t i16_rearDraftNewton;
  /** NEW from AGCO Fendt Vario: rear total draft Percent */
  uint8_t ui8_rearDraftNominal;
  /** NEW: fuel consumption L/h */
  int16_t i16_fuelRate;
  /** NEW from AGCO Fendt Vario: fuel temperature �C */
  uint8_t ui8_fuelTemperature;
	#endif
  #ifdef USE_ISO_11783
	/** flag to detect, if receive filters for ISO are created */
	bool b_isoFilterCreated;
  /** last time of ISO base_1 msg [100ms] */
  uint8_t ui8_lastIsoBase1;
  /** last time of ISO base_2 msg [100ms] */
  uint8_t ui8_lastIsoBase2;
  /** last time of ISO calendar msg [100ms] */
  uint8_t ui8_lastIsoCalendar;
  /** key switch state */
  IsoAgLib::IsoActiveFlag_t t_keySwitch;
  /** maximum time of tractor power in [min] */
  uint8_t ui8_maxPowerTime;
  /** front hitch draft [-320.000;322.550N], res: 10N/bit, offset: -320.000N  */
  int16_t i16_frontDraft;
  /** rear hitch draft [-320.000;322.550N], res: 10N/bit, offset: -320.000N  */
  int16_t i16_rearDraft;
  /** front nominal lower link force [-100%;100%], res: 0.8%/bit, offset: -100% */
  uint8_t ui8_frontLinkForce;
  /** rear nominal lower link force [-100%;100%], res: 0.8%/bit, offset: -100% */
  uint8_t ui8_rearLinkForce;
  /** front PTO engaged */
  IsoAgLib::IsoActiveFlag_t t_frontPtoEngaged;
  /** rear PTO engaged */
  IsoAgLib::IsoActiveFlag_t t_rearPtoEngaged;
  /** mode of front PTO: true == 1000 n/min; false == 540 n/min */
  IsoAgLib::IsoActiveFlag_t t_frontPto1000;
  /** mode of rear PTO: true == 1000 n/min; false == 540 n/min */
  IsoAgLib::IsoActiveFlag_t t_rearPto1000;
  /** economy mode of front PTO */
  IsoAgLib::IsoActiveFlag_t t_frontPtoEconomy;
  /** economy mode of rear PTO */
  IsoAgLib::IsoActiveFlag_t t_rearPtoEconomy;

  /** last time of maintain power request [ms] */
  uint32_t ui32_lastMaintainPowerRequest;
  /** state whether maintenance of ECU power was requested */
  bool b_maintainEcuPower;
  /** state whether maintenance of actuator power was requested */
  bool b_maintainActuatorPower;
  /** state whether maintenance of power
    * for implement in transport state was requested */
  bool b_maintainPowerForImplInTransport;
  /** state whether maintenance of power
    * for implement in park state was requested */
  bool b_maintainPowerForImplInPark;
  /** state whether maintenance of power
    * for implement in work state was requested */
  bool b_maintainPowerForImplInWork;

	/** raw GPS latitude - Lat_Minute := ( Lat_Raw / 1000000 ) - 210; Lat_Min < 0 --> South */
	int32_t i32_latitudeRaw;
	/** raw GPS longitude - Long_Minute := ( Long_Raw / 1000000 ) - 210; Long_Min < 0 --> West */
	int32_t i32_longitudeRaw;
	/** raw GPS speed (int16_t) - [m/s]??
		\todo check for correct decoding of GPS speed
		*/
	int16_t i16_speedGps;
	/** raw GPS heading ( ?? )
		\todo check for correct decoding of GPS heading
		*/
	int16_t i16_headingGps;
	/** GPS altitude - ?? [cm] ??
		\todo check for correct altitude unit
		*/
	uint32_t ui32_altitude;
	/** GPS receive qualitiy */
	IsoAgLib::IsoGpsRecMode_t t_gpsMode;
  #endif

  /** distance */
  /** real distance as int32_t value (cumulates 16bit overflows) */
  int32_t i32_distReal;
  /** theoretical distance as int32_t value (cumulates 16bit overflows)*/
  int32_t i32_distTheor;
  /** last 16bit real distance to cope with 16bit overflows */
  int16_t i16_lastDistReal;
  /** last 16bit theoretical distance to cope with 16bit overflows */
  int16_t i16_lastDistTheor;

  /** speed */
  /** real speed */
  int16_t i16_speedReal;
  /** theoretical speed */
  int16_t i16_speedTheor;

  /** pto rear */
  int16_t i16_ptoRear;
  /** pto front */
  int16_t i16_ptoFront;
  /** engine speed */
  int16_t i16_engine;

  /** gtp which act as sender of base msg */
  GetyPos_c* pc_gtp;

  /** bit_calendar */
  struct {
    uint16_t year : 12;
    uint16_t month : 4;
    uint16_t day : 6;
    uint16_t hour : 6;
    uint16_t minute : 6;
    uint16_t second : 6;
  } bit_calendar;

	/** bitmask with selection of all base data types to send */
	IsoAgLib::BaseDataGroup_t t_mySendSelection;
  /** GTP of base1 sender */
  GetyPos_c c_sendBase1Gtp;
  /** GTP of base2 sender */
  GetyPos_c c_sendBase2Gtp;
  /** GTP of base3 sender */
  GetyPos_c c_sendBase3Gtp;
  /** GTP of fuel data sender */
  GetyPos_c c_sendFuelGtp;
  /** GTP of calendar sender */
  GetyPos_c c_sendCalendarGtp;
  /** front hitch data */
  uint8_t b_hitchFront;
  /** rear hitch data */
  uint8_t b_hitchRear;
};

#if defined( PRT_INSTANCE_CNT ) && ( PRT_INSTANCE_CNT > 1 )
  /** C-style function, to get access to the unique Base_c singleton instance
    * if more than one CAN BUS is used for IsoAgLib, an index must be given to select the wanted BUS
    */
  Base_c& getBaseInstance( uint8_t rui8_instance = 0 );
#else
  /** C-style function, to get access to the unique Base_c singleton instance */
  Base_c& getBaseInstance( void );
#endif


}
#endif
