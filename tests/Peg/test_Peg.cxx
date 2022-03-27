#include <gtest/gtest.h>

#include "Peg.h"
#include "Score.h"
#include "utils.h"

using namespace MasterMind;

TEST(Peg, UniquePeg) {
  CodePeg unique(Peg::Red, Peg::Black, Peg::Orange, Peg::Green);
  CodePeg notUnique(Peg::Red, Peg::Red, Peg::Orange, Peg::Green);

  EXPECT_TRUE(unique.isUnique());
  EXPECT_FALSE(notUnique.isUnique());
}
