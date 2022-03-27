#include <gtest/gtest.h>

#include <algorithm>
#include <functional>
#include <set>
#include <utility>

#include "Peg.h"
#include "utils.h"

using namespace MasterMind;

class Score {
 private:
  std::vector<Result> mResult;
  CodePeg mExpected;

 public:
  Score(Peg c0, Peg c1, Peg c2, Peg c3) : mExpected{c0, c1, c2, c3} {}
  void hit(CodePeg& codePeg) {
    mResult.clear();
    std::set<Pos> count;
    for (auto& e : codePeg.getCos()) {
      auto pos = mExpected.match(e);
      if (pos != Pos::None) {
        count.insert(pos);
      }
    }
    for (auto& e : count) {
      if (codePeg.getCos().at(static_cast<int>(e)).first ==
          mExpected.getCos().at(static_cast<int>(e)).first) {
        mResult.push_back(Result::Black);

      } else {
        mResult.push_back(Result::White);
      }
    }
    int fill = 4 - mResult.size();
    for (int i = 0; i < fill; i++) {
      mResult.push_back(Result::Missed);
    }
    std::sort(mResult.begin(), mResult.end(), std::less<Result>());
  }
  std::vector<Result> getResult() const { return mResult; }
};

TEST(MasterMind, UniquePeg) {
  CodePeg unique(Peg::Red, Peg::Black, Peg::Orange, Peg::Green);
  CodePeg notUnique(Peg::Red, Peg::Red, Peg::Orange, Peg::Green);

  EXPECT_TRUE(unique.isUnique());
  EXPECT_FALSE(notUnique.isUnique());
}

TEST(MasterMind, OneBlack) {
  CodePeg entered(Peg::Black, Peg::Red, Peg::Yellow, Peg::Red);
  Score score(Peg::Black, Peg::Blue, Peg::Green, Peg::Orange);
  std::vector<Result> expectedResult = {Result::Black, Result::Missed,
                                        Result::Missed, Result::Missed};
  score.hit(entered);
  auto actualResult = score.getResult();
  EXPECT_EQ(expectedResult, actualResult);
}

TEST(MasterMind, OneWhite) {
  CodePeg entered(Peg::Red, Peg::Green, Peg::Yellow, Peg::Green);
  Score score(Peg::Black, Peg::Blue, Peg::Red, Peg::Orange);

  std::vector<Result> expected = {Result::White, Result::Missed, Result::Missed,
                                  Result::Missed};
  score.hit(entered);
  auto actualResult = score.getResult();
  EXPECT_EQ(expected, actualResult);
}

TEST(MasterMind, OneWhiteOneBlack) {
  CodePeg entered(Peg::Red, Peg::Green, Peg::Red, Peg::Black);
  Score score(Peg::Black, Peg::Blue, Peg::Red, Peg::Orange);

  std::vector<Result> expected = {Result::Black, Result::White, Result::Missed,
                                  Result::Missed};
  score.hit(entered);
  auto actualResult = score.getResult();
  EXPECT_EQ(expected, actualResult);
}

TEST(MasterMind, TwoWhiteTwoBlack) {
  CodePeg entered(Peg::Black, Peg::Orange, Peg::Green, Peg::Red);
  Score score(Peg::Black, Peg::Red, Peg::Green, Peg::Orange);

  std::vector<Result> expected = {Result::Black, Result::Black, Result::White,
                                  Result::White};
  score.hit(entered);
  auto actualResult = score.getResult();
  EXPECT_EQ(expected, actualResult);
}
