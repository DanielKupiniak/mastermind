#include <gtest/gtest.h>

#include "PegPattern.h"
#include "Score.h"
#include "utils.h"

using namespace MasterMind;

TEST(Score, OneBlack) {
  PegPattern entered(Peg::Black, Peg::Red, Peg::Yellow, Peg::Red);
  Score score(Peg::Black, Peg::Blue, Peg::Green, Peg::Orange);
  std::vector<KeyPeg> expectedResult = {KeyPeg::Black, KeyPeg::Missed,
                                        KeyPeg::Missed, KeyPeg::Missed};
  score.hit(entered);
  auto actualResult = score.getResult();
  EXPECT_EQ(expectedResult, actualResult);
}

TEST(Score, OneWhite) {
  PegPattern entered(Peg::Red, Peg::Green, Peg::Yellow, Peg::Green);
  Score score(Peg::Black, Peg::Blue, Peg::Red, Peg::Orange);

  std::vector<KeyPeg> expected = {KeyPeg::White, KeyPeg::Missed, KeyPeg::Missed,
                                  KeyPeg::Missed};
  score.hit(entered);
  auto actualResult = score.getResult();
  EXPECT_EQ(expected, actualResult);
}

TEST(Score, OneWhiteOneBlack) {
  PegPattern entered(Peg::Red, Peg::Green, Peg::Red, Peg::Black);
  Score score(Peg::Black, Peg::Blue, Peg::Red, Peg::Orange);

  std::vector<KeyPeg> expected = {KeyPeg::Black, KeyPeg::White, KeyPeg::Missed,
                                  KeyPeg::Missed};
  score.hit(entered);
  auto actualResult = score.getResult();
  EXPECT_EQ(expected, actualResult);
}

TEST(Score, TwoWhiteTwoBlack) {
  PegPattern entered(Peg::Black, Peg::Orange, Peg::Green, Peg::Red);
  Score score(Peg::Black, Peg::Red, Peg::Green, Peg::Orange);

  std::vector<KeyPeg> expected = {KeyPeg::Black, KeyPeg::Black, KeyPeg::White,
                                  KeyPeg::White};
  score.hit(entered);
  auto actualResult = score.getResult();
  EXPECT_EQ(expected, actualResult);
}
