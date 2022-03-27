#include "Board.h"

#include <algorithm>

namespace MasterMind {

std::string Board::printRow(const Result &result) {
  std::string row;
  for (auto &e : result) {
    row += mKeyPeg[e];
  }
  return row;
}

PegPattern Board::translateToPegPattern(const std::vector<std::string> input) {
  CodePegSeq pegs;
  std::vector<Pos> col = {Pos::C0, Pos::C1, Pos::C2, Pos::C3};
  auto pos = col.begin();
  for (auto &e : input) {
    pegs.push_back(std::make_pair(mPeg[e], *pos));
    pos++;
  }
  return PegPattern(pegs);
}

bool Board::validateInput(const std::vector<std::string> input) {
  for (auto &e : input) {
    if (mPeg.count(e) == 0) {
      return false;
    }
  }
  return true;
}

bool Board::youAreTheWinner(const Result &result) {
  return std::all_of(result.begin(), result.end(), [](const KeyPeg &keyPeg) {
    return keyPeg == KeyPeg::Black;
  });
}

}  // namespace MasterMind