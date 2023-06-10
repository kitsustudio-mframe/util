/**
 * Copyright (c) 2020 ZxyKira
 * All rights reserved.
 *
 * SPDX-License-Identifier: MIT
 *
 * ====================================================================
 * Copyright (c) 1995-1999 The Apache Group.  All rights reserved.
 *
 * Redistribution and use in source and binary forms, with or without
 * modification, are permitted provided that the following conditions
 * are met:
 *
 * 1. Redistributions of source code must retain the above copyright
 *    notice, this list of conditions and the following disclaimer.
 *
 * 2. Redistributions in binary form must reproduce the above copyright
 *    notice, this list of conditions and the following disclaimer in
 *    the documentation and/or other materials provided with the
 *    distribution.
 *
 * 3. All advertising materials mentioning features or use of this
 *    software must display the following acknowledgment:
 *    "This product includes software developed by the Apache Group
 *    for use in the Apache HTTP server project (http://www.apache.org/)."
 *
 * 4. The names "Apache Server" and "Apache Group" must not be used to
 *    endorse or promote products derived from this software without
 *    prior written permission. For written permission, please contact
 *    apache@apache.org.
 *
 * 5. Products derived from this software may not be called "Apache"
 *    nor may "Apache" appear in their names without prior written
 *    permission of the Apache Group.
 *
 * 6. Redistributions of any form whatsoever must retain the following
 *    acknowledgment:
 *    "This product includes software developed by the Apache Group
 *    for use in the Apache HTTP server project (http://www.apache.org/)."
 *
 * THIS SOFTWARE IS PROVIDED BY THE APACHE GROUP ``AS IS'' AND ANY
 * EXPRESSED OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE
 * IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR
 * PURPOSE ARE DISCLAIMED.  IN NO EVENT SHALL THE APACHE GROUP OR
 * ITS CONTRIBUTORS BE LIABLE FOR ANY DIRECT, INDIRECT, INCIDENTAL,
 * SPECIAL, EXEMPLARY, OR CONSEQUENTIAL DAMAGES (INCLUDING, BUT
 * NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS OR SERVICES;
 * LOSS OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION)
 * HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN CONTRACT,
 * STRICT LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE)
 * ARISING IN ANY WAY OUT OF THE USE OF THIS SOFTWARE, EVEN IF ADVISED
 * OF THE POSSIBILITY OF SUCH DAMAGE.
 * ====================================================================
 *
 * This software consists of voluntary contributions made by many
 * individuals on behalf of the Apache Group and was originally based
 * on public domain software written at the National Center for
 * Supercomputing Applications, University of Illinois, Urbana-Champaign.
 * For more information on the Apache Group and the Apache HTTP server
 * project, please see <http://www.apache.org/>.
 *
 */

/* ****************************************************************************************
 * Include
 */
#include "./Base64.h"

//-----------------------------------------------------------------------------------------
#include "mframe.h"

/* ****************************************************************************************
 * Macro
 */

/* ****************************************************************************************
 * Using
 */

//-----------------------------------------------------------------------------------------

//-----------------------------------------------------------------------------------------
using util::Base64;

/* ****************************************************************************************
 * Variable <Static>
 */

/* ****************************************************************************************
 * Construct Method
 */

//-----------------------------------------------------------------------------------------
Base64::Base64(void) {
  return;
}

//-----------------------------------------------------------------------------------------
Base64::~Base64(void) {
  return;
}

/* ****************************************************************************************
 * Operator Method
 */

/* ****************************************************************************************
 * Public Method <Static>
 */

/* ****************************************************************************************
 * Public Method <Override>
 */

/* ****************************************************************************************
 * Public Method
 */

//-----------------------------------------------------------------------------------------
int Base64::encode(const void *src, int srcLen, void *dst, int dstLen) {
  int i;
  char *p;

  if (this->encodeLen(srcLen) >= dstLen)
    return 0;

  p = static_cast<char *>(dst);
  const unsigned char *str = reinterpret_cast<const unsigned char *>(src);

  for (i = 0; i < srcLen - 2; i += 3) {
    *p++ = this->mTable[(str[i] >> 2) & 0x3F];
    *p++ = this->mTable[((str[i] & 0x3) << 4) |
                        (static_cast<int>(str[i + 1] & 0xF0) >> 4)];
    *p++ = this->mTable[((str[i + 1] & 0xF) << 2) |
                        (static_cast<int>(str[i + 2] & 0xC0) >> 6)];
    *p++ = this->mTable[str[i + 2] & 0x3F];
  }
  if (i < srcLen) {
    *p++ = this->mTable[(str[i] >> 2) & 0x3F];
    if (i == (srcLen - 1)) {
      *p++ = this->mTable[((str[i] & 0x3) << 4)];
      *p++ = '=';
    } else {
      *p++ = this->mTable[((str[i] & 0x3) << 4) |
                          (static_cast<int>(str[i + 1] & 0xF0) >> 4)];
      *p++ = this->mTable[((str[i + 1] & 0xF) << 2)];
    }
    *p++ = '=';
  }

  *(p + 1) = 0x00;
  return p - static_cast<char *>(dst);
}

//-----------------------------------------------------------------------------------------
int Base64::encodeLen(int len) {
  return ((len + 2) / 3 * 4);
}

//-----------------------------------------------------------------------------------------
int Base64::decode(const char *src, void *dst, int dstLen) {
  int nbytesdecoded;
  const unsigned char *bufin;
  unsigned char *bufout;
  int nprbytes;

  bufin = reinterpret_cast<const unsigned char *>(src);
  while (this->mPiexl[*(bufin++)] <= 63)
    ;

  nprbytes = (bufin - reinterpret_cast<const unsigned char *>(src)) - 1;
  nbytesdecoded = ((nprbytes + 3) / 4) * 3;
  if (nbytesdecoded > dstLen)
    return 0;

  bufout = static_cast<unsigned char *>(dst);
  bufin = reinterpret_cast<const unsigned char *>(src);

  while (nprbytes > 4) {
    *(bufout++) =
        static_cast<unsigned char>(this->mPiexl[*bufin] << 2 | this->mPiexl[bufin[1]] >> 4);
    *(bufout++) =
        static_cast<unsigned char>(this->mPiexl[bufin[1]] << 4 | this->mPiexl[bufin[2]] >> 2);
    *(bufout++) =
        static_cast<unsigned char>(this->mPiexl[bufin[2]] << 6 | this->mPiexl[bufin[3]]);
    bufin += 4;
    nprbytes -= 4;
  }

  /* Note: (nprbytes == 1) would be an error, so just ingore that case */
  if (nprbytes > 1) {
    *(bufout++) =
        static_cast<unsigned char>(this->mPiexl[*bufin] << 2 | this->mPiexl[bufin[1]] >> 4);
  }
  if (nprbytes > 2) {
    *(bufout++) =
        static_cast<unsigned char>(this->mPiexl[bufin[1]] << 4 | this->mPiexl[bufin[2]] >> 2);
  }
  if (nprbytes > 3) {
    *(bufout++) =
        static_cast<unsigned char>(this->mPiexl[bufin[2]] << 6 | this->mPiexl[bufin[3]]);
  }

  *(bufout + 1) = 0x00;
  nbytesdecoded -= (4 - nprbytes) & 3;
  return nbytesdecoded;
}

//-----------------------------------------------------------------------------------------
int Base64::decodeLen(const char *src) {
  int nbytesdecoded;
  const unsigned char *bufin;
  int nprbytes;

  bufin = reinterpret_cast<const unsigned char *>(src);
  while (this->mPiexl[*(bufin++)] <= 63)
    ;

  nprbytes = (bufin - reinterpret_cast<const unsigned char *>(src)) - 1;
  nbytesdecoded = ((nprbytes + 3) / 4) * 3;

  return nbytesdecoded;
}

/* ****************************************************************************************
 * Protected Method <Static>
 */

/* ****************************************************************************************
 * Protected Method <Override>
 */

/* ****************************************************************************************
 * Protected Method
 */

/* ****************************************************************************************
 * Private Method
 */

/* ****************************************************************************************
 * End of file
 */
