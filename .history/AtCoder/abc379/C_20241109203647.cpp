#pragma GCC optimize(1)
#pragma GCC optimize(2)
#pragma GCC optimize(3, "Ofast", "inline")
#include <bits/stdc++.h>
#define int long long
using namespace std;
constexpr int INF = 0x7fffffff;
void solve() {
    int n, m; cin >> n >> m;
    vector<int> x(m), a(m);
    priority_queue<pair<int, int>> pq;
    for (int i = 0; i < m; ++ i) cin >> x[i];
    for (int i = 0; i < m; ++ i) cin >> a[i], pq.push({x[i], a[i]});
    int ans{}, pos = n;
    while (!pq.empty()) {
        auto [p, w] = pq.top(); pq.pop();
        if (p >= pos) continue;
        
    }
    return;
}
signed main() {
    cin.tie(0) -> sync_with_stdio(0);
    int _ = 1; //cin >> _;
    while(_ --) solve();
    return 0;
}