#pragma GCC optimize(3, "Ofast", "inline")
#include <bits/stdc++.h>
#define int long long
using namespace std;
constexpr int INF = 0x7fffffff;
void solve() {
    int n, s; cin >> n >> s;
    vector<int> a(n), c(3, 0);
    for (auto && x : a) cin >> x, c[x] ++;
    int sum = c[1] + 2 * c[2];
    if (sum > s) { for (int i{}; i < n; ++ i) cout << a[i] << " \n"[i == n - 1]; return; }
    if (sum == s) { cout << "-1\n"; return; }
    if (s - sum == 1) {
        for (int i{}; i < c[0]; ++ i) cout << "0 ";
        for (int i{}; i < c[2]; ++ i) cout << "2 ";
        for (int i{}; i < c[1]; ++ i) cout << "1 ";
        cout << "\n";
    } else cout << "-1\n";
    return;
}
signed main() {
    cin.tie(nullptr) -> sync_with_stdio(false);
    int _ = 1; cin >> _;
    while(_ --) solve();
    return 0;
}