#pragma GCC optimize(1)
#pragma GCC optimize(2)
#pragma GCC optimize(3,"Ofast","inline")
#include <bits/stdc++.h>
#define int long long
using namespace std;
constexpr int INF = 0x7fffffff;
void solve() {
    int n; cin >> n;
    vector<int> a(n + 1);
    for (int i = 1; i <= n; ++ i) cin >> a[i];
    for (int i = 2; i <= n / 2; ++ i) {
        int u = (a[i] == a[i + 1]) + (a[n - i + 1] == a[n - i + 2]);
        int v = (a[n - i + 1] == a[i + 1]) + (a[i] == a[n - i + 2]);
        if (u > v) swap(a[i], a[n - i + 1]); 
    }
    int ans{};
    for (int i = 1; i < n; ++ i) ans += a[i] == a[i + 1];
    return;
}
signed main() {
    cin.tie(0) -> sync_with_stdio(0);
    int _ = 1; //cin >> _;
    while(_ --) solve();
    return 0;
}