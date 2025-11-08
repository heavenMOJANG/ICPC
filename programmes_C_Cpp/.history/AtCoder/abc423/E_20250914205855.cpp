#pragma GCC optimize(3, "Ofast", "inline")
#include <bits/stdc++.h>
#define int long long
using namespace std;
constexpr int INF = 0x7fffffff;
void solve() {
    int n, q; cin >> n >> q;
    vector<int> a(n + 1);
    for (int i = 1; i <= n; ++ i) cin >> a[i];
    vector<int> p0(n + 1, 0), p1(n + 1, 0), p2(n + 1, 0);
    for (int i = 1; i <= n; ++ i) {
        p0[i] = p0[i - 1] + a[i];
        p1[i] = p1[i - 1] + a[i] * i;
        p2[i] = p2[i - 1] + a[i] * i * i;
    }
    while (q --) {
        int l, r; cin >> l >> r;
        int s0 = p0[r] - p0[l - 1], s1 = p1[r] - p1[l - 1], s2 = p2[r] - p2[l - 1];
        int ans = (l + r) * s1 - (l - 1) * (r + 1) * s0 - s2;
        cout << ans << "\n";
    }
    return;
}
signed main() {
    cin.tie(nullptr) -> sync_with_stdio(false);
    int _ = 1; //cin >> _;
    while(_ --) solve();
    return 0;
}