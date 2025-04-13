#pragma GCC optimize(1)
#pragma GCC optimize(2)
#pragma GCC optimize(3, "Ofast", "inline")
#include <bits/stdc++.h>
#define int long long
#define ai3 array<int, 3>
using namespace std;
constexpr int INF = 0x7fffffff;
void solve() {
    int n; cin >> n;
    int x = 1, y = 1, d = 2;
    vector<array<int, 2>> ans(n);
    priority_queue<ai3, vector<ai3>, greater<ai3>> pq;
    for (int i = 0; i < n; ++ i) {
        int t; cin >> t;
        if (t && !pq.empty() && pq.top()[0] < d) {
            auto [_d, _x, _y] = pq.top(); pq.pop();
            ans[i] = {_x, _y};
        } else {
            ans[i] = {x, y};
            pq.push({x + y + 1, x + 1, y});
            pq.push({x + y + 1, x, y + 1});
            pq.push({x + y + 4, x + 1, y + 1});
            if (y == 1) swap(x, y), y += 3;
            else x += 3, y -= 3;
            d = x + y;
        }
    }
    for (int i = 0; i < n; ++ i) cout << ans[i][0] << " " << ans[i][1] << "\n";
    return;
}
signed main() {
    cin.tie(0) -> sync_with_stdio(0);
    int _ = 1; cin >> _;
    while(_ --) solve();
    return 0;
}