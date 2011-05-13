/*
  ieeprom_io.h: header for iEEPROM_IO_c object for communication with
    EEPROM

  (C) Copyright 2009 - 2010 by OSB AG and developing partners

  See the repository-log for details on the authors and file-history.
  (Repository information can be found at <http://isoaglib.com/download>)

  Use, modification and distribution are subject to the GNU General
  Public License with exceptions for ISOAgLib. (See accompanying
  file LICENSE.txt or copy at <http://isoaglib.com/download/license>)
*/
#ifndef IEEPROM_IO_H
#define IEEPROM_IO_H

#include "impl/eepromio_c.h"
#include <IsoAgLib/comm/Part5_NetworkManagement//iisoname_c.h>
#include <string>

//using STL_NAMESPACE::string;

// Begin Namespace IsoAgLib
namespace IsoAgLib {
/**
  object for communication with the EEPROM,
  stream read/write operators for all basic types;
  avoid rewriting same values to EEPROM;
  manages operations cross segment boundaries
  *@author Dipl.-Inform. Achim Spangler
*/
class iEepromIo_c : private __IsoAgLib::EepromIo_c {
public:
  /** destructor has nothing to destruct */
  ~iEepromIo_c() {};

  // ++++++++++++++++++++++++++++++++++++
  // ++++ EEPROM managing operations ++++
  // ++++++++++++++++++++++++++++++++++++

  /**
    deliver the size of the whole EEPROM memory in bytes;
    uses BIOS function (which delivers KB -> mult with 1024)
    @return size of EEPROM in BYTE
  */
  static uint16_t eepromSize(){return EepromIo_c::eepromSize();};

  /**
    set the write position in EEPROM (in Byte); answer if possible
    if aui16_adress exceeds EEPROM memory ignore setting and set Err_c::range

    possible errors:
        * Err_c::range aui16_adress outer the limits of EEPROM memory

    @param aui16_adress position of write mark [uint8_t]
    @return true -> setting of write mark without errors
  */
  bool setp(uint16_t aui16_adress) {return EepromIo_c::setp(aui16_adress);};

  /**
    set the read position in EEPROM (in Byte); answer if possible
    if aui16_adress exceeds EEPROM memory ignore setting and set Err_c::range

    possible errors:
        * Err_c::range aui16_adress outer the limits of EEPROM memory

    @param aui16_adress position of read mark [uint8_t]
    @return true -> setting of read mark without errors
  */
  bool setg(uint16_t aui16_adress) {return EepromIo_c::setg(aui16_adress);};

  /**
    get the write position in EEPROM (in Byte)
    @return position of write mark [uint8_t]
  */
  uint16_t tellp(){return EepromIo_c::tellp();};

  /**
    get the read position in EEPROM (in Byte)
    @return position of read mark [uint8_t]
  */
  uint16_t tellg(){return EepromIo_c::tellg();};

  /**
    check if write position is at end of EEPROM
    (parameter specifies lookahead (normally length of operation - 1 is passed to check if a block of data fits into)

    possible errors:
        * range if (ab_setState == true) and (current read position + lookahead) is out of EEPROM range

    @param aui16_lookahead optional uint8_t lookahead offset (default 0 -> only current write mark position tested)
    @return false -> (current position + lookahead) is a valid EEPROM address. (true -> out of EEPROM range)
  */
  bool eofp(uint16_t aui16_lookahead = 0, bool ab_setState = false)
   {return EepromIo_c::eofp(aui16_lookahead, ab_setState);};

  /**
    check if read position is at end of EEPROM
    (parameter specifies lookahead (normally length of operation - 1 is passed to check if a block of data fits into)

    possible errors:
        * range if (ab_setState == true) and (current read position + lookahead) is out of EEPROM range

    @param aui16_lookahead optional uint8_t lookahead offset (default 0 -> only current read mark position tested)
    @return false -> (current position + lookahead) is a valid EEPROM address. (true -> out of EEPROM range)
  */
  bool eofg(uint16_t aui16_lookahead = 0, bool ab_setState = false)
    {return EepromIo_c::eofg(aui16_lookahead, ab_setState);};

  /* *************************************** */
  /* *** EEPROM data operation functions *** */
  /* ************** writing **************** */
  /* *************************************** */


  /**
    write a text string value to EEPROM from actual write position on (tellp() )

    possible errors:
        * Err_c::range writing position exceeds end of EEPROM
        * Err_c::hwBusy the EEPROM was busy with another action
        * Err_c::eepromSegment low level writing caused segment error

    @see iEepromIo_c::tellp
    @see iEepromIo_c::setp
    @param arc_val string to write into EEPROM
    @return reference to this iEepromIo_c instance (for chains like "eeprom << val1 << val2 << ... << val_n;")
  */
  iEepromIo_c& operator<<(STL_NAMESPACE::string& arc_val)
    {return static_cast<iEepromIo_c&>(EepromIo_c::operator<<(arc_val));};

  /**
    write a value to EEPROM from actual write position on (tellp() )
    by use of template mechanism the correct write implementation is generted
    for the given parameter type

    possible errors:
        * Err_c::range writing position exceeds end of EEPROM
        * Err_c::hwBusy the EEPROM was busy with another action
        * Err_c::eepromSegment low level writing caused segment error

    @see iEepromIo_c::tellp
    @see iEepromIo_c::setp
    @param rTemplateVal value of any type to write into EEPROM from actual write position on
    @return reference to this iEepromIo_c instance (for chains like "eeprom << val1 << val2 << ... << val_n;")
  */
  template<class T>
  iEepromIo_c& operator<<(const T& rTemplateVal)
    {return static_cast<iEepromIo_c&>(EepromIo_c::operator<<(rTemplateVal));}

  /**
    write a uint8_t string value to EEPROM from actual write position on (tellp() )

    possible errors:
        * Err_c::range writing position exceeds end of EEPROM
        * Err_c::busy the EEPROM was busy with another action
        * Err_c::eepromSegment low level writing caused segment error

    @see EepromIo_c::tellp
    @see EepromIo_c::setp
    @param apb_string string to write into EEPROM
    @param aui16_number length of the string to write
    @return reference to this EepromIo_c instance (for chains like "eeprom << val1 << val2 << ... << val_n;")
  */
  inline iEepromIo_c& writeString(const uint8_t *const apb_string, uint16_t aui16_number)
    {return static_cast<iEepromIo_c&>(EepromIo_c::writeString(apb_string, aui16_number));};

  /* *************************************** */
  /* *** EEPROM data operation functions *** */
  /* ************** reading **************** */
  /* *************************************** */
  /**
    read a value to EEPROM from actual write position on (tellg() )
    by use of template mechanism the correct read implementation is generted
    for the given parameter type

    possible errors:
        * Err_c::range reading position exceeds end of EEPROM
        * Err_c::hwBusy the EEPROM was busy with another action
        * Err_c::eepromSegment low level reading caused segment error

    @see iEepromIo_c::tellg
    @see iEepromIo_c::setg
    @param rTemplateVal EERPOM data is read into rTemplateVal from actual read position on
    @return reference to this iEepromIo_c instance (for chains like "eeprom >> val1 >> val2 >> ... >> val_n;")
  */
  template<class T>
  iEepromIo_c& operator>>(T& rTemplateVal)
    {return static_cast<iEepromIo_c&>(EepromIo_c::operator>>(rTemplateVal));}

  /**
    read operator for strings with given length; uses BIOS function

    possible errors:
        * Err_c::range reading position exceeds end of EEPROM
        * Err_c::hwBusy the EEPROM was busy with another reading action
        * Err_c::eepromSegment low level reading caused segment error

    @see iEepromIo_c::tellg
    @see iEepromIo_c::setg
    @param apb_string pointer to uint8_t string, which should be read from actual EEPROM read position on
    @param aui16_number number of uint8_t to read into string
    @return true -> read with success
  */
  bool readString(uint8_t *const apb_string, uint16_t aui16_number)
    {return EepromIo_c::readString(apb_string, aui16_number);};
private:
  /** allow getIeepromInstance() access to shielded base class.
      otherwise __IsoAgLib::getEepromInstance() wouldn't be accepted by compiler
    */
  friend iEepromIo_c& getIeepromInstance( void );
  friend iEepromIo_c& operator<<(iEepromIo_c& rc_stream, const iIsoName_c& rc_data );
  friend iEepromIo_c& operator>>(iEepromIo_c& rc_stream, iIsoName_c& rc_data );
};

/** C-style function, to get access to the unique EepromIo_c singleton instance */
inline iEepromIo_c& getIeepromInstance( void ) { return static_cast<iEepromIo_c&>(__IsoAgLib::getEepromInstance());};
inline iEepromIo_c& operator<<(iEepromIo_c& rc_stream, const iIsoName_c& rc_data )
  { return static_cast<iEepromIo_c&>(operator<<(static_cast<__IsoAgLib::EepromIo_c&>(rc_stream), rc_data ) );};
inline iEepromIo_c& operator>>(iEepromIo_c& rc_stream, iIsoName_c& rc_data )
  { return static_cast<iEepromIo_c&>(operator>>(static_cast<__IsoAgLib::EepromIo_c&>(rc_stream), rc_data ) );};


/** this typedef is only for some time to provide backward compatibility at API level */
typedef iEepromIo_c iEEPROMIO_c;

} // end of IsoAgLibInterafce namespace
#endif