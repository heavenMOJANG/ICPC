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
        if (l + 1 == r) return make_pair(s[l], 1ll);
        int mid1 = (2 * l + r) / 3, mid2 = (l + 2 * r) / 3;
        auto [val1, cnt1] = self(self, l, mid1);
        auto [val2, cnt2] = self(self, mid1, mid2);
        auto [val3, cnt3] = self(self, mid2, r);
        if (val1 == val2 && val2 == val3) return make_pair(val1, cnt1 + cnt2 + cnt3 - max({cnt1, cnt2, cnt3}));
        else if (val1 == val2) return make_pair(val1, min(cnt1, cnt2));
        else if (val1 == val3) return make_pair(val1, min(cnt1, cnt3));
        else if (val2 == val3) return make_pair(val2, min(cnt2, cnt3));
    };
    int ans = dfs(dfs, 0, pow(3, n)).first;
    cout << ans << "\n";
    return;
}
signed main() {
    cin.tie(0) -> sync_with_stdio(0);
    int _ = 1; //cin >> _;
    while(_ --) solve();
    return 0;
}