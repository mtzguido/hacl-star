/* MIT License
 *
 * Copyright (c) 2016-2022 INRIA, CMU and Microsoft Corporation
 * Copyright (c) 2022-2023 HACL* Contributors
 *
 * Permission is hereby granted, free of charge, to any person obtaining a copy
 * of this software and associated documentation files (the "Software"), to deal
 * in the Software without restriction, including without limitation the rights
 * to use, copy, modify, merge, publish, distribute, sublicense, and/or sell
 * copies of the Software, and to permit persons to whom the Software is
 * furnished to do so, subject to the following conditions:
 *
 * The above copyright notice and this permission notice shall be included in all
 * copies or substantial portions of the Software.
 *
 * THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
 * IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
 * FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE
 * AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER
 * LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM,
 * OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN THE
 * SOFTWARE.
 */


#ifndef __Hacl_Hash_SHA3_H
#define __Hacl_Hash_SHA3_H

#if defined(__cplusplus)
extern "C" {
#endif

#include <string.h>
#include "krml/internal/types.h"
#include "krml/lowstar_endianness.h"
#include "krml/internal/target.h"

#include "Lib_Memzero0.h"
#include "Hacl_Hash_Types.h"

typedef Hacl_Streaming_MD_state_64 Hacl_Streaming_SHA3_state_256;

Hacl_Streaming_MD_state_64 *Hacl_Streaming_SHA3_create_in_256(void);

void Hacl_Streaming_SHA3_init_256(Hacl_Streaming_MD_state_64 *s);

/**
0 = success, 1 = max length exceeded. Due to internal limitations, there is currently an arbitrary limit of 2^64-1 bytes that can be hashed through this interface.
*/
uint32_t
Hacl_Streaming_SHA3_update_256(Hacl_Streaming_MD_state_64 *p, uint8_t *data, uint32_t len);

void Hacl_Streaming_SHA3_finish_256(Hacl_Streaming_MD_state_64 *p, uint8_t *dst);

void Hacl_Streaming_SHA3_free_256(Hacl_Streaming_MD_state_64 *s);

Hacl_Streaming_MD_state_64 *Hacl_Streaming_SHA3_copy_256(Hacl_Streaming_MD_state_64 *s0);

void
Hacl_SHA3_shake128_hacl(
  uint32_t inputByteLen,
  uint8_t *input,
  uint32_t outputByteLen,
  uint8_t *output
);

void
Hacl_SHA3_shake256_hacl(
  uint32_t inputByteLen,
  uint8_t *input,
  uint32_t outputByteLen,
  uint8_t *output
);

void Hacl_SHA3_sha3_224(uint32_t inputByteLen, uint8_t *input, uint8_t *output);

void Hacl_SHA3_sha3_256(uint32_t inputByteLen, uint8_t *input, uint8_t *output);

void Hacl_SHA3_sha3_384(uint32_t inputByteLen, uint8_t *input, uint8_t *output);

void Hacl_SHA3_sha3_512(uint32_t inputByteLen, uint8_t *input, uint8_t *output);

extern const uint32_t Hacl_Impl_SHA3_keccak_rotc[24U];

extern const uint32_t Hacl_Impl_SHA3_keccak_piln[24U];

extern const uint64_t Hacl_Impl_SHA3_keccak_rndc[24U];

uint64_t Hacl_Impl_SHA3_rotl(uint64_t a, uint32_t b);

void Hacl_Impl_SHA3_state_permute(uint64_t *s);

void Hacl_Impl_SHA3_loadState(uint32_t rateInBytes, uint8_t *input, uint64_t *s);

void Hacl_Impl_SHA3_storeState(uint32_t rateInBytes, uint64_t *s, uint8_t *res);

void
Hacl_Impl_SHA3_absorb(
  uint64_t *s,
  uint32_t rateInBytes,
  uint32_t inputByteLen,
  uint8_t *input,
  uint8_t delimitedSuffix
);

void
Hacl_Impl_SHA3_squeeze(
  uint64_t *s,
  uint32_t rateInBytes,
  uint32_t outputByteLen,
  uint8_t *output
);

void
Hacl_Impl_SHA3_keccak(
  uint32_t rate,
  uint32_t capacity,
  uint32_t inputByteLen,
  uint8_t *input,
  uint8_t delimitedSuffix,
  uint32_t outputByteLen,
  uint8_t *output
);

#if defined(__cplusplus)
}
#endif

#define __Hacl_Hash_SHA3_H_DEFINED
#endif
