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
    vector<int> b(n + 1);
    for (int i = 1; i <= n; ++ i) cin >> b[i];
    int maxn{}, ans{};
    for (int i = 1; i <= n; ++ i) {
        if (b[i] <= maxn) ans = max(ans, f(b[i], maxn));
        if (maxn < b[i] && b[i] < 2 * maxn) ans = max(ans, b[i]);
        if (2 * maxn <= b[i]) {
            for (int j = 2; j < i; ++ j) ans = max(ans, f(b[i], b[j]));
        }
        maxn = max(maxn, b[i]);
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