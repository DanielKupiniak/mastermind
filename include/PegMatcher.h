#pragma once
#include <set>
#include <vector>

#include "PegPattern.h"
#include "utils.h"

namespace MasterMind {
class PegMatcher {
 private:
  Result mResult;
  PegPattern mExpected;

  /**
   * @brief matches given Pegs agains secret pattern, and returs positions of
   * matched Pegs
   *
   * @param givenPeg
   * @return std::set<Pos>
   */
  std::set<Pos> matchedPegs(const PegPattern& givenPeg);

  /**
   * @brief based on matches stores result
   *
   * @param matches
   * @param givenPeg
   */
  void calculateResult(const std::set<Pos>& matches,
                       const PegPattern& givenPeg);
  /**
   * @brief sort result in order B->W->X
   *
   */
  void sortResult();

 public:
  /**
   * @brief Construct a new Peg Matcher object
   *
   * @param c0
   * @param c1
   * @param c2
   * @param c3
   */
  PegMatcher(Peg c0, Peg c1, Peg c2, Peg c3);

  /**
   * @brief Construct a new Peg Matcher object
   *
   * @param pegPattern
   */

  PegMatcher(const PegPattern& pegPattern);
  /**
   * @brief calculates result based on given PegPattern
   *
   * @param codePeg
   */

  void run(PegPattern& codePeg);
  /**
   * @brief Get the Result object
   *
   * @return Result
   */
  Result getResult() const;
};
}  // namespace MasterMind