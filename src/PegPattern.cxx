#include "PegPattern.h"

#include <set>

namespace MasterMind {

PegPattern::PegPattern(const Peg& c0, const Peg& c1, const Peg& c2,
                       const Peg& c3)
    : mPegSeq{{{c0, Pos::C0}, {c1, Pos::C1}, {c2, Pos::C2}, {c3, Pos::C3}}} {}

PegPattern::PegPattern(const CodePegSeq& pegs) : mPegSeq(pegs) {}

Pos PegPattern::find(const Peg& peg) {
  for (auto& e : mPegSeq) {
    if (peg == e.first) {
      return e.second;
    }
  }
  return Pos::None;
}

bool PegPattern::isUnique() const {
  std::set<Peg> uniqueSeq;
  for (auto& e : mPegSeq) {
    uniqueSeq.insert(e.first);
  }
  return uniqueSeq.size() == mPegSeq.size();
}

Peg PegPattern::at(const Pos& pos) const {
  return mPegSeq.at(static_cast<int>(pos)).first;
}

size_t PegPattern::size() const { return mPegSeq.size(); }

CodePegSeq PegPattern::getPegSeq() const { return mPegSeq; }
}  // namespace MasterMind