#pragma GCC optimize(1)
#pragma GCC optimize(2)
#pragma GCC optimize(3, "Ofast", "inline")
#include <bits/stdc++.h>
#define int long long
using namespace std;
constexpr int INF = 0x7fffffff;
int f(int x, int y) { return (x % y) + (y % x); }
void solve() {
    int n; cin >> n;
    vector<int> b(n + 1), a(n + 1);
    for (int i = 1; i <= n; ++ i) cin >> b[i];
    int maxn{}; a[1] = 0;
    for (int i = 2; i <= n; ++ i) {
        if (b[i] <= maxn) a[i] = f(b[i], maxn);
        if (maxn < b[i] && b[i] < 2 * maxn) a[i] = b[i];
        if (2 * maxn <= b[i]) {
            for (int j = 1; j < i; ++ j) a[j] = f(b[i], b[j]);
        }
    }
    for (int i = 1; i <= n; ++ i) cout << a[i] << " \n"[i == n];
    return;
}
signed main() {
    cin.tie(0) -> sync_with_stdio(0);
    int _ = 1; cin >> _;
    while(_ --) solve();
    return 0;
}