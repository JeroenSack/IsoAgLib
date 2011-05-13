/*
  actoro_c.h:
    header for the actor output management object

  (C) Copyright 2009 - 2010 by OSB AG and developing partners

  See the repository-log for details on the authors and file-history.
  (Repository information can be found at <http://isoaglib.com/download>)

  Use, modification and distribution are subject to the GNU General
  Public License with exceptions for ISOAgLib. (See accompanying
  file LICENSE.txt or copy at <http://isoaglib.com/download/license>)
*/
#ifndef ACTOR_O_H
#define ACTOR_O_H

/* *************************************** */
/* ********** include headers ************ */
/* *************************************** */
#include <IsoAgLib/util/impl/singleton.h>

#include "digitalo_c.h"
#include "actor_c.h"


// Begin Namespace __IsoAgLib
namespace __IsoAgLib {
/**
  Hardware dependent object for hardware independent getting of actor data;
  manages with help of object ActorBase_c and derived classes
  the output from different data sources
  @see Digital_O
  @see ActorBase
  @short Hardware dependent object for hardware independent controling of actor outputs.
  @author Dipl.-Inform. Achim Spangler
  */
class ActorO_c : public SingletonDerivedCont1<ActorO_c,ClientBase,DigitalO_c,uint8_t> {
public:
  /** destructor for the actor output manager object */
  ~ActorO_c();
  /**
    initialisation for the actor output management which sets the allowed number
    ranges for digital ouptut channels.
    As the constructor is often not called for static instances, the init function
    is used by the Singleton base class, to set the unique instance in a well defined
    initial state

    possible errors:
        * Err_c::range given limits are not possible
    @param ab_digitalFirst smallest allowed digital output channel number (DIGITAL_OUTPUT_MIN)
    @param ab_digitalLast greatest allowed digital output channel number (DIGITAL_OUTPUT_MAX)
    @see masterHeader
  */
  void init(uint8_t ab_digitalFirst = DIGITAL_OUTPUT_MIN, uint8_t ab_digitalLast = DIGITAL_OUTPUT_MAX);
  /** every subsystem of IsoAgLib has explicit function for controlled shutdown
    */
  void close( void ){};
  /**
    set the limits for digital output channels (first setting can be done by constructor parameters)

    possible errors:
        * Err_c::range given limits are not possible
    @param ab_digitalFirst number of the smallest allowed digital output channel
    @param ab_digitalLast number of the greatest allowed digital output channel
  */
  void setDigitalLimits(uint8_t ab_digitalFirst, uint8_t ab_digitalLast);
  /** handler function for access to undefined client.
    * the base Singleton calls this function, if it detects an error
    */
  static void registerAccessFlt( void );

  /**
    check if digital output object to given ab_channel exist
    @see ActorO_c::createDigital
    @see ActorO_c::deleteDigital
    @param ab_channel number of the tested output channel
    @return true -> searched output object exist
  */
  bool existDigital(uint8_t ab_channel) { return existC1( ab_channel );};
  /**
    deliver reference to requested digital channel object to access this actor output;
    IMPORTANT: an digital output channel object with the wanted number must exist
               -> creating with createDigital and checking with existDigital
               (throw exception if exceptions are activated on compile time)

    possible errors:
        * Err_c::elNonexistant wanted digital output with given channel no does not exist
    @see ActorO_c::createDigital
    @see ActorO_c::existDigital
    @see DigitalO_c::Digital_O
    @param ab_channel channel of the digital sensor output
    @return reference to the wanted digital actor output channel
    @exception containerElementNonexistant
  */
  DigitalO_c& digital(uint8_t ab_channel) { return getC1( ab_channel );};
private:
//private methods
  friend class DigitalO_c;
  friend class SingletonDerived<ActorO_c,ClientBase>;
    /** private constructor which prevents direct instantiation in user application
    * NEVER define instance of ActorO_c within application
    */
  ActorO_c( void ) { };
	void singletonInit() {init();};

  /** register pointer to a new client
    * this function is called within construction of new client instance
    */
  bool registerClient( DigitalO_c* pc_client) { return registerC1( pc_client );};
  /** unregister a client instance, which is destructed at the moment
    * this function is called within the destructor of the client instance
    */
  void unregisterClient( DigitalO_c* pc_client) { unregisterC1( pc_client );};
  /**
    deliver min channel no limit
    @return min channel no limit
  */
  uint8_t min_digitalLimit() const {return b_min_digitalLimit;};
  /**
    deliver max channel no limit
    @return max channel no limit
  */
  uint8_t maxDigitalLimit() const {return b_maxDigitalLimit;};
  /**
    set min channel no limit
    @param ab_minLimit min channel no limit
  */
  void setMinDigitalLimit(uint8_t ab_minLimit) {b_min_digitalLimit = ab_minLimit;};
  /**
    set max channel no limit
    @param ab_maxLimit max channel no limit
  */
  void setMaxDigitalLimit(uint8_t ab_maxLimit) {b_maxDigitalLimit = ab_maxLimit;};

private: // Private attributes
  /** min digital channel limit */
  uint8_t b_min_digitalLimit;
  /** max digital channel limit */
  uint8_t b_maxDigitalLimit;
};
/** C-style function, to get access to the unique ActorO_c singleton instance */
ActorO_c& getActorInstance( void );

}
#endif
