/*
   mkvmerge -- utility for splicing together matroska files
   from component media subtypes

   Distributed under the GPL v2
   see the file COPYING for details
   or visit http://www.gnu.org/copyleft/gpl.html

   math helper functions

   Written by Moritz Bunkus <moritz@bunkus.org>.
*/

#include "common/common_pch.h"

#include "common/math.h"

namespace mtx { namespace math {

uint64_t
round_to_nearest_pow2(uint64_t value) {
  uint64_t best_value = 0;
  uint64_t test_value = 1;

  while (0x8000000000000000ull >= test_value) {
    if (  (value > test_value ? value - test_value : test_value - value)
        < (value > best_value ? value - best_value : best_value - value))
      best_value = test_value;
    test_value <<= 1;
  }

  return best_value;
}

int
int_log2(uint64_t value) {
  for (int bit = 63; bit >= 0; --bit)
    if (value & (1ull << bit))
      return bit;

  return -1;
}

double
int_to_double(int64_t value) {
  if (static_cast<uint64_t>(value + value) > (0xffeull << 52))
    return NAN;
  return std::ldexp(((value & ((1ll << 52) - 1)) + (1ll << 52)) * (value >> 63 | 1), (value >> 52 & 0x7ff) - 1075);
}

}}
