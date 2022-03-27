#include "PegPattern.h"

#include <set>

namespace MasterMind {

PegPattern::PegPattern(Peg c0, Peg c1, Peg c2, Peg c3)
    : mCodePeg{{{c0, Pos::C0}, {c1, Pos::C1}, {c2, Pos::C2}, {c3, Pos::C3}}} {}

Pos PegPattern::match(const Cos& cos) {
  for (auto& e : mCodePeg) {
    if (cos.first == e.first) {
      return e.second;
    }
  }
  return Pos::None;
}

bool PegPattern::isUnique() {
  std::set<Peg> uniqueSeq;
  for (auto& e : mCodePeg) {
    uniqueSeq.insert(e.first);
  }
  return uniqueSeq.size() == mCodePeg.size();
}

std::array<Cos, 4> PegPattern::getCos() const { return mCodePeg; }
}  // namespace MasterMind