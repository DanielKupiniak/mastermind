#include <gtest/gtest.h>

#include "Peg.h"
#include "Score.h"
#include "utils.h"

using namespace MasterMind;

TEST(Score, OneBlack) {
  CodePeg entered(Peg::Black, Peg::Red, Peg::Yellow, Peg::Red);
  Score score(Peg::Black, Peg::Blue, Peg::Green, Peg::Orange);
  std::vector<Result> expectedResult = {Result::Black, Result::Missed,
                                        Result::Missed, Result::Missed};
  score.hit(entered);
  auto actualResult = score.getResult();
  EXPECT_EQ(expectedResult, actualResult);
}

TEST(Score, OneWhite) {
  CodePeg entered(Peg::Red, Peg::Green, Peg::Yellow, Peg::Green);
  Score score(Peg::Black, Peg::Blue, Peg::Red, Peg::Orange);

  std::vector<Result> expected = {Result::White, Result::Missed, Result::Missed,
                                  Result::Missed};
  score.hit(entered);
  auto actualResult = score.getResult();
  EXPECT_EQ(expected, actualResult);
}

TEST(Score, OneWhiteOneBlack) {
  CodePeg entered(Peg::Red, Peg::Green, Peg::Red, Peg::Black);
  Score score(Peg::Black, Peg::Blue, Peg::Red, Peg::Orange);

  std::vector<Result> expected = {Result::Black, Result::White, Result::Missed,
                                  Result::Missed};
  score.hit(entered);
  auto actualResult = score.getResult();
  EXPECT_EQ(expected, actualResult);
}

TEST(Score, TwoWhiteTwoBlack) {
  CodePeg entered(Peg::Black, Peg::Orange, Peg::Green, Peg::Red);
  Score score(Peg::Black, Peg::Red, Peg::Green, Peg::Orange);

  std::vector<Result> expected = {Result::Black, Result::Black, Result::White,
                                  Result::White};
  score.hit(entered);
  auto actualResult = score.getResult();
  EXPECT_EQ(expected, actualResult);
}
