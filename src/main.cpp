#include <iostream>
#include <vector>

#include "Board.h"
#include "PegPattern.h"
#include "Score.h"
using namespace MasterMind;

void printEnterLineInfo(const int attempt) {
  std::cout << attempt << ") Please enter your guess: " << std::endl;
}

void printWrongInputLength(std::string &line) {
  std::cout << "Provided Line " << line << " has wrong length " << std::endl;
}

std::vector<std::string> convertTovector(std::string &line) {
  std::vector<std::string> input;
  for (auto &c : line) {
    input.push_back(std::string(1, c));
  }
  return input;

  std::cout << "Provided Line " << line
            << " has wrong length. Repeat entry: " << std::endl;
}

PegPattern generateSecret() {
  std::vector<Peg> pegs = {Peg::Black, Peg::Orange, Peg::Red, Peg::Yellow};
  return std::move(PegPattern(pegs.at(0), pegs.at(1), pegs.at(2), pegs.at(3)));
}

int main(int, char **) {
  std::cout << "Welcome in mastermind game!" << std::endl;
  std::cout << "Rules:" << std::endl;
  std::cout << "\t1. Player can enter guess 10 times" << std::endl;
  std::cout << "\t2. Secret pegs are combination of four pegs" << std::endl;
  std::cout << "\t3. Secret pegs are unique and cant be empty" << std::endl;
  std::cout << "\t4. Allowed characters: 1, 2, 3, 4, 5, 6" << std::endl;
  std::cout << "\t6. If Codebreaker wins game message will print" << std::endl
            << std::endl;
  std::cout << "Lets start !!!" << std::endl;

  Board board;
  auto secret = generateSecret();
  Score score(secret);
  std::vector<std::string> pegs;
  bool isGuessed = false;
  for (int i = 0; (i < 10) && (false == isGuessed); i++) {
    std::string line;
    bool isOk = false;
    while (false == isOk) {
      printEnterLineInfo(i + 1);
      std::cin >> line;
      if (4 != line.size()) {
        printWrongInputLength(line);
      } else {
        pegs = convertTovector(line);
        isOk = board.validateInput(pegs);
        if (isOk) {
          auto guess = board.translateToPegPattern(pegs);
          score.hit(guess);
          auto result = score.getResult();
          std::cout << board.printRow(result) << std::endl;
          isGuessed = board.youAreTheWinner(result);
        } else {
          std::cout << "Unknown characters: " << line << std::endl;
        }
      }
    }
  }
  if (isGuessed) {
    std::cout << "You are the CodeBreaker!!!" << std::endl;
  } else {
    std::cout << "Maybe next time :(" << std::endl;
  }
}
