#pragma GCC optimize(3, "Ofast", "inline")
#include <bits/stdc++.h>
#define int long long
using namespace std;
constexpr int INF = 0x7fffffff;
void solve() {
    int n, px, py, qx, qy; cin >> n >> px >> py >> qx >> qy;
    int tot{}, maxn{};
    for (int i{}; i < n; ++ i) {
        int x; cin >> x;
        tot += x, maxn = max(maxn, x);
    }
    int d = (qx - px) * (qx - px) + (qy - py) * (qy - py);
    int l = max(0ll, 2 * maxn - tot), r = tot;
    return;
}
signed main() {
    cin.tie(0) -> sync_with_stdio(0);
    int _ = 1; //cin >> _;
    while(_ --) solve();
    return 0;
}