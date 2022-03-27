#pragma once
#include <vector>

#include "PegPattern.h"
#include "utils.h"
namespace MasterMind {
class Score {
 private:
  std::vector<Result> mResult;
  PegPattern mExpected;

 public:
  Score(Peg c0, Peg c1, Peg c2, Peg c3);
  void hit(PegPattern& codePeg);
  std::vector<Result> getResult() const;
};
}  // namespace MasterMind