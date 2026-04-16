#pragma GCC optimize(3, "Ofast", "inline")
#include <bits/stdc++.h>
#define int long long
using namespace std;
constexpr int INF = 0x7fffffff;
void solve() {
  int N; cin >> N;
  string S; cin >> S;
  int p{}; 
  while (S[p] == 'o') p ++;
  for (int i = p; i < (int)S.size(); ++ i) cout << S[i];
  cout << "\n";
  return;
}
signed main() {
    cin.tie(nullptr) -> sync_with_stdio(false);
    int _ = 1; //cin >> _;
    while(_ --) solve();
    return 0;
}