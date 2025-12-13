#pragma GCC optimize(3, "Ofast", "inline")
#include <bits/stdc++.h>
#include <atcoder/segtree>
#define int long long
using namespace std;
using namespace atcoder;
constexpr int INF = 0x7fffffff;
int op(int a, int b) { return a + b; }
int e() { return 0ll; }
void solve() {
    int n; cin >> n;
    vector<int> a(n + 1), p(n + 1);
    for (int i = 1; i <= n; ++ i) cin >> a[i], p[a[i]] = i;
    segtree<int, op, e> seg(n + 1);
    int ans{};
    for (int i = 1; i <= n; ++ i) {
        int x = p[i];
        int l = seg.prod(1, x + 1);
        ans += (l + 1) * (i - l);
        seg.set(x, 1);
    }
    cout << ans << "\n";
    return;
}
signed main() {
    cin.tie(nullptr) -> sync_with_stdio(false);
    int _ = 1; //cin >> _;
    while(_ --) solve();
    return 0;
}