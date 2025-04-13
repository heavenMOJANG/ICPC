#pragma GCC optimize(1)
#pragma GCC optimize(2)
#pragma GCC optimize(3, "Ofast", "inline")
#include <bits/stdc++.h>
#define int long long
using namespace std;
constexpr int INF = 0x7fffffff;
void solve() {
    int n, m; cin >> n >> m;
    int maxx = LLONG_MIN, minx = LLONG_MAX;
    int maxy = LLONG_MIN, miny = LLONG_MAX;
    for (int i = 0; i < n; ++ i) {
        int x, y; cin >> x >> y;
        maxx = max(maxx, x + y), minx = min(minx, x + y);
        maxy = max(maxy, x - y), miny = min(miny, x - y);
    }
    priority_queue<int, vector<int>, greater<int>> pq;
    for (int i = 0; i < m; ++ i) {
        int x, y; cin >> x >> y;
        int dx = x + y, dy = x - y;
        pq.push(max({abs(dx - maxx), abs(dx - minx), abs(dy - maxy), abs(dy - miny)}));
    }
    cout << pq.top() << "\n";
    return;
}
signed main() {
    cin.tie(0) -> sync_with_stdio(0);
    int _ = 1; cin >> _;
    while(_ --) solve();
    return 0;
}