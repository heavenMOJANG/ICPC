#pragma GCC optimize(1)
#pragma GCC optimize(2)
#pragma GCC optimize(3, "Ofast", "inline")
#include <bits/stdc++.h>
#define int long long
using namespace std;
constexpr int INF = 0x7fffffff;
void solve() {
    int n, q; cin >> n >> q;
    vector<int> h(n + 1);
    for (int i = 1; i <= n; ++ i) cin >> h[i];
    vector<int> low(n + 1), hig(n + 1);
    for (int i = 2; i <= n; ++ i) low[i] = min(h[i], h[i - 1]), hig[i] = max(h[i], h[i + 1]);
    
    return;
}
signed main() {
    cin.tie(0) -> sync_with_stdio(0);
    int _ = 1; //cin >> _;
    while(_ --) solve();
    return 0;
}