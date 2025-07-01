#pragma GCC optimize(1)
#pragma GCC optimize(2)
#pragma GCC optimize(3, "Ofast", "inline")
#include <bits/stdc++.h>
#define int long long
using namespace std;
constexpr int INF = 0x7fffffff;
void solve() {
    int n; cin >> n;
    vector<int> a(n + 1), b(n + 1);
    for (int i = 1; i <= n; ++ i) cin >> a[i], b[a[i]] = i;
    int l{}, r{};
    for (int i = 2; i <= n; ++ i) if (b[i] < b[i - 1]) { l = n - i + 1; break; }
    for (int i = n - 1; i >= 1; ++ i) if (b[i] < b[i + 1]) { r = i; break; }
    cout << min(l, r) << "\n";
    return;
}
signed main() {
    cin.tie(0) -> sync_with_stdio(0);
    int _ = 1; cin >> _;
    while(_ --) solve();
    return 0;
}