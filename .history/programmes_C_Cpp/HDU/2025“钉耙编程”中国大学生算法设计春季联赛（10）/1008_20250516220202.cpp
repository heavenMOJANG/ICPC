#pragma GCC optimize(1)
#pragma GCC optimize(2)
#pragma GCC optimize(3, "Ofast", "inline")
#include <bits/stdc++.h>
#define int long long
using namespace std;
constexpr int INF = 0x7fffffff;
int a[110][1010], mx[110][2];
void solve() {
    int n, m; cin >> n >> m;
    for (int i{}; i < n; ++ i) {
        int m0{}, m1{};
        for (int j{}; j < m; ++ j) {
            cin >> a[i][j];
            if (a[i][j] > m0) m1 = m0, m0 = a[i][j];
            else if (a[i][j] > m1) m1 = a[i][j];
        }
        mx[i][0] = m0, mx[i][1] = m1;
    }
    int maxn{};
    for (int k{}; k < m; ++ k) {
        vector<int> d(n);
        for (int i{}; i < n; ++ i) d[i] = mx[i][0] - a[i][k];
        sort(d.begin(), d.end());
        int res{};
        for (int i{}; i < n; ++ i) res += mx[i][0];
        res -= accumulate(d.begin(), d.begin() + n / 2 + 1, 0);
        maxn = max(maxn, res);
    }
    cout << maxn << "\n";
    return;
}
signed main() {
    cin.tie(0) -> sync_with_stdio(0);
    int _ = 1; cin >> _;
    while(_ --) solve();
    return 0;
}