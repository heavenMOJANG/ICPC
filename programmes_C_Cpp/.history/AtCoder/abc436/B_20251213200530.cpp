#pragma GCC optimize(3, "Ofast", "inline")
#include <bits/stdc++.h>
#define int long long
using namespace std;
constexpr int INF = 0x7fffffff;
void solve() {
    int n; cin >> n;
    vector a(n, vector<int> (n, 0));
    int r{}, c = (n - 1) / 2, k = 1;
    a[r][c] = k ++;
    while (k <= n * n) {
        if (!a[(r - 1) % n][(c + 1) % n]) {
            a[(r - 1) % n][(c + 1) % n] = k ++;
            r = (r - 1) % n;
            c = (c + 1) % n;
        } else {
            a[(r + 1) % n][c] = k ++;
            r = (r + 1) % n;
        }
    }
    for (int i{}; i < n; ++ i)
        for (int j{}; j < n; ++ j) cout << a[i][j] << " \n"[j == n - 1];
    return;
}
signed main() {
    cin.tie(nullptr) -> sync_with_stdio(false);
    int _ = 1; //cin >> _;
    while(_ --) solve();
    return 0;
}