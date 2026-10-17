#pragma GCC optimize(3, "Ofast", "inline")
#include <bits/stdc++.h>
#define int long long
using namespace std;
constexpr int INF = 0x7fffffff;
constexpr int MOD = 998244353;
void solve() {
    int N; cin >> N;
    if (N == 1) { cout << "1\n"; return; }
    vector<int> fac(100000, 1), p;
    for (int i{1}; i < 100000; ++ i) fac[i] = fac[i - 1] * i % MOD;
    for (int i{1}; i * i <= N; ++ i)
        if (N % i == 0) {
            if (i > 1) p.emplace_back(i);
            if (i * i != N && N / i > 1) p.emplace_back(N / i);
        }
    ranges::sort(p);
    int M = p.size(), ans{};
    auto dfs = [&](auto self, int idx, int cnt, int prod, int sum, int last) -> void {
        if (prod > last) {
            int s = (sum + prod) % MOD;
            int res1 = (fac[cnt + 1] + fac[cnt + 2]) % MOD * s % MOD;
            int res2 = fac[cnt + 2];
            (ans += res1 + res2) %= MOD;
        }
        for (int i{idx}; i < M; ++ i) {
            if (p[i] > prod / p[i]) break;
            if (prod % p[i] == 0)
                self(self, i + 1, cnt + 1, prod / p[i], (sum + p[i]) % MOD, p[i]);
        }
    };
    dfs(dfs, 0, 0, N, 0, 1);
    cout << ans << "\n";
    return;
}
signed main() {
    cin.tie(nullptr) -> sync_with_stdio(false);
    int _ = 1; //cin >> _;
    while(_ --) solve();
    return 0;
}