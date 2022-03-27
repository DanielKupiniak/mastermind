#pragma once
#include <array>

#include "utils.h"

namespace MasterMind {

class PegPattern {
 private:
  std::array<CodePeg, 4> mCodePeg;

 public:
  PegPattern(Peg c0, Peg c1, Peg c2, Peg c3);

  Pos match(const CodePeg& cos);

  bool isUnique();

  std::array<CodePeg, 4> getCodePeg() const;
};
}  // namespace MasterMind