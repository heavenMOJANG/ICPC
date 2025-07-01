#pragma GCC optimize(1)
#pragma GCC optimize(2)
#pragma GCC optimize(3, "Ofast", "inline")
#include <bits/stdc++.h>
#define int long long
using namespace std;
constexpr int INF = 0x7fffffff;
constexpr double eps = 1e-8;
constexpr int N = 1e5 + 10;
int n, k;
double a[N], p[N];
bool check(double x) {
    p[1] = x;
    double sum = x;
    for (int i = 2; i <= n; ++ i) {
        p[i] = (a[i] * x) / (a[i] * x + a[1] - a[1] * x);
        sum += p[i];
    }
    return sum > (k * 1.0l);
}
void solve() {
    cin >> n >> k;
    for (int i = 1; i <= n; ++ i) cin >> a[i];
    double l{}, r = 1.0l;
    while (r - l > eps) {
        double mid = (l + r) / 2.0;
        if (check(mid)) r = mid;
        else l = mid;
    }
    for (int i = 1; i <= n; ++ i) cout << fixed << setprecision(12) << p[i] << "\n";
    return;
}
signed main() {
    cin.tie(0) -> sync_with_stdio(0);
    int _ = 1; //cin >> _;
    while(_ --) solve();
    return 0;
}