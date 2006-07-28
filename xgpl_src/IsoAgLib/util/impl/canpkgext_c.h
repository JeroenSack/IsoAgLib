/***************************************************************************
                          canpkgext_c.h - header for extended CANPkg_c object,
                                          which calls data flag converting
                                          functions on assign operations
                             -------------------
    begin                : Tue Jan 11 2000
    copyright            : (C) 2000 - 2004 by Dipl.-Inform. Achim Spangler
    email                : a.spangler@osb-ag:de
    type                 : Header
    $LastChangedDate$
    $LastChangedRevision$
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
 * Copyright (C) 1999 - 2004 Dipl.-Inform. Achim Spangler                  *
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

#ifndef CAN_PKG_EXT_H
#define CAN_PKG_EXT_H

#include "canpkg_c.h"
#include <IsoAgLib/util/impl/util_funcs.h>

// Begin Namespace __IsoAgLib
namespace __IsoAgLib {

class DevKey_c;
class MonitorItem_c;

/** values which indicates the state of an address */
typedef enum { Valid = 0, OnlyNetworkMgmt = 1, Invalid = 3 } MessageState_t;
/** structure which will be filled when an address is resolved */
typedef struct
{ // IMPORTANT:
  // the DevKey_c instance should be handled as if it would be a fixed
  // _part_ of the struct --> the constructor allocates an instance, the destructur frees it
  //                          and all other operations just operate on the allocated instance.
  DevKey_c*         p_devKey;
  // IMPORTANT:
  // in contrast to DevKey_c, the MonitorItem_c _POINTER_ is always set to NULL or to an instance, that
  // is located somewhere else (thus do NEVER NEVER NEVER call new or delete for this entry!!!!!!!!)
  const MonitorItem_c*  pc_monitorItem;
  //can be source or destination address
  uint8_t address;
} AddressResolveResults;

typedef enum
{
  local  = 0,
  remote = 1
} Scope;

/** extended version of CANPkg_c which overwrites the
    assign and getData functions
    with call for data flag converting functions
  *@author Dipl.-Inform. Achim Spangler
  */

class CANPkgExt_c : public CANPkg_c  {
protected:
public:
  /** default constructor, which has nothing to do */
  CANPkgExt_c( int ri_singletonVecKey = 0 );
  /** virtual default destructor, which has nothing to do */
  virtual ~CANPkgExt_c();
  /**
    ==> REACTIVATE if some NON-STATIC member vars will be added!
    ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
    assign operator to insert informations from one CANPkg_c into another
    @see __IsoAgLib::FilterBox_c::operator>>
    @see CANPkgExt_c::operator=
    @see CANPkgExt_c::getData
    @param rrefc_right reference to the source CANPkg_c on the right
    @return reference to the source CANPkg_c to enable assign chains like
        "pkg1 = pkg2 = pkg3 = pkg4;"
  virtual const CANPkg_c& operator=(const CANPkg_c& rrefc_right);
  */

  /**
    simply deliver a uint8_t from a specific position with operator[]
    @param rb_pos position of dellivered uint8_t [0..7]
    @return uint8_t balue in CAN data string at pos rb_pos
  */
  uint8_t operator[](uint8_t rui8_pos) const {return pb_data[rui8_pos];};
  /**
    set an uint8_t value at specified position in string
    @param rui8_devClassInst position [0..7]
    @param rui8_val uint8_t value to set
  */
  void setUint8Data( uint8_t rui8_devClassInst, uint8_t rui8_val) { pb_data[rui8_devClassInst] = rui8_val;};
  /**
    set an uint16_t value at specified position in string
    @param rui8_devClassInst position [0..6]
    @param rui16_val uint16_t value to set
  */
  void setUint16Data( uint8_t rui8_pos, uint16_t rui16_val)
    {numberRef2LittleEndianString( rui16_val, (pb_data+rui8_pos) );};
    //{ pb_data[rui8_pos] = (rui16_val & 0xFF); pb_data[rui8_pos+1] = ( rui16_val >> 8 );};
  /**
    set an int16_t value at specified position in string
    @param rui8_devClassInst position [0..6]
    @param ri16_val int16_t value to set
  */
  void setInt16Data( uint8_t rui8_pos, int16_t ri16_val)
    {numberRef2LittleEndianString( ri16_val, (pb_data+rui8_pos) );};
    //{ pb_data[rui8_pos] = (ri16_val & 0xFF); pb_data[rui8_pos+1] = ( ri16_val >> 8 );};
  /**
    set an uint32_t value at specified position in string
    @param rui8_devClassInst position [0..4]
    @param rui32_val uint32_t value to set
  */
  void setUint32Data( uint8_t rui8_pos, uint32_t rui32_val)
    {numberRef2LittleEndianString( rui32_val, (pb_data+rui8_pos) );};
  //{ setUint16Data( rui8_pos,     uint16_t(rui32_val & 0xFFFF) );
  //    setUint16Data( (rui8_pos+2), uint16_t( rui32_val >> 16 ) );};
  /**
    set an int32_t value at specified position in string
    @param rui8_devClassInst position [0..4]
    @param ri32_val int32_t value to set
  */
  void setInt32Data( uint8_t rui8_pos, int32_t ri32_val)
    {numberRef2LittleEndianString( ri32_val, (pb_data+rui8_pos) );};
  //{ setInt16Data( rui8_pos,     int16_t(ri32_val & 0xFFFF) );
  //  setInt16Data( (rui8_pos+2), int16_t( ri32_val >> 16 ) );};

  /**
    simply deliver a uint8_t from a specific position with
    @param rb_pos position of dellivered uint8_t [0..7]
    @return uint8_t balue in CAN data string at pos rb_pos
  */
  uint8_t getUint8Data(uint8_t rui8_pos) const {return pb_data[rui8_pos];};
  /**
    simply deliver a uint16_t from a specific starting position with
    @param rb_pos position of dellivered uint16_t [0..6]
    @return uint16_t balue in CAN data string at pos (rb_pos, rb_pos+1) read Low/High order
  */
  uint16_t getUint16Data(uint8_t rui8_pos) const { return convertLittleEndianStringUi16(pb_data+rui8_pos);};
  //{return (uint16_t(pb_data[rb_pos]) | (uint16_t(pb_data[rb_pos+1])<<8));};
  /**
    simply deliver a int16_t from a specific starting position with
    @param rb_pos position of dellivered int16_t [0..6]
    @return int16_t balue in CAN data string at pos (rb_pos, rb_pos+1) read Low/High order
  */
  int16_t getInt16Data(uint8_t rui8_pos) const { return convertLittleEndianStringI16(pb_data+rui8_pos);};
  // {return int16_t( uint16_t(pb_data[rb_pos]) | ( uint16_t(pb_data[rb_pos+1]) << 8 ) );};
  /**
    simply deliver a uint32_t from a specific starting position with
    @param rb_pos position of dellivered uint32_t [0..4]
    @return uint32_t balue in CAN data string at pos (rb_pos, rb_pos+1) read Low/High order
  */
  uint32_t getUint32Data(uint8_t rui8_pos) const { return convertLittleEndianStringUi32(pb_data+rui8_pos);};
  // {return (uint32_t(getUint16Data(rb_pos)) | (uint32_t(getUint16Data(rb_pos+2))<<16));};
  /**
    simply deliver a int32_t from a specific starting position with
    @param rb_pos position of dellivered int32_t [0..4]
    @return int32_t balue in CAN data string at pos (rb_pos, rb_pos+1) read Low/High order
  */
  int32_t getInt32Data(uint8_t rui8_pos) const { return convertLittleEndianStringI32(pb_data+rui8_pos);};
  // {return int32_t( uint32_t(getUint16Data(rb_pos)) | ( uint32_t(getUint16Data(rb_pos+2)) << 16 ) );};

  /**
    put data into given reference to BIOS related data structure with data, len
    @param reft_ident     reference where the ident is placed for send
    @param refui8_identType reference to the ident type val: 0==std, 1==ext
    @param refb_dlcTarget reference to the DLC field of the target
    @param pb_dataTarget pointer to the data string of the target
  */
  virtual void getData(uint32_t& reft_ident, uint8_t& refui8_identType,
                       uint8_t& refb_dlcTarget, uint8_t* pb_dataTarget);

  virtual bool isNetworkMgmt() const { return false; } ;
  #ifdef USE_DIN_9684
    /**
    deliver sender nr
    @return SEND code of base msg (bit 8-11 in identifier)
  */
  uint8_t dinSa() const {return (ident(0) & 0xF);};
  #endif

  #ifdef USE_ISO_11783
  // begin of block with ISO 11783 CAN formating functions
  /**
    get the value of the ISO11783 ident field SA
    @return source adress
  */
  uint8_t isoSa() const;
  /**
    get the value of the ISO11783 ident field PGN
    @return parameter group number
  */
  uint32_t isoPgn() const {return ( ( ( (uint32_t)ident() >> 8) & 0x1FF00 ) | isoPs() );};
  /**
    get the value of the ISO11783 ident field DP
    @return data page
  */
  uint8_t isoDp() const {return (ident(3) & 0x1);};
  /**
    get the value of the ISO11783 ident field PF
    @return PDU Format
  */
  uint8_t isoPf() const {return ident(2);};
  /**
    get the value of the ISO11783 ident field PS
    @return PDU Specific
  */
  uint8_t isoPs() const;
  /**
    get the value of the ISO11783 ident field PRI
    @return priority
  */
  uint8_t isoPri() const {return (ident(3) >> 2);};

  /**
    set the value of the ISO11783 ident field SA
    @return source adress
  */
  void setIsoSa(uint8_t rui8_val);
  /**
    set the value of the ISO11783 ident field PGN
    @return parameter group number
  */
  void setIsoPgn(uint32_t rui32_val);
  /**
    set the value of the ISO11783 ident field DP
    @return data page
  */
  void setIsoDp(uint8_t rui8_val){setIdent( ((ident(3)& 0x1E) | (rui8_val & 1)), 3, Ident_c::ExtendedIdent);};
  /**
    set the value of the ISO11783 ident field PF
    @return PDU Format
  */
  void setIsoPf(uint8_t rui8_val){setIdent(rui8_val, 2, Ident_c::ExtendedIdent); };
  /**
    set the value of the ISO11783 ident field PS
    @return PDU Specific
  */
  void setIsoPs(uint8_t rui8_val);
  /**
    set the value of the ISO11783 ident field PRI
    @return priority
  */
  void setIsoPri(uint8_t rui8_val){setIdent( ((ident(3)&1) | (rui8_val << 2)), 3, Ident_c::ExtendedIdent);}

  void setExtCanPkg(uint8_t pri, uint8_t dp, uint8_t pf, uint8_t ps, uint8_t sa, uint8_t len) {
    CANPkg_c::setIdentType(Ident_c::ExtendedIdent);
    setIsoPri(pri);
    setIsoDp(dp);
    setIsoPf(pf);
    setIsoPs(ps);
    setIsoSa(sa);
    setLen (len);
    b_runFlag2String = false;
  }

  void setExtCanPkg3(uint8_t pri, uint8_t dp, uint8_t pf, uint8_t ps, uint8_t sa, uint8_t d0, uint8_t d1, uint8_t d2) {
    CANPkg_c::setIdentType(Ident_c::ExtendedIdent);
    setIsoPri(pri);
    setIsoDp(dp);
    setIsoPf(pf);
    setIsoPs(ps);
    setIsoSa(sa);
    setUint8Data (0, d0);
    setUint8Data (1, d1);
    setUint8Data (2, d2);
    setLen (3);
    b_runFlag2String = false;
  }

  void setExtCanPkg8(uint8_t pri, uint8_t dp, uint8_t pf, uint8_t ps, uint8_t sa, uint8_t d0, uint8_t d1, uint8_t d2, uint8_t d3, uint8_t d4, uint8_t d5, uint8_t d6, uint8_t d7) {
    CANPkg_c::setIdentType(Ident_c::ExtendedIdent);
    setIsoPri(pri);
    setIsoDp(dp);
    setIsoPf(pf);
    setIsoPs(ps);
    setIsoSa(sa);
    setUint8Data (0, d0);
    setUint8Data (1, d1);
    setUint8Data (2, d2);
    setUint8Data (3, d3);
    setUint8Data (4, d4);
    setUint8Data (5, d5);
    setUint8Data (6, d6);
    setUint8Data (7, d7);
    setLen (8);
    b_runFlag2String = false;
  }
  /** check if source and destination address are valid
      @see     FilterBox_c::processMsg()
      @pre     we want to process a message
      @return  Valid -> both addresses are valid
               Invalid -> one or both addresses are invalid
               OnlyNetworkMgmt -> one or both addresses are only useable for network management
    */
  MessageState_t resolveReceivingInformation();

  /** check if source and destination address are valid
      @see     CANPkgExt_c::operator<<
      @pre     we want to send a message
      @return  Valid -> both addresses are valid
               Invalid -> one or both addresses are invalid
               OnlyNetworkMgmt -> one or both addresses are only useable for network management
    */
  bool resolveSendingInformation();
  /** set the monitoritem for resolve SA
      @param pc_monitorItem  needed monitoritem
    */
  void setMonitorItemForSA( const MonitorItem_c* pc_monitorItem );
  /** set the devKey for resolve SA
      @param p_devKey        needed devKey
    */
  void setDevKeyForSA( const DevKey_c& p_devKey );
  /** set the monitoritem for resolve SA
      @param pc_monitorItem  needed monitoritem
    */
  void setMonitorItemForDA( const MonitorItem_c* pc_monitorItem );
  /** set the devKey for resolve SA
      @param p_devKey        needed devKey
    */
  void setDevKeyForDA( const DevKey_c& p_devKey );


  #ifdef ALLOW_PROPRIETARY_MESSAGES_ON_STANDARD_PROTOCOL_CHANNEL
    /** this virtual function can be used to detect CAnCustomer_c derived CAN message handlers, which
        want to send/receive proprietary messages on a CANIO_c instance, which is used to transport
        standardized protocol ISO 11783 or DIN 9684.
        Any proprietary derived CAN message handler should overload this function to return true in this function.
    */
    virtual bool isProprietaryMessageOnStandardizedCan() const { return false;};
  #endif // end of ALLOW_PROPRIETARY_MESSAGES_ON_STANDARD_PROTOCOL_CHANNEL
  // end of block with ISO 11783 specific functions
  #endif

  /**
    abstract function to transform the string data into flag values
    => derived class must implement suitable data conversion function

    needed for assigning informations from another CANPkg_c or CANPkgExt
    @see CANPkgExt_c::operator=
  */
  virtual void string2Flags();

private:
// Private methods
  #ifdef USE_ISO_11783
  /** report if the combination of address and scope is valid in context of message processing
      @return  true -> address, scope combination is valid
    */
  MessageState_t address2IdentRemoteSa();
  /** report if the combination of address and scope is valid in context of message processing
      @return  true -> address, scope combination is valid
    */
  MessageState_t address2IdentLocalDa();
  /** set address in context of sending a message
      @param  addressResolveResults  source or destination address
      @param  scope                  local or remote
      @return  true -> monitoritem_c, devKey_c is a valid combination
    */
  MessageState_t setAddress(AddressResolveResults& addressResolveResults, Scope scope);
  /** resolve a given monitoritem and get address if possible
      @param  addressResolveResults  address to resolve
      @return true -> monitoritem could be resolved
              false -> nothing more to be done
    */
  bool resolveMonitorItem( AddressResolveResults& addressResolveResults );
  #endif

  /**
    abstract transform flag values to data string
    => derived class must implement suitable data converting function

    needed for sending informations from this object via CANIO_c on CAN BUS,
    because CANIO_c doesn't know anything about the data format of this type of msg
    so that it can only use an unformated data string from CANPkg
    @see CANPkgExt_c::getData
    @see __IsoAgLib::CANIO_c::operator<<
  */
  virtual void flags2String();

  /** flag to decide if flags2String has to be executed during send.
      Normally this is needed, but after each call of setExtCanPkg?? all bytes of the stream are already setup.
    */
  static bool b_runFlag2String;

  /** variable which holds the results for a resolved source address */
  AddressResolveResults addrResolveResSA;
  /** variable which holds the results for a resolved destination address */
  AddressResolveResults addrResolveResDA;
};

}
#endif
