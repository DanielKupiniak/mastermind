#include <gtest/gtest.h>

#include "PegMatcher.h"
#include "PegPattern.h"
#include "utils.h"

using namespace MasterMind;

TEST(PegPattern, findPeg) {
  PegPattern actual(Peg::Red, Peg::Black, Peg::Orange, Peg::Green);
  EXPECT_EQ(Pos::C0, actual.find(Peg::Red));
  EXPECT_EQ(Pos::C1, actual.find(Peg::Black));
  EXPECT_EQ(Pos::C2, actual.find(Peg::Orange));
  EXPECT_EQ(Pos::C3, actual.find(Peg::Green));
  EXPECT_EQ(Pos::None, actual.find(Peg::Purple));
  EXPECT_EQ(Pos::None, actual.find(Peg::Yellow));
}

TEST(PegPattern, ColorAtPosition) {
  PegPattern actual(Peg::Red, Peg::Black, Peg::Orange, Peg::Orange);
  EXPECT_EQ(Peg::Red, actual.at(Pos::C0));
  EXPECT_EQ(Peg::Black, actual.at(Pos::C1));
  EXPECT_EQ(Peg::Orange, actual.at(Pos::C2));
  EXPECT_EQ(Peg::Orange, actual.at(Pos::C3));
}