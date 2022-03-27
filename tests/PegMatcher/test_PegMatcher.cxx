#include <gtest/gtest.h>

#include "PegMatcher.h"
#include "PegPattern.h"
#include "utils.h"

using namespace MasterMind;

TEST(PegMatcher, OneBlack) {
  PegPattern entered(Peg::Black, Peg::Red, Peg::Yellow, Peg::Red);
  PegMatcher pegMatcher(Peg::Black, Peg::Purple, Peg::Green, Peg::Orange);
  Result expectedResult = {KeyPeg::Black, KeyPeg::Missed, KeyPeg::Missed,
                           KeyPeg::Missed};
  pegMatcher.run(entered);
  auto actualResult = pegMatcher.getResult();
  EXPECT_EQ(expectedResult, actualResult);
}

TEST(PegMatcher, OneWhite) {
  PegPattern entered(Peg::Red, Peg::Green, Peg::Yellow, Peg::Green);
  PegMatcher pegMatcher(Peg::Black, Peg::Purple, Peg::Red, Peg::Orange);

  Result expected = {KeyPeg::White, KeyPeg::Missed, KeyPeg::Missed,
                     KeyPeg::Missed};
  pegMatcher.run(entered);
  auto actualResult = pegMatcher.getResult();
  EXPECT_EQ(expected, actualResult);
}

TEST(PegMatcher, OneWhiteOneBlack) {
  PegPattern entered(Peg::Red, Peg::Green, Peg::Red, Peg::Black);
  PegMatcher pegMatcher(Peg::Black, Peg::Purple, Peg::Red, Peg::Orange);

  Result expected = {KeyPeg::Black, KeyPeg::White, KeyPeg::Missed,
                     KeyPeg::Missed};
  pegMatcher.run(entered);
  auto actualResult = pegMatcher.getResult();
  EXPECT_EQ(expected, actualResult);
}

TEST(PegMatcher, TwoWhiteTwoBlack) {
  PegPattern entered(Peg::Black, Peg::Orange, Peg::Green, Peg::Red);
  PegMatcher pegMatcher(Peg::Black, Peg::Red, Peg::Green, Peg::Orange);

  Result expected = {KeyPeg::Black, KeyPeg::Black, KeyPeg::White,
                     KeyPeg::White};
  pegMatcher.run(entered);
  auto actualResult = pegMatcher.getResult();
  EXPECT_EQ(expected, actualResult);
}

TEST(PegMatcher, FourBlack) {
  PegPattern entered(Peg::Black, Peg::Orange, Peg::Green, Peg::Red);
  PegMatcher pegMatcher(Peg::Black, Peg::Orange, Peg::Green, Peg::Red);

  Result expected = {KeyPeg::Black, KeyPeg::Black, KeyPeg::Black,
                     KeyPeg::Black};
  pegMatcher.run(entered);
  auto actualResult = pegMatcher.getResult();
  EXPECT_EQ(expected, actualResult);
}

TEST(PegMatcher, FourWhitek) {
  PegPattern entered(Peg::Orange, Peg::Black, Peg::Red, Peg::Green);
  PegMatcher pegMatcher(Peg::Black, Peg::Orange, Peg::Green, Peg::Red);

  Result expected = {KeyPeg::White, KeyPeg::White, KeyPeg::White,
                     KeyPeg::White};
  pegMatcher.run(entered);
  auto actualResult = pegMatcher.getResult();
  EXPECT_EQ(expected, actualResult);
}

TEST(PegMatcher, FourNone) {
  PegPattern entered(Peg::Orange, Peg::Orange, Peg::Green, Peg::Green);
  PegMatcher pegMatcher(Peg::Yellow, Peg::Black, Peg::Purple, Peg::Red);

  Result expected = {KeyPeg::Missed, KeyPeg::Missed, KeyPeg::Missed,
                     KeyPeg::Missed};
  pegMatcher.run(entered);
  auto actualResult = pegMatcher.getResult();
  EXPECT_EQ(expected, actualResult);
}
