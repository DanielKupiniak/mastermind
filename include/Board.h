#pragma once

#include <map>
#include <string>
#include <vector>

#include "PegPattern.h"
#include "utils.h"
namespace MasterMind {

class Board {
 private:
  std::map<KeyPeg, std::string> mKeyPeg = std::map<KeyPeg, std::string>{
      {KeyPeg::Black, "B"}, {KeyPeg::White, "W"}, {KeyPeg::Missed, "X"}};

  std::map<std::string, Peg> mPeg = std::map<std::string, Peg>{
      {"1", Peg::Red},   {"2", Peg::Green},  {"3", Peg::Purple},
      {"4", Peg::Black}, {"5", Peg::Orange}, {"6", Peg::Yellow}};

 public:
  std::string printRow(const Result &result);
  PegPattern translateToPegPattern(const std::vector<std::string> input);
  bool validateInput(const std::vector<std::string> input);
  bool youAreTheWinner(const Result &result);
};
}  // namespace MasterMind