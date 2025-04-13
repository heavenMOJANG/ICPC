#pragma GCC optimize(1)
#pragma GCC optimize(2)
#pragma GCC optimize(3, "Ofast", "inline")
#include <bits/stdc++.h>
#define int long long
using namespace std;
constexpr int INF = 0x7fffffff;
constexpr int N = 5010;
struct Point { int x, y; };
void solve() {
    int n; cin >> n;
    vector<Point> p(n);
    for (auto && [x, y] : p) cin >> x >> y;
    long double minn = LLONG_MAX;
    vector<Point> v(n);
    for (int i{}; i < n; ++ i) {
        int idx{}:
        for (int j{}; j < n; ++ j)
            if (i != j) {

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