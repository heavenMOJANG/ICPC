#pragma GCC optimize(1)
#pragma GCC optimize(2)
#pragma GCC optimize(3, "Ofast", "inline")
#include <bits/stdc++.h>
#define int long long
using namespace std;
constexpr int INF = 0x7fffffff;
void solve() {
    int n; cin >> n;
    vector<int> d(n + 1);
    for (int i = 1; i <= n; ++ i) cin >> d[i];
    stack<int> s;
    vector<pair<int, int>> q(n + 1);
    int cur{};
    for (int i = 1; i <= n; ++ i) {
        cin >> q[i].first >> q[i].second;
        if (d[i] == -1) { s.push(i); continue; }
        cur += d[i];
        while (!s.empty() && cur < q[i].first) {
            int p = s.top(); s.pop();
            d[p] = 1;
            cur ++;
        }
    }
    return;
}
signed main() {
    cin.tie(0) -> sync_with_stdio(0);
    int _ = 1; //cin >> _;
    while(_ --) solve();
    return 0;
}