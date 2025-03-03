#pragma GCC optimize(1)
#pragma GCC optimize(2)
#pragma GCC optimize(3, "Ofast", "inline")
#include <bits/stdc++.h>
#define int long long
using namespace std;
constexpr int INF = 0x7fffffff;
void solve() {
    int n; cin >> n;
    set<int> a, b;
    for (int i = 0, x; i < n; ++ i) cin >> x, a.insert(x);
    for (int i = 0, x; i < n; ++ i) cin >> x, b.insert(x);
    cout << (a.size() >= 3 || b.size() >= 3 || (a.size() >= 2 && b.size() >= 2) ? "YES\n" : "NO\n");
    return;
}
signed main() {
    cin.tie(0) -> sync_with_stdio(0);
    int _ = 1; cin >> _;
    while(_ --) solve();
    return 0;
}