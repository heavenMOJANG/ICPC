#pragma GCC optimize(3, "Ofast", "inline")
#include <bits/stdc++.h>
#define int long long
using namespace std;
constexpr int INF = 0x7fffffff;
constexpr int MOD = 998244353;
void solve() {
    int N, M; cin >> N >> M;
    vector<int> fac(M + 1, 1);
    for (int i = 1; i <= M; ++ i) fac[i] = fac[i - 1] * 2 % MOD;
    vector<vector<int>> seg(N);
    for (int i{}; i < M; ++ i) {
        int x, y; cin >> x >> y;
        seg[y - 1].emplace_back(x);
    }
    vector<int> ans(N, 0), pre(N, 0);
    ans[0] = pre[0] = 1;
    for (int r = 1; r < N; ++ r) {
        auto v = seg[r];
        sort(v.begin(), v.end());
        int m = v.size(), tmp{};
        for (int i{}; i < m; ++ i) {
            int l = v[i], k = fac[m - 1 - i], sum = pre[r - 1];
            if (l >= 2) (sum += MOD - pre[l - 2]) %= MOD;
            (tmp += k * sum % MOD) %= MOD;
        }
        pre[r] = (pre[r - 1] + (ans[r] = tmp)) % MOD;
    }
    
    cout << ans[N - 1] % MOD << "\n";
    return;
}
signed main() {
    cin.tie(nullptr) -> sync_with_stdio(false);
    int _ = 1; //cin >> _;
    while(_ --) solve();
    return 0;
}