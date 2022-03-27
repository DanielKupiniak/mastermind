#pragma once
#include <vector>

#include "utils.h"

namespace MasterMind {

class PegPattern {
 private:
  CodePegSeq mPegSeq;

 public:
  /**
   * @brief Construct a new Peg Pattern object
   *
   * @param c0
   * @param c1
   * @param c2
   * @param c3
   */
  PegPattern(const Peg& c0, const Peg& c1, const Peg& c2, const Peg& c3);
  /**
   * @brief Construct a new Peg Pattern object
   *
   * @param pegs
   */
  PegPattern(const CodePegSeq& pegs);

  /**
   * @brief returns Peg based on Pos
   *
   * @param pos
   * @return Peg
   */
  Peg at(const Pos& pos) const;
  /**
   * @brief return first occurence of Pos based on Peg
   *
   * @param cos
   * @return Pos
   */
  Pos find(const Peg& cos);
  /**
   * @brief returns size of PegPattern, in current implementation always 4
   *
   * @return size_t
   */
  size_t size() const;

  /**
   * @brief Get the PegSeq object
   *
   * @return CodePegSeq
   */
  CodePegSeq getPegSeq() const;
};

}  // namespace MasterMind