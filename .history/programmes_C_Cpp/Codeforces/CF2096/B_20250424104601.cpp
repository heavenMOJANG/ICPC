#pragma GCC optimize(1)
#pragma GCC optimize(2)
#pragma GCC optimize(3, "Ofast", "inline")
#include <bits/stdc++.h>
#define int long long
using namespace std;
constexpr int INF = 0x7fffffff;
void solve() {
    int n, k; cin >> n >> k;
    struct Node {
        int l, r;
        bool operator < (const Node& b) const { return (l + r) > (b.l + b.r); }
    };
    vector<Node> a(n);
    for (int i{}; i < n; ++ i) cin >> a[i].l;
    for (int i{}; i < n; ++ i) cin >> a[i].r;
    sort(a.begin(), a.end());
    int ans{};
    for (int i = 0; i < k - 1; ++ i) ans += a[i].l + a[i].r;
    for (int i = k - 1; i < n; ++ i) ans += max(a[i].l, a[i].r);
    ans ++;
    cout << ans << "\n";
    return;
}
signed main() {
    cin.tie(0) -> sync_with_stdio(0);
    int _ = 1; cin >> _;
    while(_ --) solve();
    return 0;
}