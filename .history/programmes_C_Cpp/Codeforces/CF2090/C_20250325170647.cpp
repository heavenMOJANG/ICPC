#pragma GCC optimize(1)
#pragma GCC optimize(2)
#pragma GCC optimize(3, "Ofast", "inline")
#include <bits/stdc++.h>
#define int long long
#define ai3 array<int, 3>
using namespace std;
constexpr int INF = 0x7fffffff;
void solve() {
    int n; cin >> n;
    int x = 1, y = 1, d = 2;
    vector<array<int, 2>> ans(n);
    vector<>
    for (int i = 0; i < n; ++ i) {
        int t; cin >> t;
        if (t && !pq.empty() && pq.top().first < t) {
            cout << -1 << endl;
            return;
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