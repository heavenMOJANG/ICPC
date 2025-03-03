#pragma GCC optimize(1)
#pragma GCC optimize(2)
#pragma GCC optimize(3, "Ofast", "inline")
#include <bits/stdc++.h>
#define int long long
using namespace std;
constexpr int INF = 0x7fffffff;
void solve() {
    int n; cin >> n;
    vector a(n, vector<int>(n));
    for (int i = 0; i < n; ++ i)
        for (int j = 0; j < n; ++ j) cin >> a[i][j];
    set<int> s;
    vector<int> p(n);
    iota(p.begin(), p.end(), 0);
    s.insert(p.begin(), p.end());
    int ans = 1, maxn = n;
    for (int j = n - 1; j >= 1; -- j) {
        set<int> tmp;
        for (int i = 0; i < n; ++ i) {
            if (a[i][j] == 1) {
                if (s.count(i)) tmp.insert(i);
            }
        }
        s = tmp;
        maxn = min(maxn - 1, (int)s.size());
        if (maxn == 0) break;
        ans ++;
    }
    cout << ans << "\n";
    return;
}
signed main() {
    cin.tie(0) -> sync_with_stdio(0);
    int _ = 1; cin >> _;
    while(_ --) solve();
    return 0;
}