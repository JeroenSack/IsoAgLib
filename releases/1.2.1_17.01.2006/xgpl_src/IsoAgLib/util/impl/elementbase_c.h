/***************************************************************************
                          elementbase_c.h - header for base class for all
                                               IsoAgLib member objects which
                                               stores the pointer to the IsoAgLib
                                               instance, and delivers some
                                               access features to other
                                               components of the system
                             -------------------
    begin                 Fri Apr 07 2000
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
 * Copyright (C) 2000 - 2004 Dipl.-Inform. Achim Spangler                 *
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
#ifndef ELEMENT_BASE_H
#define ELEMENT_BASE_H


/* *************************************** */
/* ********** include headers ************ */
/* *************************************** */
//#include <Application_Config/isoaglib_config.h>
#include <IsoAgLib/hal/config.h>
#include <IsoAgLib/util/impl/cancustomer_c.h>


// Begin Namespace __IsoAgLib
namespace __IsoAgLib {

/** Base class for member classes of IsoAgLib
  * which have a timeEvent() function, that
  * shall be called by Scheduler_c::timeEvent()
  *@author Dipl.-Inform. Achim Spangler
  */
class ElementBase_c : public CANCustomer_c {
 public:
  /** this function is used by IsoAgLib components
    * to perform periodic timed tasks.
    * The central function Scheduler_c::timeEvent()
    * calls the timeEvent() function of all
    * IsoAgLib subsystem classes which are derived
    * from ElementBase_c and which registered
    * in the list of Scheduler_c during init
    * @return true -> all planned activities performed in available time
    */
  virtual bool timeEvent( void ) = 0;
  /** this function is used by IsoAgLib components
    * to close all their ressources.
    * this enables a coordinated shutdown by Scheduler_c
    */
  virtual void close( void ) = 0;
  /** clear b_alreadyClosed so that close() can be called one time */
  void clearAlreadyClosed( void ) { b_alreadyClosed = false; } ;
  /** set b_alreadyClosed so that close() can't be called another time */
  void setAlreadyClosed( void ) { b_alreadyClosed = true; } ;
  /** check b_alreadyClosed to decide if close() can be called */
  bool checkAlreadyClosed( void ) const { return b_alreadyClosed; } ;
 private:
   /** store already called close() after last call of init() */
   bool b_alreadyClosed;
};

} // end namespace __IsoAgLib
#endif
