#include <gtest/gtest.h>

#include <algorithm>
#include <map>

#include "PegPattern.h"
#include "utils.h"

using namespace MasterMind;

class Board {
 private:
  std::map<KeyPeg, std::string> mKeyPeg = std::map<KeyPeg, std::string>{
      {KeyPeg::Black, "B"}, {KeyPeg::White, "W"}, {KeyPeg::Missed, "X"}};

  std::map<std::string, Peg> mPeg = std::map<std::string, Peg>{
      {"R", Peg::Red},   {"G", Peg::Green},  {"P", Peg::Purple},
      {"B", Peg::Black}, {"O", Peg::Orange}, {"Y", Peg::Yellow}};

 public:
  std::string printRow(const Result &result) {
    std::string row;
    for (auto &e : result) {
      row += mKeyPeg[e];
    }
    return row;
  }

  PegPattern translateToPegPattern(const std::vector<std::string> input) {
    CodePegSeq pegs;
    std::vector<Pos> col = {Pos::C0, Pos::C1, Pos::C2, Pos::C3};
    auto pos = col.begin();
    for (auto &e : input) {
      pegs.push_back(std::make_pair(mPeg[e], *pos));
      pos++;
    }
    return PegPattern(pegs);
  }
};

TEST(Board, PrintScore) {
  Result result = {KeyPeg::White, KeyPeg::Black, KeyPeg::Missed, KeyPeg::White};
  Board board;

  std::string expectedRow = "WBXW";
  EXPECT_EQ(expectedRow, board.printRow(result));
}

TEST(Board, translateToPegPattern) {
  PegPattern expected(Peg::Red, Peg::Black, Peg::Orange, Peg::Green);
  Board board;

  std::vector<std::string> actualRow = {"R", "B", "O", "G"};
  EXPECT_EQ(expected.getPegSeq(),
            board.translateToPegPattern(actualRow).getPegSeq());
}
