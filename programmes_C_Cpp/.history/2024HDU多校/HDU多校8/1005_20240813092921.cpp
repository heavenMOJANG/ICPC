#pragma GCC optimize(1)
#pragma GCC optimize(2)
#pragma GCC optimize(3,"Ofast","inline")
#include<bits/stdc++.h>
#define int long long
using namespace std;
constexpr int INF = 0x7fffffff;
void solve() {
    int l, r, k; cin >> l >> r >> k;
    map<int, map<int, int>> mp;
    auto dfs = [&](auto self, int len, int k) {
        if (len <= 0 || k < 0) return 0;
        if (mp[len].count(k)) return mp[len][k];
        if (len == 1) return 1;
        int l, r;
        if (len & 1) {
            l = len / 2 - 1;
            r = len / 2;
        } else {
            l = len / 2;
            r = len / 2;
        }
        return mp[len][k] = dfs(self, l, k - 1) + dfs(self, r, k) + 1;
    };
    if (__lg(r - l + 1) < k) cout << r - l + 1 << "\n";
    else cout << dfs(dfs, r - l + 1, k);
}
signed main() {
    cin.tie(0) -> sync_with_stdio(0);
    int _ = 1; cin >> _;
    while(_ --) solve();
    return 0;
}