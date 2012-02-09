/*
  aux2inputs_c.h:
  - send Auxiliary Input Type 2 Maintenance message

  (C) Copyright 2009 - 2011 by OSB AG and developing partners

  See the repository-log for details on the authors and file-history.
  (Repository information can be found at <http://isoaglib.com/download>)

  Use, modification and distribution are subject to the GNU General
  Public License with exceptions for ISOAgLib. (See accompanying
  file LICENSE.txt or copy at <http://isoaglib.com/download/license>)
*/
#ifndef AUX2INPUTS_H
#define AUX2INPUTS_H

#include <IsoAgLib/scheduler/impl/schedulertask_c.h>
#include <IsoAgLib/util/impl/singleton.h>
#include <IsoAgLib/comm/Part5_NetworkManagement/impl/identitem_c.h>

#include "../ivtobjectauxiliaryinput2_c.h"

namespace __IsoAgLib {

// forward declaration
class VtClientServerCommunication_c;

class Aux2Inputs_c : public Scheduler_Task_c
{
  // @todo: check correct singleton instantiation!
#if 1 < PRT_INSTANCE_CNT
  MACRO_MULTITON_CONTRIBUTION();
#else
  MACRO_SINGLETON_CONTRIBUTION();
#endif

public:

  enum Aux2InputsState_en 
  {
    Aux2InputsState_Initializing = 0,
    Aux2InputsState_Ready = 1,
    Aux2InputsState_NoAuxInputAvailable
  };

  Aux2Inputs_c(const IdentItem_c& arc_wsMasterIdentItem);

  virtual ~Aux2Inputs_c(void);

  void init(VtClientServerCommunication_c* a_vtClientServerCommunication);

  /**
    send AUX2 input maintenance message (100msec) and call timeEventInputStateMsg(NULL) (1sec)
  */
  bool timeEvent(void);

  inline void setState(Aux2InputsState_en a_state) { m_state = a_state; }

  inline void setModelIdentificationCode(uint16_t a_model) { m_modelIdentificationCode = a_model; }

#ifdef USE_VTOBJECT_auxiliaryinput2
  STL_NAMESPACE::list<IsoAgLib::iVtObjectAuxiliaryInput2_c*>& getObjectList() { return mlist_auxInput2; }
#endif

  /**
    set enabled state for matching input object ID (0xFFFF => all input objects)
    @return TRUE if at least one object ID matches
  */
  bool setInputStateEnabledInObjects(uint16_t aui16_inputObjId, bool a_enabled);


#ifdef USE_VTOBJECT_auxiliaryinput2
  /**
    send AUX2 input status message for all inputs (a_aux2InputObj == NULL) or only for passed AUX2 input object
  */
  void timeEventInputStateMsg(vtObjectAuxiliaryInput2_c* a_aux2InputObj);
#endif

  void setLearnMode(bool a_learnMode) { mb_learnMode = a_learnMode; }

private:

  const IdentItem_c& mrc_wsMasterIdentItem;

  Aux2InputsState_en m_state;

  uint16_t m_modelIdentificationCode;

#ifdef USE_VTOBJECT_auxiliaryinput2
  STL_NAMESPACE::list<IsoAgLib::iVtObjectAuxiliaryInput2_c*> mlist_auxInput2;
#endif

  // time stamp of last auxiliary input maintenance message sent
  uint32_t mui32_timeStampLastMaintenance;

  bool mb_learnMode;

  VtClientServerCommunication_c* mp_vtClientServerCommunication;
};


}
#endif