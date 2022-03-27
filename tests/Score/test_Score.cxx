#include <gtest/gtest.h>

#include "PegPattern.h"
#include "Score.h"
#include "utils.h"

using namespace MasterMind;

TEST(Score, OneBlack) {
  PegPattern entered(Peg::Black, Peg::Red, Peg::Yellow, Peg::Red);
  Score score(Peg::Black, Peg::Blue, Peg::Green, Peg::Orange);
  Result expectedResult = {KeyPeg::Black, KeyPeg::Missed, KeyPeg::Missed,
                           KeyPeg::Missed};
  score.hit(entered);
  auto actualResult = score.getResult();
  EXPECT_EQ(expectedResult, actualResult);
}

TEST(Score, OneWhite) {
  PegPattern entered(Peg::Red, Peg::Green, Peg::Yellow, Peg::Green);
  Score score(Peg::Black, Peg::Blue, Peg::Red, Peg::Orange);

  Result expected = {KeyPeg::White, KeyPeg::Missed, KeyPeg::Missed,
                     KeyPeg::Missed};
  score.hit(entered);
  auto actualResult = score.getResult();
  EXPECT_EQ(expected, actualResult);
}

TEST(Score, OneWhiteOneBlack) {
  PegPattern entered(Peg::Red, Peg::Green, Peg::Red, Peg::Black);
  Score score(Peg::Black, Peg::Blue, Peg::Red, Peg::Orange);

  Result expected = {KeyPeg::Black, KeyPeg::White, KeyPeg::Missed,
                     KeyPeg::Missed};
  score.hit(entered);
  auto actualResult = score.getResult();
  EXPECT_EQ(expected, actualResult);
}

TEST(Score, TwoWhiteTwoBlack) {
  PegPattern entered(Peg::Black, Peg::Orange, Peg::Green, Peg::Red);
  Score score(Peg::Black, Peg::Red, Peg::Green, Peg::Orange);

  Result expected = {KeyPeg::Black, KeyPeg::Black, KeyPeg::White,
                     KeyPeg::White};
  score.hit(entered);
  auto actualResult = score.getResult();
  EXPECT_EQ(expected, actualResult);
}

TEST(Score, FourBlack) {
  PegPattern entered(Peg::Black, Peg::Orange, Peg::Green, Peg::Red);
  Score score(Peg::Black, Peg::Orange, Peg::Green, Peg::Red);

  Result expected = {KeyPeg::Black, KeyPeg::Black, KeyPeg::Black,
                     KeyPeg::Black};
  score.hit(entered);
  auto actualResult = score.getResult();
  EXPECT_EQ(expected, actualResult);
}

TEST(Score, FourWhitek) {
  PegPattern entered(Peg::Orange, Peg::Black, Peg::Red, Peg::Green);
  Score score(Peg::Black, Peg::Orange, Peg::Green, Peg::Red);

  Result expected = {KeyPeg::White, KeyPeg::White, KeyPeg::White,
                     KeyPeg::White};
  score.hit(entered);
  auto actualResult = score.getResult();
  EXPECT_EQ(expected, actualResult);
}

TEST(Score, FourNone) {
  PegPattern entered(Peg::Orange, Peg::Orange, Peg::Green, Peg::Green);
  Score score(Peg::Yellow, Peg::Black, Peg::Blue, Peg::Red);

  Result expected = {KeyPeg::Missed, KeyPeg::Missed, KeyPeg::Missed,
                     KeyPeg::Missed};
  score.hit(entered);
  auto actualResult = score.getResult();
  EXPECT_EQ(expected, actualResult);
}
