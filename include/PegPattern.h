#pragma once
#include <vector>

#include "utils.h"

namespace MasterMind {

class PegPattern {
 private:
  std::vector<CodePeg> mPegSeq;

 public:
  PegPattern(const Peg& c0, const Peg& c1, const Peg& c2, const Peg& c3);
  Peg at(const Pos& pos) const;
  Pos find(const Peg& cos);
  bool isUnique() const;
  size_t size() const;

  std::vector<CodePeg> getPegSeq() const;
};

}  // namespace MasterMind