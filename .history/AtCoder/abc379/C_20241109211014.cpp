#pragma GCC optimize(1)
#pragma GCC optimize(2)
#pragma GCC optimize(3, "Ofast", "inline")
#include <bits/stdc++.h>
#define int long long
using namespace std;
constexpr int INF = 0x7fffffff;
void solve() {
    int n, m; cin >> n >> m;
    vector<int> x(m + 1), a(m + 1);
    int sum{};
    for (int i = 0; i < m; ++ i) cin >> x[i];
    for (int i = 0; i < m; ++ i) cin >> a[i], sum += a[i];
    if (sum != n) { cout << "-1\n"; return; }
    if (x[0] != 1) { cout << "-1\n"; return; }
    if (m == 1) { cout << n * (n - 1) / 2 << "\n"; return; }
    int lst = n, ans{};
    for (int i = m - 1; i >= 0 ; ++ i) {
        if (x[i] == lst) { lst --; continue;}
        int len = lst - x[i];
        if (a[i] < len) {

        } else {
            lst = x[i] - 1;
            continue;
        }
    }
    return;
}
signed main() {
    cin.tie(0) -> sync_with_stdio(0);
    int _ = 1; //cin >> _;
    while(_ --) solve();
    return 0;
}