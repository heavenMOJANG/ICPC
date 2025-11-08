#pragma GCC optimize(3, "Ofast", "inline")
#include <bits/stdc++.h>
#define int long long
using namespace std;
constexpr int INF = 0x7fffffff;
struct Node {
    int a, b, c, id;
    bool operator < (const Node &t) const { return a < t.a; }
};
void solve() {
    int n, k; cin >> n >> k;
    vector<Node> a(n);
    queue<int> q;
    for (int i{}; i < n; ++ i) cin >> a[i].a >> a[i].b >> a[i].c, a[i].id = i, q.push(i);
    sort(a.begin(), a.end());
    priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;
    int tot{}, tim{};
    vector<int> ans(n);
    while (!q.empty()) {
        while (!pq.empty() && tot + a[q.front()].c > k) {
            tim = pq.top().first;
            tot -= pq.top().second;
            pq.pop();
        }
        int e = max(a[q.front()].a, tim);
        ans[a[q.front()].id] = e;
        tot += a[q.front()].c;
        pq.push({e + a[q.front()].b, a[q.front()].c});
        q.pop();
    }
    for (int i{}; i < n; ++ i) cout << ans[i] << "\n";
    return;
}
signed main() {
    cin.tie(nullptr) -> sync_with_stdio(false);
    int _ = 1; //cin >> _;
    while(_ --) solve();
    return 0;
}