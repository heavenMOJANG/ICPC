#pragma GCC optimize(1)
#pragma GCC optimize(2)
#pragma GCC optimize(3, "Ofast", "inline")
#include <bits/stdc++.h>
#define int long long
using namespace std;
constexpr int INF = 0x7fffffff;
void solve() {
    int n; cin >> n;
    vector<int> a(n), b(n);
    for (auto && x : a) cin >> x;
    for (auto && x : b) cin >> x;
    int maxn{}, submaxn{};
    int maxp{}, submaxp{};
    for (int i = 0; i < n; ++ i) {
        int d = max(0ll, b[i] - a[i]);
        if (d > maxn) {
            submaxn = maxn;
            submaxp = maxp;
            maxn = d;
            maxp = i;
        }
    }
    int flag = 1;
    for (int i = 0; i < n; ++ i) {
        if (i == maxp) {
            if (max(0ll, a[i] - b[i]) < submaxn) flag = 0;
        } else {
            if (max(0ll, a[i] - b[i]) < maxn) flag = 0;
        }
    }
    cout << (flag ? "YES\n" : "NO\n");
    return;
}
signed main() {
    cin.tie(0) -> sync_with_stdio(0);
    int _ = 1; cin >> _;
    while(_ --) solve();
    return 0;
}