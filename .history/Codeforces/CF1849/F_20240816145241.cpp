#pragma GCC optimize(1)
#pragma GCC optimize(2)
#pragma GCC optimize(3,"Ofast","inline")
#include<bits/stdc++.h>
#define int long long
using namespace std;
constexpr int INF = 0x7fffffff;
void solve() {
    int n;
    vector<int> a(n + 1);
    for (int i = 0; i < n; ++ i) cin >> a[i], a[i] += a[i - 1];
    map<int, vector<pair<int, int>>> mp;
    for (int r = 1; r <= n; ++ r)
        for (int l = 1; l <= r + 1; ++ l) mp[a[l - 1]+ a[r]].emplace_back(l, r);
    int ans = 0;
    for (auto & [x, v] : mp) {
        int minn = INF;
        for (auto [l, r] : v) {
            int tmp = max(0ll, r - l);
            tmp = min(tmp, minn - l + r - 2);
            ans += tmp;
            minn = min(minn, tmp + l - r);

        }
    }
}
signed main() {
    cin.tie(0) -> sync_with_stdio(0);
    int _ = 1; //cin >> _;
    while(_ --) solve();
    return 0;
}