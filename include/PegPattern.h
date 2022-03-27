#pragma once
#include <array>

#include "utils.h"

namespace MasterMind {

class PegPattern {
 private:
  std::array<Cos, 4> mCodePeg;

 public:
  PegPattern(Peg c0, Peg c1, Peg c2, Peg c3);

  Pos match(const Cos& cos);

  bool isUnique();

  std::array<Cos, 4> getCos() const;
};
}  // namespace MasterMind