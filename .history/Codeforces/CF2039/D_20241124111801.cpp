#pragma GCC optimize(1)
#pragma GCC optimize(2)
#pragma GCC optimize(3, "Ofast", "inline")
#include <bits/stdc++.h>
#define int long long
using namespace std;
constexpr int INF = 0x7fffffff;
void solve() {
    int n, m; cin >> n >> m;
    vector<int> s(m);
    for (int i = 0; i < n; ++ i) cin >> s[i];
    vector<int> a(n + 1, INF);
    a[1] = m - 1;
    for (int i = 1; i <= n; ++ i)
        for (int j = i + i; j <= n; j += i) a[j] = min(a[j], a[i] - 1);
    for (int i = 1; i <= n; ++ i) if (a[i] < 0) { cout << "-1\n"; return; }
    for (int i = 1; i <= n; ++ i) cout << s[a[i]] << " \n"[i == n];
    return;
}
signed main() {
    cin.tie(0) -> sync_with_stdio(0);
    int _ = 1; cin >> _;
    while(_ --) solve();
    return 0;
}