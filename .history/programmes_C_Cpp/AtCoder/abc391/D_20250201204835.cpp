#pragma GCC optimize(1)
#pragma GCC optimize(2)
#pragma GCC optimize(3, "Ofast", "inline")
#include <bits/stdc++.h>
#define int long long
#define pii pair<int, int>
using namespace std;
constexpr int INF = 0x7fffffff;
void solve() {
    int n, w; cin >> n >> w;
    map<int, priority_queue<pii, vector<pii>, greater<pii>>> mp;
    vector<int> tim(n + 1, INF);
    for (int i = 0; i < n; ++ i) {
        int x, y; cin >> x >> y;
        mp[x].push({y, i + 1});
    }
    while (mp.size() == w) {
        int maxn{};
        for (auto [x, pq] : mp) maxn = max(maxn, pq.top().first);
        for (auto [x, pq] : mp) {
            cout << pq.top().second << ": " << x << "," << pq.top().first << "\n";
            tim[pq.top().second] = maxn;
            pq.pop();
            if (pq.empty()) mp.erase(x);
        }
    }
    int q; cin >> q;
    while (q --) {
        int t, a; cin >> t >> a;
        if (t >= tim[a]) cout << "No\n";
        else cout << "Yes\n";
    }
    return;
}
signed main() {
    cin.tie(0) -> sync_with_stdio(0);
    int _ = 1; //cin >> _;
    while(_ --) solve();
    return 0;
}