/***************************************************************************
                          isimplemanagesetpointremote_c.h  - managing of remote
                                                   process data object
                             -------------------
    begin                : Fri Apr 07 2000
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
#ifndef ISIMPLE_MANAGE_SETPOINT_REMOTE_H
#define ISIMPLE_MANAGE_SETPOINT_REMOTE_H

/* *************************************** */
/* ********** include headers ************ */
/* *************************************** */
#include "impl/simplemanagesetpointremote_c.h"

// Begin Namespace IsoAgLib
namespace IsoAgLib {
// ***************************************************************************************
// *************************** iSimpleManageSetpointRemote_c ***************************
// ***************************************************************************************

/**
  simple management of a Setpoint value
  without flexible setpoints.
  */
class iSimpleManageSetpointRemote_c : public __IsoAgLib::SimpleManageSetpointRemote_c
{
 public:
  #ifdef SIMPLE_SETPOINT_WITH_PERCENT
  /**
    deliver the actual percent setpoint
    @param rb_sendRequest true -> send request for actual value
    @return percent setpoint value
  */
  uint8_t setpointPercentVal(bool rb_sendRequest = false)
    { return SimpleManageSetpointRemote_c::setpointPercentVal( rb_sendRequest);};
  /**
    send a setpoint cmd with given percent setpoint
    @param rb_val commanded setpoint percent value
    @param rb_onlyStoreOnResponse true -> the given value is only stored if response arrives
  */
  void setSetpointPercentVal(uint8_t rb_val, bool rb_onlyStoreOnResponse = true)
    { return SimpleManageSetpointRemote_c::setSetpointPercentVal( rb_val, rb_onlyStoreOnResponse);};
  #endif
  /**
    deliver the actual master setpoint
    @param rb_sendRequest true -> send request for actual value
    @return setpoint value as long
  */
  int32_t setpointMasterVal(bool rb_sendRequest = false)
    { return SimpleManageSetpointRemote_c::setpointMasterVal( rb_sendRequest);};
  /**
    send a setpoint cmd with given exact setpoint
    @param ri32_val commanded setpoint value as long
    @param rb_onlyStoreOnResponse true -> the given value is only stored if response arrives
  */
  void setSetpointMasterVal(int32_t ri32_val, bool rb_onlyStoreOnResponse = true)
    { return SimpleManageSetpointRemote_c::setSetpointMasterVal( ri32_val, rb_onlyStoreOnResponse);};
  #ifdef USE_FLOAT_DATA_TYPE
  /**
    deliver the actual master setpoint
    @param rb_sendRequest true -> send request for actual value
    @return setpoint value as float
  */
  float setpointMasterValFloat(bool rb_sendRequest = false)
    { return SimpleManageSetpointRemote_c::setpointMasterValFloat( rb_sendRequest);};
  /**
    send a setpoint cmd with given exact setpoint
    @param rf_val commanded setpoint value as float
    @param rb_onlyStoreOnResponse true -> the given value is only stored if response arrives
  */
  void setSetpointMasterVal(float rf_val, bool rb_onlyStoreOnResponse = true)
    { return SimpleManageSetpointRemote_c::setSetpointMasterVal( rf_val, rb_onlyStoreOnResponse);};
  #endif
 private:
  friend class iProcDataRemote_c;
  friend class iProcDataRemoteSimpleMeasure_c;
  friend class iProcDataRemoteSimpleSetpoint_c;
  friend class iProcDataRemoteSimpleSetpointSimpleMeasure_c;
};

}
#endif
