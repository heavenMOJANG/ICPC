#pragma GCC optimize(3, "Ofast", "inline")
#include <bits/stdc++.h>
#define int long long
using namespace std;
constexpr int INF = 0x7fffffff;
constexpr int MAXN = 60;
constexpr int STATE[3][3] = {{1, 0, 0}, {1, 2, 0}, {1, 0, 0}};
constexpr int MATCH[3][3] = {{0,0,0}, {0,0,0}, {0,0, 1}};
void solve() {
    string S; cin >> S; int N = S.size();
    int K; cin >> K;
    array<array<int, MAXN + 10>, 3> dp;
    for (auto& r : dp) r.fill(INF);
    dp[0][30] = 0;
    int minn{60}, maxn{60};
    for (int i{1}; i <= N; ++ i) {
        array<array<int, MAXN + 10>, 3> ndp;
        for (auto& r : ndp) r.fill(INF);
        int f = (i >= 3 && S[i-3] == 'A' && S[i-2] == 'B' && S[i-1] == 'C') ? 1 : 0;
        char o{S[i - 1]};
        int idx = (o >= 'A' && o <= 'C') ? (o - 'A') : -1ll;

    }
    return;
}
signed main() {
    cin.tie(nullptr) -> sync_with_stdio(false);
    int _ = 1; //cin >> _;
    while(_ --) solve();
    return 0;
}
