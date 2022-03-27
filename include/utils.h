#pragma once
#include <utility>
#include <vector>

namespace MasterMind {
enum class Peg { Red, Green, Purple, Black, Orange, Yellow };
enum class Pos { C0, C1, C2, C3, None };
enum class KeyPeg { Black, White, Missed };

using CodePeg = std::pair<Peg, Pos>;
using Result = std::vector<KeyPeg>;
using CodePegSeq = std::vector<CodePeg>;
}  // namespace MasterMind
