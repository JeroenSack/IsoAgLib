/***************************************************************************
                          idinitem_c.h - element class for monitor
                                           lists of members

                             -------------------
    begin                : Fri Apr 07 2000
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
#ifndef IMEMBER_ITEM_H
#define IMEMBER_ITEM_H

/* *************************************** */
/* ********** include headers ************ */
/* *************************************** */
#include "impl/dinitem_c.h"
#include <IsoAgLib/util/igetypos_c.h>

// Begin Namespace IsoAgLib
namespace IsoAgLib {

/**
  A DINItem_c stores and manages all status and identity informations
  of a DIN 9684 member. In addition to the name (up to 7 character) the lasted
  time since the last alive msg can be requested. Instances for local
  identities can manage the address claim procedure and send of alive triggered
  by periodic calls of timeEvent.
  @author Dipl.-Inform. Achim Spangler
  @short element class for monitor lists of members
  @see iServiceItem
*/
class iDINItem_c : private __IsoAgLib::DINItem_c {
private:
  friend class iIdentItem_c;
  friend class iSystemMgmt_c;
  friend class iDINMonitor_c;
public:
  // Public methods
  /**
    deliver the DEV_KEY code of this item
    @return DEV_KEY code
  */
  const iDevKey_c& devKey()const{return static_cast<const iDevKey_c&>(DINItem_c::devKey());};
  /**
    deliver the DEVCLASS code alone (derived from devKey)
    @return DEVCLASS code
  */
  uint8_t devClass()const{return DINItem_c::devClass();};
  /**
    deliver the device class inst code alone (derived from devKey)
    @return device class inst code
  */
  uint8_t devClassInst()const{return DINItem_c::devClassInst();};
  /**
    deliver the number/adress of this item
    @return number
  */
  uint8_t nr()const{return DINItem_c::nr();};
  /**
    deliver name
    @return pointer to the name uint8_t string (7byte)
  */
  const uint8_t* name() const {return DINItem_c::name();};
  /**
    check if the name field is empty (no name received)
    @return true -> no name received
  */
  bool isEmptyName() const{return DINItem_c::isEmptyName();};

  /**
    deliver name as pure ASCII string
    @param pc_name string where ASCII string is inserted
    @param rui8_maxLen max length for name
  */
  void getPureAsciiName(int8_t *pc_asciiName, uint8_t rui8_maxLen)
  {DINItem_c::getPureAsciiName(pc_asciiName, rui8_maxLen);};

  /**
    set name
    @param rpb_name pointer to 7 uint8_t string, which is used as name
  */
  void setName(const uint8_t* rpb_name){DINItem_c::setName(rpb_name);};
  /**
    send the name of this monitor item

    possible errors:
      * Err_c::lbsSysNoActiveLocalDinMember this item hasn't claimed address
            --> sending is not allowed
      * dependant error in CANIO_c during send
  */
  void sendName(){DINItem_c::sendName();};

  /**
    calculates time between now and last set of i32_lastTime;
    if called with time parameter, the difference to this is calculated,
    otherwise the system time is retreived and used
    @param ri32_time optional time to use for calculating the difference time to last update (default use actual System_c::getTime() )
    @return lasted time between last update and the compare time [msec.]
  */
  int32_t lastedTime() {return DINItem_c::lastedTime();};
  /**
    check if specific state is set
    @param ren_itemState state information to check
    @return true -> the given state is set
  */
  bool itemState(itemState_t ren_itemState) const
    {return DINItem_c::itemState(ren_itemState);};

  /**
    deliver the state information
    @return state information of type itemState_t (with state informations coded by OR in enum)
  */
  const itemState_t itemState() const
    {return DINItem_c::itemState();};

  /**
    set the state of a local memberItem and send optional the new state, if
    Item::off, Item::standby or Item::active was set
    @param ren_itemState wante new state (independent old values aren't changed)
    @param rb_sendState optional send the new state for TRUE (default: don't send)
    @return resulting state
  */
  itemState_t setItemState(itemState_t ren_itemState, bool rb_sendState = false)
    {return DINItem_c::setItemState(ren_itemState, rb_sendState);};
#ifndef EXCLUDE_RARE_DIN_SYSTEM_CMD
  /**
    deliver the requested state information
    @return state information of type itemState_t (with state informations coded by OR in enum)
  */
  itemState_t requestedState(){return DINItem_c::requestedState();};
  /**
    check if specific state is requested
    @param ren_itemState state information to check
    @return true -> the given state is requested
  */
  bool requestedState(itemState_t ren_itemState) const
    {return DINItem_c::requestedState(ren_itemState);};
#endif
  /**
    retreive the address claim counter
    @return actual address claim cnt
  */
  uint8_t addressClaimCnt(){return DINItem_c::addressClaimCnt();};

  /**
    retreive the counter of false alive msgs
    @return actual false alive cnt
  */
  uint8_t falseAliveCnt() const {return DINItem_c::falseAliveCnt();};

  /**
    retreive the counter of caused conflicts
    @return actual count of caused conflict
  */
  uint8_t causedConflictCnt() const {return DINItem_c::causedConflictCnt();};

  /**
    retreive the counter of affected conflicts
    @return actual count of affected conflict
  */
  uint8_t affectedConflictCnt() const {return DINItem_c::affectedConflictCnt();};
};

}
#endif
