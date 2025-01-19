#pragma GCC optimize(1)
#pragma GCC optimize(2)
#pragma GCC optimize(3,"Ofast","inline")
#include<bits/stdc++.h>
#define int long long
using namespace std;
constexpr int inf = 0x7fffffff;
void solve() {
    int n, k; cin >> n >> k;
    vector<int> a(n), b(n), c(n);
    for (int i = 0; i < n; ++ i) cin >> a[i];
    for (int i = 0; i < n; ++ i) cin >> b[i], c[i] = a[i] / b[i];
    auto check = [&](int x) {
        int res = 0;
        for (int i = 0; i < n; ++ i) {
            if (a[i] <= x) continue;
            if (a[i] - c[i] * b[i] > x) {
                res += c[i] + 1;
                continue;
            }
            res += (a[i] - x + b[i] - 1) / b[i];
        }
        return res > k;
    }
    return;
}
signed main() {
    cin.tie(0) -> sync_with_stdio(0);
    int _ = 1; //cin >> _;
    while(_ --) solve();
    return 0;
}