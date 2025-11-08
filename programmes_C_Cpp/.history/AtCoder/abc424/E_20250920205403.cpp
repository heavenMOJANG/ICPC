#pragma GCC optimize(3, "Ofast", "inline")
#include <bits/stdc++.h>
#define int long long
#define double long double
using namespace std;
constexpr int INF = 0x7fffffff;
void solve() {
    int n, k, x; cin >> n >> k >> x;
    vector<double> a(n); double maxa{};
    for (int i{}; i < n; ++ i) cin >> a[i], maxa = max(maxa, a[i]);
    auto check = [&](double X) {
        if (X <= 0) return true;
        int res{}, s{};
        for (int i{}; i < n; ++ i) {
            if (a[i] < X) continue;
            res ++;

        }
    };
    return;
}
signed main() {
    cin.tie(nullptr) -> sync_with_stdio(false);
    int _ = 1; //cin >> _;
    while(_ --) solve();
    return 0;
}