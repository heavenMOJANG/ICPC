#pragma GCC optimize(1)
#pragma GCC optimize(2)
#pragma GCC optimize(3, "Ofast", "inline")
#include <bits/stdc++.h>
#define int long long
using namespace std;
constexpr int INF = 0x7fffffff;
constexpr double eps = 1e-6;
constexpr int N = 1e5 + 10;
int n, k;
double a[N];
bool check(double x) {

}
void solve() {
    cin >> n >> k;
    for (int i = 1; i <= n; ++ i) cin >> a[i];
    double l{}, r = 1.0l;
    while (r - l > eps) {
        double mid = (l + r) / 2;
        
    }
    return;
}
signed main() {
    cin.tie(0) -> sync_with_stdio(0);
    int _ = 1; //cin >> _;
    while(_ --) solve();
    return 0;
}