#pragma GCC optimize(1)
#pragma GCC optimize(2)
#pragma GCC optimize(3, "Ofast", "inline")
#include <bits/stdc++.h>
#define int long long
using namespace std;
constexpr int INF = 0x7fffffff;
struct Node {
    int x, y;
    bool operator < (const Node &rhs) const {
        int dx = x % 3, dy = y % 3;
        int rdx = rhs.x % 3, rdy = rhs.y % 3;
        int d{}, rhd{};
        if (dx == 1 && dy == 1) d = x + y;
        if (dx == 1 && dy == 2) d = x + y + 1;
        return (x + y) == (rhs.x + rhs.y) ? x > rhs.x : (x + y) > (rhs.x + rhs.y);
    }
};
void solve() {
    int n; cin >> n;
    vector<int> t(n + 1);
    for (int i = 1; i <= n; ++ i) cin >> t[i];
    int d = ceil(sqrt(n));
    priority_queue<Node> pq0;
    int sx = 1, sy = 1;
    for (int i = 0; i < d; ++ i)
        for (int j = 0; j < d; ++ j)
            pq0.push({sx + i * 3, sy + j * 3});
    priority_queue<Node> pq1;
    for (int i = 1; i <= n; ++ i) {
        if (t[i] == 0) {
            auto [x, y] = pq0.top(); pq0.pop();
            cout << x << " " << y << "\n";
            pq1.push({x + 1, y});
            pq1.push({x, y + 1});
            pq1.push({x + 1, y + 1});
        } else {
            if (pq1.empty()) {
                auto [x, y] = pq0.top(); pq0.pop();
                cout << x << " " << y << "\n";
                pq1.push({x + 1, y});
                pq1.push({x, y + 1});
                pq1.push({x + 1, y + 1});
            } else {
                auto [x, y] = pq1.top(); pq1.pop();
                cout << x << " " << y << "\n";
            }
        }
    }
    return;
}
signed main() {
    cin.tie(0) -> sync_with_stdio(0);
    int _ = 1; cin >> _;
    while(_ --) solve();
    return 0;
}