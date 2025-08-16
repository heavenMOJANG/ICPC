#pragma GCC optimize(3, "Ofast", "inline")
#include <bits/stdc++.h>
#define int long long
using namespace std;
constexpr int INF = 0x7fffffff;
void solve() {
    int n, m; cin >> n >> m;
    string s, t; cin >> s >> t;
    vector<int> d(n + 1, 0);
    while (m --) {
        int l, r; cin >> l >> r; l --, r --;
        d[l] ^= 1;
        if (r + 1 < n) d[r + 1] ^= 1;
    }
    int cur{};
    for (int i{}; i < n; ++ i) {
        cur ^= d[i];
        if (cur) s[i] = t[i];
    }
    cout << s << "\n";
    return;
}
signed main() {
    cin.tie(nullptr) -> sync_with_stdio(false);
    int _ = 1; //cin >> _;
    while(_ --) solve();
    return 0;
}