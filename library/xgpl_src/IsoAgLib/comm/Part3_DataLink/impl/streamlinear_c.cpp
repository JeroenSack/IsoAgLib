/*
  streamlinear_c.cpp

  (C) Copyright 2009 - 2010 by OSB AG and developing partners

  See the repository-log for details on the authors and file-history.
  (Repository information can be found at <http://isoaglib.com/download>)

  Use, modification and distribution are subject to the GNU General
  Public License with exceptions for ISOAgLib. (See accompanying
  file LICENSE.txt or copy at <http://isoaglib.com/download/license>)
*/

#include "streamlinear_c.h"
#include "chunk_c.h"



// Begin Namespace __IsoAgLib
namespace __IsoAgLib {



  StreamLinear_c::StreamLinear_c (StreamType_t at_streamType, const IsoAgLib::ReceiveStreamIdentifier_c& ac_rsi, uint32_t aui32_msgSize SINGLETON_VEC_KEY_PARAMETER_DEF_WITH_COMMA)
  : Stream_c (at_streamType, ac_rsi, aui32_msgSize SINGLETON_VEC_KEY_PARAMETER_USE_WITH_COMMA)
  , mui32_parsedCnt (0)
{
  mvecui8_buffer.reserve (aui32_msgSize); // as reactOnStreamStart told we have enough memory!
};

StreamLinear_c::~StreamLinear_c()
{
}


#ifdef ENABLE_MULTIPACKET_VARIANT_FAST_PACKET
// //////////////////////////////// +X2C Operation : insert6Bytes
//! Parameter:
//! @param pui8_data: pointer to 6 bytes of data!
void
StreamLinear_c::insertFirst6Bytes(const uint8_t* pui8_data)
{
  mvecui8_buffer.push_back (pui8_data[0]);
  mvecui8_buffer.push_back (pui8_data[1]);
  mvecui8_buffer.push_back (pui8_data[2]);
  mvecui8_buffer.push_back (pui8_data[3]);
  mvecui8_buffer.push_back (pui8_data[4]);
  mvecui8_buffer.push_back (pui8_data[5]);
}
#endif

// //////////////////////////////// +X2C Operation : insert7Bytes
//! Parameter:
//! @param pui8_data: pointer to 7 bytes of data!
void
StreamLinear_c::insert7Bytes(const uint8_t* pui8_data)
{ // ~X2C
  mvecui8_buffer.push_back (pui8_data[0]);
  mvecui8_buffer.push_back (pui8_data[1]);
  mvecui8_buffer.push_back (pui8_data[2]);
  mvecui8_buffer.push_back (pui8_data[3]);
  mvecui8_buffer.push_back (pui8_data[4]);
  mvecui8_buffer.push_back (pui8_data[5]);
  mvecui8_buffer.push_back (pui8_data[6]);
  // as ui32_recCnt is mvecui8_buffer.size(), it is automatically increased!
} // -X2C



} // end namespace __IsoAgLib
