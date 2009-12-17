/*
  isoterminalpkg_c.h: object for transformation of CAN uint8_t string
    to and from System data structure

  (C) Copyright 2009 - 2010 by OSB AG and developing partners

  See the repository-log for details on the authors and file-history.
  (Repository information can be found at <http://isoaglib.com/download>)

  Use, modification and distribution are subject to the GNU General
  Public License with exceptions for ISOAgLib. (See accompanying
  file LICENSE.txt or copy at <http://isoaglib.com/download/license>)
*/
#ifndef ISO_TERMINAL_PKG_H
#define ISO_TERMINAL_PKG_H

/* *************************************** */
/* ********** include headers ************ */
/* *************************************** */
#include <IsoAgLib/typedef.h>
#include <IsoAgLib/comm/Part3_DataLink/impl/canpkgext_c.h>
#include <IsoAgLib/comm/Part5_NetworkManagement/impl/isoname_c.h>

// Begin Namespace __IsoAgLib
namespace __IsoAgLib {

/**
  IsoTerminalPkg_c
  @author Dipl.-Inform. Achim Spangler
*/

class IsoTerminalPkg_c : public CanPkgExt_c  {
public:
  /** default constructor */
  IsoTerminalPkg_c (int ai_singletonVecKey = 0) : CanPkgExt_c (ai_singletonVecKey) {}
  /** default destructor */
  ~IsoTerminalPkg_c() {}

  /* ************************** */
  /* ***retreiving of values*** */
  /* ************************** */

  /* *********************** */
  /* ***setting of values*** */
  /* *********************** */

  /**
    overloaded virtual function to translate the string data into flag values;
    needed for assigning informations from another CanPkg_c or CANPkgExt
    @see CanPkg_c::operator=
    @see CanPkgExt_c::operator=
  */
  virtual void string2Flags();
protected: // protected methods

  /**
    overloaded virtual function to translate flag values to data string;
    needed for sending informations from this object via CanIo_c on CAN BUS,
    because CanIo_c doesn't know anything about the data format of this type of msg
    so that it can only use an unformated data string from CANPkg
    @see CanPkg_c::getData
    @see CanPkgExt_c::getData
  */
  virtual void flags2String();
};

}
#endif
