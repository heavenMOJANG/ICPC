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
    priority_queue<pii, vector<pii>, greater<pii>> pq[w + 1];
    vector<int> tim(n + 1, INF);
    int tot{};
    for (int i = 1; i <= n; ++ i) {
        int x, y; cin >> x >> y;
        pq[x].push({y, i});
        if (pq[x].size() == 1) tot ++;
    }
    while (tot == w) {
        int maxn{};
        for (int i = 1; i <= n; ++ i) maxn = max(maxn, pq[i].top().first);
        for (int i = 1; i <= n; ++ i) {
            tim[pq[i].top().second] = maxn;
            pq[i].pop();/*
            if (pq[i].empty()) tot --;*/
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