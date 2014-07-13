#ifndef MATCH_H
#define MATCH_H

#include "model.h"

#include <vector>
#include <array>

class Match : public Model {
 public:
  Match(const std::vector<unsigned char>& history,
    const unsigned long long& byte_context, const unsigned int& bit_context_,
    int limit, float delta, unsigned long long map_size,
    unsigned long long* longest_match);
  float Predict();
  void Perceive(int bit);
  void ByteUpdate();

 private:
  const std::vector<unsigned char>& history_;
  const unsigned long long& byte_context_;
  const unsigned int& bit_context_;
  unsigned long long history_pos_;
  unsigned long long cur_match_;
  unsigned char cur_byte_;
  unsigned char bit_pos_;
  unsigned char match_length_;
  unsigned long long* longest_match_;
  int limit_;
  float delta_;
  float divisor_;
  std::vector<unsigned int> map_;
  std::array<float, 256> predictions_;
  std::array<int, 256> counts_;
};

#endif

