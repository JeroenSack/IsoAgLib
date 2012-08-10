/***************************************************************************
                          imeasure_prog_local.h - object for managing local

  (C) Copyright 2009 - 2012 by OSB AG and developing partners

  See the repository-log for details on the authors and file-history.
  (Repository information can be found at <http://isoaglib.com/download>)

  Use, modification and distribution are subject to the GNU General
  Public License with exceptions for ISOAgLib. (See accompanying
  file LICENSE.txt or copy at <http://isoaglib.com/download/license>)
*/
#ifndef IMEASURE_PROG_LOCAL_H
#define IMEASURE_PROG_LOCAL_H

/* *************************************** */
/* ********** include headers ************ */
/* *************************************** */
#include "impl/measureproglocal_c.h"
#include <IsoAgLib/comm/Part5_NetworkManagement//iisoname_c.h>


// Begin Namespace IsoAgLib
namespace IsoAgLib {
/**
  managing of local measure progs and values;
  sending values for running programs,
  answering value requests,
  starting and stopping measure programs by remote
  @see MeasureProgRemote
  @author Dipl.-Inform. Achim Spangler
*/
class iMeasureProgLocal_c : private __IsoAgLib::MeasureProgLocal_c {
private:
  // private typedef alias names
  typedef __IsoAgLib::Proc_c Proc_c;
public:
  /**
    deliver med val
  */
  virtual int32_t med() const {return MeasureProgLocal_c::med();};


  /**
    deliver value
    @return measure val for this prog (can differ from master measure val)
  */
  int32_t val(){return MeasureProgLocal_c::val();};
  /**
    deliver integ val
    @return integral val for this measure prog
  */
  int32_t integ(){return MeasureProgLocal_c::integ();};
  /**
    deliver min val
    @return MIN val for this measure prog
  */
  int32_t min(){return MeasureProgLocal_c::min();};
  /**
    deliver max val
    @return MAX val for this measure prog
  */
  int32_t max(){return MeasureProgLocal_c::max();};
  /**
    deliver the delta
    @return:delta between the last two measure vals [1/sec]
  */
  int32_t delta(){return MeasureProgLocal_c::delta();};
  /**
    deliver the acceleration
    @return acceleration calculated from the last delta values [1/(sec*sec)]
  */
  int32_t accel(){return MeasureProgLocal_c::accel();};

  /**
    return the c_isoName code for this measureProg
    @return ISOName of this measureProg
  */
  const iIsoName_c& isoName(){return MeasureProgLocal_c::isoName().toConstIisoName_c();};
  /**
    deliver the type of the active increment types
    @return actual Bit-OR combined increment types
  */
  Proc_c::type_t type(){return MeasureProgLocal_c::type();};
  /**
    check if the given increment type is active
    @param ren_type tested increment type
    @return true -> given increment type is set
  */
  bool checkType(Proc_c::type_t ren_type)
    {return MeasureProgLocal_c::checkType(ren_type);};
  /**
    check if given send type is activated
    @param ren_doSend tested sended value
    @return true -> given value is sent on trigger
  */
  bool checkDoSend(Proc_c::doSend_t ren_doSend)
    {return MeasureProgLocal_c::checkDoSend(ren_doSend);};
 private:
  friend class iProcDataLocal_c;
};

}
#endif
