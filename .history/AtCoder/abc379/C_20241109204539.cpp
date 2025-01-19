#pragma GCC optimize(1)
#pragma GCC optimize(2)
#pragma GCC optimize(3, "Ofast", "inline")
#include <bits/stdc++.h>
#define int long long
using namespace std;
constexpr int INF = 0x7fffffff;
void solve() {
    int n, m; cin >> n >> m;
    vector<int> x(m), a(m);
    int sum{};
    for (int i = 0; i < m; ++ i) cin >> x[i];
    for (int i = 0; i < m; ++ i) cin >> a[i], sum += a[i];
    if (sum != n) { cout << "-1\n"; return; }
    for (int i = 0; i < m; ++ i) {
        diff[x[i]] += a[i];
        if (x[i] + 1 <= n) 
    }
    return;
}
signed main() {
    cin.tie(0) -> sync_with_stdio(0);
    int _ = 1; //cin >> _;
    while(_ --) solve();
    return 0;
}