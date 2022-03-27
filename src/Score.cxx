#include "Score.h"

#include <algorithm>
#include <set>

namespace MasterMind {
Score::Score(Peg c0, Peg c1, Peg c2, Peg c3) : mExpected{c0, c1, c2, c3} {}
void Score::hit(PegPattern& codePeg) {
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
std::vector<Result> Score::getResult() const { return mResult; }
}  // namespace MasterMind