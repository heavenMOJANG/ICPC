#pragma GCC optimize(1)
#pragma GCC optimize(2)
#pragma GCC optimize(3, "Ofast", "inline")
#include <bits/stdc++.h>
#define int long long
using namespace std;
constexpr int INF = 0x7fffffff;
void solve() {
    int n, m; cin >> n >> m;
    vector<int> a(n), b(m);
    for (int i = 0; i < n; ++ i) cin >> a[i];
    for (int i = 0; i < m; ++ i) cin >> b[i];
    if (b[0] - a[0] < a[0]) a[0] = b[0] - a[0];
    for (int i = 1; i < n; ++ i) {
        int l = min(a[i], b[0] - a[i]), r = max(a[i], b[0] - a[i]);
        if (a[i - 1] < l) a[i] = l;
        else if (l <= a[i - 1] && a[i - 1 ] <= r) a[i] = r;
        else { cout << "NO\n"; return; }
    }
    cout << "YES\n";
    return;
}
signed main() {
    cin.tie(0) -> sync_with_stdio(0);
    int _ = 1; cin >> _;
    while(_ --) solve();
    return 0;
}