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
    for (int i = 0; i < n; ++ i) cin >> b[i];
    int ok = 1;
    for (int i = 0; i < n - 1; ++ i)
        if (a[i] > a[i + 1]) {
            if (a[i] - b[0] <= a[i + 1]) ok = 0;
        } else { cout << "NO\n"; return; }
    cout << "YES\n";
    return;
}
signed main() {
    cin.tie(0) -> sync_with_stdio(0);
    int _ = 1; cin >> _;
    while(_ --) solve();
    return 0;
}