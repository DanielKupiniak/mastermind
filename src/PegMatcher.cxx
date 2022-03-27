#include "PegMatcher.h"

#include <algorithm>
#include <set>

namespace MasterMind {
PegMatcher::PegMatcher(Peg c0, Peg c1, Peg c2, Peg c3)
    : mExpected{c0, c1, c2, c3} {}
void PegMatcher::run(PegPattern& givenPeg) {
  mResult.clear();

  auto matches = matchedPegs(givenPeg);

  calculateResult(matches, givenPeg);

  sortResult();
}
PegMatcher::PegMatcher(const PegPattern& secret) : mExpected(secret) {}

std::set<Pos> PegMatcher::matchedPegs(const PegPattern& givenPeg) {
  std::set<Pos> matches;
  for (auto& e : givenPeg.getPegSeq()) {
    auto pos = mExpected.find(e.first);
    if (pos != Pos::None) {
      matches.insert(pos);
    }
  }
  return matches;
}

void PegMatcher::calculateResult(const std::set<Pos>& matches,
                                 const PegPattern& givenPeg) {
  for (auto& e : matches) {
    if (givenPeg.at(e) == mExpected.at(e)) {
      mResult.push_back(KeyPeg::Black);

    } else {
      mResult.push_back(KeyPeg::White);
    }
  }
}

void PegMatcher::sortResult() {
  auto fillMissed = mExpected.size() - mResult.size();
  for (size_t i = 0; i < fillMissed; i++) {
    mResult.push_back(KeyPeg::Missed);
  }
  std::sort(mResult.begin(), mResult.end(), std::less<KeyPeg>());
}

Result PegMatcher::getResult() const { return mResult; }
}  // namespace MasterMind