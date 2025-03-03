#pragma GCC optimize(1)
#pragma GCC optimize(2)
#pragma GCC optimize(3, "Ofast", "inline")
#include <bits/stdc++.h>
#define int long long
using namespace std;
constexpr int INF = 0x7fffffff;
void solve() {
    int a, b; cin >> a >> b;
    int ans{};
    auto dfs = [&](auto && self, int a, int b, int step) {
        if (step == 15) return;
        if (!a || !b) { ans = step + 1; return; }
        int g = __gcd(a, b);
        self(self, a - g, b, step + 1);
        if (a > g) self(self, a, b - g, step + 1);
    };
    ans = 15;
    dfs(dfs, a, b, 0);
    return;
}
signed main() {
    cin.tie(0) -> sync_with_stdio(0);
    int _ = 1; cin >> _;
    while(_ --) solve();
    return 0;
}