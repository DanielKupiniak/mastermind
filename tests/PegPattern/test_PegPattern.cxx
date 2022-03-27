#include <gtest/gtest.h>

#include "PegPattern.h"
#include "Score.h"
#include "utils.h"

using namespace MasterMind;

TEST(PegPattern, UniquePeg) {
  PegPattern unique(Peg::Red, Peg::Black, Peg::Orange, Peg::Green);
  PegPattern notUnique(Peg::Red, Peg::Red, Peg::Orange, Peg::Green);

  EXPECT_TRUE(unique.isUnique());
  EXPECT_FALSE(notUnique.isUnique());
}

TEST(PegPattern, findPeg) {
  PegPattern unique(Peg::Red, Peg::Black, Peg::Orange, Peg::Green);
}
