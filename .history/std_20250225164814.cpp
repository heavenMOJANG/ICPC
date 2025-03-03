#pragma GCC optimize(1)
#pragma GCC optimize(2)
#pragma GCC optimize(3, "Ofast", "inline")
#include <bits/stdc++.h>
using namespace std;
constexpr int INF = 0x7fffffff;
constexpr int N = 4e5 + 10;
const double PI = acos(-1.0);
double a[N];
void solve() {
    int n, k; cin >> n >> k;
    for (int i = 0; i < n; ++ i) {
        int x, y; cin >> x >> y;
        a[i] = atan2(y, x);
    }
    sort(a, a + n);
    for (int i = 0; i < n; ++ i) a[i + n] = a[i] + 2 * PI;
    double ans{};
    for (int i = 0; i < n; ++ i) ans = max(ans, a[i + k] - a[i]);
    cout << fixed << setprecision(10) << ans << endl;
    return;
}
signed main() {
    cin.tie(0) -> sync_with_stdio(0);
    freopen("2.in", "r", stdin);
    freopen("2.out", "w", stdout);
    int _ = 1; cin >> _;
    while(_ --) solve();
    fclose(stdin);
    fclose(stdout);
    return 0;
}