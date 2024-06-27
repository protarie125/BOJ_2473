#include <algorithm>
#include <bit>
#include <chrono>
#include <cmath>
#include <cstdint>
#include <deque>
#include <iomanip>
#include <iostream>
#include <limits>
#include <map>
#include <numeric>
#include <queue>
#include <ranges>
#include <set>
#include <sstream>
#include <stack>
#include <string>
#include <tuple>
#include <utility>
#include <vector>

using namespace std;

using ll = int64_t;
using vl = vector<ll>;

ll n;
vl A;

int main() {
  ios::sync_with_stdio(false);
  std::cin.tie(nullptr);

  cin >> n;
  A = vl(n);
  for (auto&& x : A) {
    cin >> x;
  }
  sort(A.begin(), A.end());

  auto ans = vl{A[0], A[1], A[2]};
  auto minval = abs(ans[0] + ans[1] + ans[2]);
  for (auto i = 0; i < n - 2; ++i) {
    auto b = i + 1;
    auto e = n - 1;
    while (b < e) {
      auto q = A[i] + A[b] + A[e];
      if (abs(q) < minval) {
        minval = abs(q);
        ans = vl{A[i], A[b], A[e]};
      }

      if (q < 0) {
        ++b;
      } else {
        --e;
      }
    }
  }

  cout << ans[0] << ' ' << ans[1] << ' ' << ans[2];

  return 0;
}