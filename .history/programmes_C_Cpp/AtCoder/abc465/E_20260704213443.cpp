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
            int res{(m3 == 0) + h3 + popcount(static_cast<int>(mask)) == 3};
            return res == 1ll ? 1ll : 0ll;

        }
    };
    return;
}
signed main() {
    cin.tie(nullptr) -> sync_with_stdio(false);
    int _ = 1; //cin >> _;
    while(_ --) solve();
    return 0;
}