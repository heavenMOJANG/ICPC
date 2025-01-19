#pragma GCC optimize(1)
#pragma GCC optimize(2)
#pragma GCC optimize(3, "Ofast", "inline")
#include <bits/stdc++.h>
#define int long long
using namespace std;
constexpr int INF = 0x7fffffff;
void solve() {
    int n, m; cin >> n >> m;
    vector<int> x(n + 1), a(n + 1, 0);
    priority_queue<pair<int, int>> pq;
    for (int i = 0; i < m; ++ i) cin >> x[i];
    for (int i = 0; i < m; ++ i) cin >> a[x[i]], pq.push({x[i], a[x[i]]});
    int ans{};
    for (int i = n; i >= 1; -- i) {
        if (!a[i]) {
            if (pq.empty()) { cout << "-1\n"; return; }
            auto [p, w] = pq.top(); pq.pop();
            ans += i - p;
            w --;
            if (!w) a[p] = 0;
            else pq.push({p, w});
        } else {
            while (!pq.empty() && pq.top().first >= i) st.pop();
        }
    }
    cout << ans << "\n";
    return;
}
signed main() {
    cin.tie(0) -> sync_with_stdio(0);
    int _ = 1; //cin >> _;
    while(_ --) solve();
    return 0;
}