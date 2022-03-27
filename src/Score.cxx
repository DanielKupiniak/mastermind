#include "Score.h"

#include <algorithm>
#include <set>

namespace MasterMind {
Score::Score(Peg c0, Peg c1, Peg c2, Peg c3) : mExpected{c0, c1, c2, c3} {}
void Score::hit(PegPattern& codePeg) {
  mResult.clear();
  std::set<Pos> count;
  for (auto& e : codePeg.getCodePeg()) {
    auto pos = mExpected.match(e);
    if (pos != Pos::None) {
      count.insert(pos);
    }
  }
  for (auto& e : count) {
    if (codePeg.getCodePeg().at(static_cast<int>(e)).first ==
        mExpected.getCodePeg().at(static_cast<int>(e)).first) {
      mResult.push_back(KeyPeg::Black);

    } else {
      mResult.push_back(KeyPeg::White);
    }
  }
  int fill = 4 - mResult.size();
  for (int i = 0; i < fill; i++) {
    mResult.push_back(KeyPeg::Missed);
  }
  std::sort(mResult.begin(), mResult.end(), std::less<KeyPeg>());
}
std::vector<KeyPeg> Score::getResult() const { return mResult; }
}  // namespace MasterMind