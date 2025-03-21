#pragma GCC optimize(1)
#pragma GCC optimize(2)
#pragma GCC optimize(3, "Ofast", "inline")
#include <bits/stdc++.h>
#define int long long
using namespace std;
constexpr int INF = 0x7fffffff;
struct Query {
    int l, r, id;
    bool operator < (const Query& q) const { return r < q.r; }
};
void solve() {
    int n; cin >> n;
    vector<int> a(n + 1), f0(n + 1, 0);
    map<int, vector<int>> mp;
    for (int i = 1; i <= n; ++ i) {
        cin >> a[i];
        mp[a[i]].emplace_back(i);
        if (a[i] == 0) f0[i] ++;
        f0[i] += f0[i - 1];
    }
    int ans{};
    for (auto [x, v]: mp) {
        for (int i = 1; i < v.size(); ++ i) {
            if (f0[v[i] - 1] - f0[v[0]]) {
                break;
            }
        }
    }
    cout << ans << "\n";
    return;
}
signed main() {
    cin.tie(0) -> sync_with_stdio(0);
    int _ = 1; cin >> _;
    while(_ --) solve();
    return 0;
}