/*
   mkvmerge -- utility for splicing together matroska files
   from component media subtypes

   Distributed under the GPL
   see the file COPYING for details
   or visit http://www.gnu.org/copyleft/gpl.html

   checksum calculations

   Written by Moritz Bunkus <moritz@bunkus.org>.
*/

#ifndef __CHECKSUMS_H
#define __CHECKSUMS_H

#include "os.h"

uint32_t MTX_DLL_API calc_adler32(const unsigned char *buffer, int size);

enum crc_type_e {
  CRC_8_ATM      = 0,
  CRC_16_ANSI    = 1,
  CRC_16_CCITT   = 2,
  CRC_32_IEEE    = 3,
  CRC_32_IEEE_LE = 4,
  CRC_MAX        = CRC_32_IEEE_LE + 1,
};

int MTX_DLL_API crc_init(uint32_t *ctx, int le, int bits, uint32_t poly, int ctx_size);
const uint32_t * MTX_DLL_API crc_get_table(crc_type_e crc_id);
uint32_t crc_calc(const uint32_t *ctx, uint32_t start_crc, const unsigned char *buffer, size_t length);

#endif // __CHECKSUMS_H
