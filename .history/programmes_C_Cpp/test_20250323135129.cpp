#pragma GCC optimize(1)
#pragma GCC optimize(2)
#pragma GCC optimize(3, "Ofast", "inline")
#include <bits/stdc++.h>
#define int long long
using namespace std;
constexpr int INF = 0x7fffffff;
void solve() {
    int n, m; cin >> n >> m;
    string s[n];
    for (int i = 0; i < n; ++ i) cin >> s[i];
    int ok = 1;
    vector pre(n + 1, vector<int>(m + 1, 0));
    cout << (ok ? "YES\n" : "NO\n");
    return;
}
signed main() {
    cin.tie(0) -> sync_with_stdio(0);
    int _ = 1; cin >> _;
    while(_ --) solve();
    return 0;
}