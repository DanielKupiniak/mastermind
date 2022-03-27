#pragma once
#include <vector>

#include "utils.h"

namespace MasterMind {

class PegPattern {
 private:
  CodePegSeq mPegSeq;

 public:
  PegPattern(const Peg& c0, const Peg& c1, const Peg& c2, const Peg& c3);
  PegPattern(const CodePegSeq& pegs);

  Peg at(const Pos& pos) const;
  Pos find(const Peg& cos);
  bool isUnique() const;
  size_t size() const;

  CodePegSeq getPegSeq() const;
};

}  // namespace MasterMind