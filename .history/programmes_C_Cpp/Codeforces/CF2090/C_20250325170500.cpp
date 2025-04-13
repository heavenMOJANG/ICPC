#pragma GCC optimize(1)
#pragma GCC optimize(2)
#pragma GCC optimize(3, "Ofast", "inline")
#include <bits/stdc++.h>
#define int long long
using namespace std;
constexpr int INF = 0x7fffffff;
void solve() {
    int n; cin >> n;
    vector<int> t(n + 1);
    for (int i = 1; i <= n; ++ i) cin >> t[i];
    int d = ceil(sqrt(n)) + 10;
    priority_queue<array<int, 3>, vector<array<int, 3>>, greater<array<int, 3>>> pq;
    for (int i = 0; i < d; ++ i)
        for (int j = 0; j < d; ++ j)
            pq0.push({1 + i * 3, 1 + j * 3});
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
                auto [x1, y1] = pq1.top(); pq1.pop();
                cout << x1 << " " << y1 << "\n";
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