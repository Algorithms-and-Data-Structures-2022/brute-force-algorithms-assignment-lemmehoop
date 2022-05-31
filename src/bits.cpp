#include "assignment/bits.hpp"

#include <cassert>  // assert

namespace assignment {

  bool is_bit_set(int mask, int pos) {
    assert(mask >= 0 && pos >= 0 && pos < 30);  // pos < макс. кол-ва бит в маске

    int new_mask = 1 << pos;

    return mask & new_mask;
  }

  int set_bit(int mask, int pos) {
    assert(mask >= 0 && pos >= 0 && pos < 30);
    int new_mask = 1 << pos;
    mask = new_mask | mask;
    return mask;
  }

  std::vector<int> mask2indices(const std::vector<int>& elems, int mask) {
    assert(mask >= 0);

    std::vector<int> indices;

    for (int pos = 0; pos < static_cast<int>(elems.size()); pos++) {

      if (is_bit_set(mask, pos)) {
        indices.push_back(pos);
      }
    }

    return indices;
  }

  std::vector<int> mask2elems(const std::vector<int>& elems, int mask) {
    assert(mask >= 0);

    std::vector<int> masked_elems;

    for (int pos = 0; pos < static_cast<int>(elems.size()); pos++) {

      if (is_bit_set(mask, pos)) {
        masked_elems.push_back(elems[pos]);
      }
    }

    return masked_elems;
  }

}  // namespace assignment