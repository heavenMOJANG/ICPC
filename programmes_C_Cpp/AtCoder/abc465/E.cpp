#pragma GCC optimize(3, "Ofast", "inline")
#include <bits/stdc++.h>
#define int long long
using namespace std;
constexpr int INF = 0x7fffffff;
constexpr int MOD = 998244353;
void solve() {
    string S; cin >> S;
    int N{(int)S.size()};
    int dp[505][3][2][1 << 10];
    memset(dp, -1ll, sizeof(dp));
    auto dfs = [&](auto& self, int pos, int limit, int lead, int m3, int h3, int mask) {
        if (pos == N) {
            if (lead) return 0ll;
            int res{(m3 == 0) + h3 + (popcount(static_cast<unsigned>(mask)) == 3)};
            return res == 1 ? 1ll : 0ll;
        }
        if (!limit && !lead && dp[pos][m3][h3][mask] != -1ll) return dp[pos][m3][h3][mask];
        int can{limit ? (S[pos] - '0') : 9ll}, res{};
        for (int d{}; d <= can; ++ d) {
            bool nlimit{limit && (d == can)};
            bool nlead{lead && (d == 0)};
            int nm3{(m3 + d) % 3};
            bool nh3{h3 || (d == 3)};
            int nmask{nlead ? 0ll : (mask | (1ll << d))};
            res += self(self, pos + 1, nlimit, nlead, nm3, nh3, nmask);
            if (res >= MOD) res -= MOD;
        }
        if (!limit && !lead) dp[pos][m3][h3][mask] = res;
        return res;
    };
    cout << dfs(dfs, 0, 1, 1, 0, 0, 0) << "\n";
    return;
}
signed main() {
    cin.tie(nullptr) -> sync_with_stdio(false);
    int _ = 1; //cin >> _;
    while(_ --) solve();
    return 0;
}