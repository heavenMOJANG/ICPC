#pragma GCC optimize(1)
#pragma GCC optimize(2)
#pragma GCC optimize(3, "Ofast", "inline")
#include <bits/stdc++.h>
#define int long long
using namespace std;
constexpr int INF = 0x7fffffff;
constexpr int N = 1e5;
int lg[N], dpMax[20][N], dpMin[20][N];
void int
void solve() {
    int n, q; cin >> n >> q;
    for (int i = 1; i <= n; ++ i) cin >> h[i];
    for (int i = 2; i <= n; ++ i) low[i] = min(h[i], h[i - 1]), high[i] = max(h[i], h[i + 1]);
    build(1, 1, n);

    return;
}
signed main() {
    cin.tie(0) -> sync_with_stdio(0);
    for (int i = 2; i < N; ++ i) lg[i] = lg[i >> 1] + 1;
    int _ = 1; cin >> _;
    while(_ --) solve();
    return 0;
}