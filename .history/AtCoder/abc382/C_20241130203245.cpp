#pragma GCC optimize(1)
#pragma GCC optimize(2)
#pragma GCC optimize(3, "Ofast", "inline")
#include <bits/stdc++.h>
#define int long long
using namespace std;
constexpr int INF = 0x7fffffff;
void solve() {
    int n, m; cin >> n >> m;
    vector<int> a(n);
    vector<int> b(m);
    for (int i = 0; i < n; ++ i) {
        cin >> a[i].first;
        a[i].second = i
    for (int i = 0; i < n; ++ i) rk[i] = a[i].first;
    for (int j = 0; j < m; ++ j) {
        cin >> b[j];
        int p = lower_bound(rk.begin(), rk.end(), b[j]) - rk.begin() - 1;
        //cout << p << "\n";
        if (p == -1) {
            if (b[j] < a[0].first) cout << "-1\n";
            else cout << a[0].second << "\n";
        }
        else cout << a[p].second << "\n";
    }
    return;
}
signed main() {
    cin.tie(0) -> sync_with_stdio(0);
    int _ = 1; //cin >> _;
    while(_ --) solve();
    return 0;
}