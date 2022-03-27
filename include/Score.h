#pragma once
#include <set>
#include <vector>

#include "PegPattern.h"
#include "utils.h"

namespace MasterMind {
class Score {
 private:
  Result mResult;
  PegPattern mExpected;

  std::set<Pos> matchedPegs(const PegPattern& givenPeg);
  void calculateResult(const std::set<Pos>& count, const PegPattern& givenPeg);
  void sortResult();

 public:
  Score(Peg c0, Peg c1, Peg c2, Peg c3);
  Score(const PegPattern& pegPattern);
  void hit(PegPattern& codePeg);
  Result getResult() const;
};
}  // namespace MasterMind