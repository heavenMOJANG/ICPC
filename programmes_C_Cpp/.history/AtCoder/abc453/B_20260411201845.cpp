#pragma GCC optimize(3, "Ofast", "inline")
#include <bits/stdc++.h>
#define int long long
using namespace std;
constexpr int INF = 0x7fffffff;
void solve() {
  int T, X; cin >> T >> X;
  vector<int> A(T + 1);
  for (auto &&x : A) cin >> x;
  int P = A[0];
  cout << "0 " << P << "\n";
  for (int i = 1; i <= T; ++i)
    if (abs(A[i] - P) >= X) {
      cout << i << " " << A[i] << "\n";
      P = A[i];
    }
  return;
}
signed main() {
  cin.tie(nullptr)->sync_with_stdio(false);
  int _ = 1; // cin >> _;
  while (_--)
    solve();
  return 0;
}