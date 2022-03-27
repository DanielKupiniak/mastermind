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
  /**
   * @brief prints result in human readable format
   *
   * @param result
   * @return std::string
   */
  std::string printRow(const Result &result);

  /**
   * @brief convert input from console to PegPattern
   *
   * @param input
   * @return PegPattern
   */

  PegPattern translateToPegPattern(const std::vector<std::string> input);
  /**
   * @brief checks if input provided from console have valid chars
   *
   * @param input
   * @return true
   * @return false
   */
  bool validateInput(const std::vector<std::string> input);

  /**
   * @brief evaluate result to finish game
   *
   * @param result
   * @return true
   * @return false
   */
  bool youAreTheWinner(const Result &result);

  /**
   * @brief prints PegPattern in human readable format
   *
   * @param pattern
   * @return std::string
   */
  std::string printPegPattern(const PegPattern &pattern);
};
}  // namespace MasterMind