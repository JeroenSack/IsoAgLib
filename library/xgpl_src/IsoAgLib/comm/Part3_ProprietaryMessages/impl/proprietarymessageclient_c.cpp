/*
  proprietarymessageclient_c.cpp

  (C) Copyright 2009 - 2016 by OSB AG and developing partners

  See the repository-log for details on the authors and file-history.
  (Repository information can be found at <http://isoaglib.com/download>)

  Use, modification and distribution are subject to the GNU General
  Public License with exceptions for ISOAgLib. (See accompanying
  file LICENSE.txt or copy at <http://isoaglib.com/download/license>)
*/

#include "proprietarymessageclient_c.h"
#include "proprietarymessagehandler_c.h"
#include <IsoAgLib/comm/impl/isobus_c.h>
#include <IsoAgLib/comm/Part3_DataLink/impl/multisend_c.h>


namespace __IsoAgLib
{
  bool ProprietaryMessageA_c::sendWithPrio( unsigned prio, const IsoName_c& a_overwrite_remote ) {

    isoaglib_assert( prio <= 7 );
    isoaglib_assert(m_ident);
    // do not allow overwrite to a different target if m_remote is specified
    isoaglib_assert(!m_remote.isSpecified() || a_overwrite_remote.isUnspecified() || (a_overwrite_remote == m_remote));

    const uint32_t pgn = ( uint32_t( m_dp ) << 16) | PROPRIETARY_A_PGN;
    if (getDataSend().getLen() <= 8)
    {
      CanPkgExt_c pkg;

      pkg.setIsoPri( static_cast<uint8_t>( prio ) );
      pkg.setIsoPgn( pgn );
      pkg.setISONameForDA( a_overwrite_remote.isSpecified() ? a_overwrite_remote : m_remote );
      pkg.setMonitorItemForSA( m_ident->getIsoItem() );
      pkg.setDataFromString ( getDataSend().getDataStream(), static_cast<uint8_t>( getDataSend().getLen() ) );
      getIsoBusInstance( m_ident->getMultitonInst() ) << pkg;
      return true;
    }
    else
    { /** multi-packet */
      /** variable should be evaluated */
      // const bool cb_couldStartMultiSend =
      // we could catch the information if the sending succeeded, but what to do with it anyway?
      return getMultiSendInstance( m_ident->getMultitonInst() ).sendIsoTarget(
         m_ident->isoName(),
         a_overwrite_remote.isSpecified() ? a_overwrite_remote : m_remote,
         getDataSend().getDataStream(0),
         getDataSend().getLen(),
         pgn,
         this );
    }
  }

  void ProprietaryMessageA_c::init(const IdentItem_c& a_ident, const IsoName_c& a_remote, uint8_t a_dp) {
    isoaglib_assert( NULL == m_ident );
    m_ident = &a_ident;
    m_remote = a_remote;
    m_dp = a_dp;
  }


  void ProprietaryMessageA_c::change(const IdentItem_c& a_ident, const IsoName_c& a_remote, uint8_t a_dp) {
    isoaglib_assert( NULL != m_ident );
    m_ident = &a_ident;
    m_remote = a_remote;
    m_dp = a_dp;
  }


  void ProprietaryMessageA_c::close() {
    isoaglib_assert( NULL != m_ident );
    isoaglib_assert( !m_isRegistered );
    m_ident = NULL;
    m_remote = IsoName_c::IsoNameUnspecified();
    m_dp = 0;
  }


  void ProprietaryMessageA_c::enableReception()
  {
    isoaglib_assert( NULL != m_ident );
    isoaglib_assert( !m_isRegistered );
    getProprietaryMessageHandlerInstance( m_ident->getMultitonInst() ).registerProprietaryMessage( *this );
    m_isRegistered = true;
  }


  void ProprietaryMessageA_c::disableReception()
  {
    isoaglib_assert( NULL != m_ident );
    isoaglib_assert( m_isRegistered );
    getProprietaryMessageHandlerInstance( m_ident->getMultitonInst() ).deregisterProprietaryMessage( *this );
    m_isRegistered = false;
  }





  bool ProprietaryMessageB_c::sendWithPrio( uint8_t ps, unsigned prio, const IsoName_c& a_overwrite_remote ) {

    isoaglib_assert( prio <= 7 );
    isoaglib_assert(m_ident);
    // do not allow overwrite to a different target if m_remote is specified
    isoaglib_assert(!m_remote.isSpecified() || a_overwrite_remote.isUnspecified() || (a_overwrite_remote == m_remote));

    const uint32_t pgn = ( uint32_t( m_dp ) << 16) | PROPRIETARY_B_PGN | ps;
    if (getDataSend().getLen() <= 8)
    {
      CanPkgExt_c pkg;

      pkg.setIsoPri( static_cast<uint8_t>( prio ) );
      pkg.setIsoPgn( pgn );
      pkg.setMonitorItemForSA( m_ident->getIsoItem() );
      pkg.setDataFromString ( getDataSend().getDataStream(), static_cast<uint8_t>( getDataSend().getLen() ) );
      getIsoBusInstance( m_ident->getMultitonInst() ) << pkg;
      return true;
    }
    else
    { /** multi-packet */
      /** variable should be evaluated */
      // const bool cb_couldStartMultiSend =
      // we could catch the information if the sending succeeded, but what to do with it anyway?
      return getMultiSendInstance( m_ident->getMultitonInst() ).sendIsoTarget(
         m_ident->isoName(),
         a_overwrite_remote.isSpecified() ? a_overwrite_remote : m_remote,
         getDataSend().getDataStream(0),
         getDataSend().getLen(),
         pgn,
         this );
    }
  }

  void ProprietaryMessageB_c::init(const IdentItem_c& a_ident, const IsoName_c& a_remote, uint8_t a_dp) {
    isoaglib_assert(NULL == m_ident);
    m_ident = &a_ident;
    m_remote = a_remote;
    m_dp = a_dp;
  }


  void ProprietaryMessageB_c::change(const IdentItem_c& a_ident, const IsoName_c& a_remote, uint8_t a_dp) {
    isoaglib_assert(NULL != m_ident);
    m_ident = &a_ident;
    m_remote = a_remote;
    m_dp = a_dp;
  }


  void ProprietaryMessageB_c::close() {
    isoaglib_assert(NULL != m_ident);
    m_ident = NULL;
    m_remote = IsoName_c::IsoNameUnspecified();
    m_dp = 0;
  }


  void ProprietaryMessageB_c::enableReception( uint8_t ps )
  {
    isoaglib_assert(NULL != m_ident);
    getProprietaryMessageHandlerInstance( m_ident->getMultitonInst() ).registerProprietaryMessage( *this, ps );
  }


  void ProprietaryMessageB_c::disableReception( uint8_t ps )
  {
    isoaglib_assert(NULL != m_ident);
    getProprietaryMessageHandlerInstance( m_ident->getMultitonInst() ).deregisterProprietaryMessage( *this, ps );
  }

};
