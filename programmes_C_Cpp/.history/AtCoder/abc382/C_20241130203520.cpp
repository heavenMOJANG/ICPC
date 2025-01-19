#pragma GCC optimize(1)
#pragma GCC optimize(2)
#pragma GCC optimize(3, "Ofast", "inline")
#include <bits/stdc++.h>
#define int long long
using namespace std;
constexpr int INF = 0x7fffffff;
void solve() {
    int n, m; cin >> n >> m;
    vector<int> a(n);
    vector<int> ans(m);
    priority_queue<pair<int, int>> pq;
    for (int i = 0; i < n; ++ i) cin >> a[i];
    for (int j = 0; j < m; ++ j) {
        int b; cin >> n;
        pq.push({b, j});
    }
    for (int i = 0; i < n; ++ i) {
        while (!pq.empty() && pq.top().first >= a[i]) {
            int p = pq.top().second;
            ans[p] = i + 1;
            pq.pop();
        }
    }
    for (int j = 0; j < m; ++ j) cout << ans[j] << "\n";
    return;
}
signed main() {
    cin.tie(0) -> sync_with_stdio(0);
    int _ = 1; //cin >> _;
    while(_ --) solve();
    return 0;
}