#pragma GCC optimize(1)
#pragma GCC optimize(2)
#pragma GCC optimize(3, "Ofast", "inline")
#include <bits/stdc++.h>
#define int long long
using namespace std;
constexpr int INF = 0x7fffffff;
void solve() {
    int n, m; cin >> n >> m;
    priority_queue<pair<int, int>> pq[n];
    for (int i{}; i < n; ++ i)
        for (int j{}; j < m; ++ j) {
            int x; cin >> x;
            pq[i].push({x, n});
        }
    for (int k{}; k < m; ++ k) {
        vector<pair<int, int>> a;
        for (int i{}; i < n; ++ i) {
            auto [x, id] = pq.top();
        }
        sort(a.begin(), a.end());
    }
    return;
}
signed main() {
    cin.tie(0) -> sync_with_stdio(0);
    int _ = 1; //cin >> _;
    while(_ --) solve();
    return 0;
}