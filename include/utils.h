#pragma once
#include <utility>
namespace MasterMind {
enum class Peg { Red, Green, Blue, Black, Orange, Yellow };
enum class Pos { C0, C1, C2, C3, None };
enum class KeyPeg { Black, White, Missed };

using CodePeg = std::pair<Peg, Pos>;

}  // namespace MasterMind
