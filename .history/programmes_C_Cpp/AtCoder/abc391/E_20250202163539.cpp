#pragma GCC optimize(1)
#pragma GCC optimize(2)
#pragma GCC optimize(3, "Ofast", "inline")
#include <bits/stdc++.h>
#define int long long
using namespace std;
constexpr int INF = 0x7fffffff;
void solve() {
    int n; cin >> n;
    string s; cin >> s;
    auto dfs = [&](auto && self, int l, int r) {
        if (l + 1 == r) return make_pair(s[l], 1);
        int mid1 = (2 * l + r) / 3, mid2 = (l + 2 * r) / 3;
        auto [val1, cnt1] = dfs(self, l, mid1);


    };
    cout << ans << "\n";
    return;
}
signed main() {
    cin.tie(0) -> sync_with_stdio(0);
    int _ = 1; //cin >> _;
    while(_ --) solve();
    return 0;
}