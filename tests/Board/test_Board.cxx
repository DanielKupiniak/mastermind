#include <gtest/gtest.h>

#include <iterator>
#include <string>
#include <vector>

#include "Board.h"
#include "PegPattern.h"
#include "utils.h"
using namespace MasterMind;

TEST(Board, PrintScore) {
  Result result = {KeyPeg::White, KeyPeg::Black, KeyPeg::Missed, KeyPeg::White};
  Board board;

  std::string expectedRow = "WBXW";
  EXPECT_EQ(expectedRow, board.printRow(result));
}

TEST(Board, translateToPegPattern) {
  PegPattern expected(Peg::Red, Peg::Black, Peg::Orange, Peg::Green);
  Board board;

  std::vector<std::string> actualRow = {"1", "4", "5", "2"};
  EXPECT_EQ(expected.getPegSeq(),
            board.translateToPegPattern(actualRow).getPegSeq());
}

TEST(Board, youAreTheWinner) {
  Board board;
  Result result = {KeyPeg::Black, KeyPeg::Black, KeyPeg::Black, KeyPeg::Black};
  bool allBlacks = board.youAreTheWinner(result);
  EXPECT_TRUE(allBlacks);

  result = {KeyPeg::Black, KeyPeg::Black, KeyPeg::Black, KeyPeg::White};
  allBlacks = board.youAreTheWinner(result);
  EXPECT_FALSE(allBlacks);
}

TEST(Board, printPegPattern) {
  Board board;
  PegPattern expected(Peg::Red, Peg::Black, Peg::Orange, Peg::Green);
  EXPECT_EQ("1452", board.printPegPattern(expected));
}
