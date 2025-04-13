#pragma GCC optimize(1)
#pragma GCC optimize(2)
#pragma GCC optimize(3, "Ofast", "inline")
#include <bits/stdc++.h>
#define int long long
using namespace std;
constexpr int INF = 0x7fffffff;
int check(int x0, int y0, int x1, int y1) {
    int rx0 = x0 % 3, ry0 = y0 % 3;
    int rx1 = x1 % 3, ry1 = y1 % 3;
    int d0{}, d1{};
    if (rx0 == 1 && ry0 == 1) d0 = x0 + y0;
    if (rx0 == 1 && ry0 == 2) d0 = x0 + y0 + 1;
    if (rx0 == 2 && ry0 == 1) d0 = x0 + y0 + 1;
    if (rx0 == 2 && ry0 == 2) d0 = x0 + y0 + 4;
    if (rx1 == 1 && ry1 == 1) d1 = x1 + y1;
    if (rx1 == 1 && ry1 == 2) d1 = x1 + y1 + 1;
    if (rx1 == 2 && ry1 == 1) d1 = x1 + y1 + 1;
    if (rx1 == 2 && ry1 == 2) d1 = x1 + y1 + 4;
    return d0 == d1 ? x0 == x1 ? y0 > y1 : x0 > x1 : d0 > d1;
}
struct Node {
    int x, y;
    bool operator < (const Node &rhs) const {
        return check(x, y, rhs.x, rhs.y);
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
                auto [x0, y0] = pq0.top();
                auto [x1, y1] = pq1.top();
                if (!check(x0, y0, x1, y1)) {
                    cout << x0 << " " << y0 << "\n";
                    pq0.pop();
                    pq1.push({x0 + 1, y0});
                    pq1.push({x0, y0 + 1});
                    pq1.push({x0 + 1, y0 + 1});
                } else {
                    cout << x1 << " " << y1 << "\n";
                    pq1.pop();
                }
                
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