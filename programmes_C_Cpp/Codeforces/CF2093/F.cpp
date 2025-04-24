#pragma GCC optimize(1)
#pragma GCC optimize(2)
#pragma GCC optimize(3, "Ofast", "inline")
#include <bits/stdc++.h>
#define int long long
using namespace std;
constexpr int INF = 0x7fffffff;
void solve() {
    int n, m; cin >> n >> m;
    vector<string> a(n + 1);
    vector b(m + 1, vector<string> (n + 1));
    for (int i = 1; i <= n; ++ i) cin >> a[i];
    for (int i = 1; i <= m; ++ i)
        for (int j = 1; j <= n; ++ j) cin >> b[i][j];
    for (int i = 1; i <= n; ++ i) {
        int ok{};
        for (int j = 1; j <= m; ++ j) if (a[i] == b[j][i]) { ok = 1; break; }
        if (!ok) { cout << "-1\n"; return; }
    }
    int minn = INF;
    for (int j = 1; j <= m; ++ j) {
        int cnt{};
        for (int i = 1; i <= n; ++ i) if (a[i] != b[j][i]) cnt ++;
        minn = min(minn, cnt);
    }
    cout << n + 2 * minn << "\n";
    return;
}
signed main() {
    cin.tie(0) -> sync_with_stdio(0);
    int _ = 1; cin >> _;
    while(_ --) solve();
    return 0;
}