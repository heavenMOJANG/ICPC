#pragma GCC optimize(1)
#pragma GCC optimize(2)
#pragma GCC optimize(3,"Ofast","inline")
#include <bits/stdc++.h>
#define int long long
using namespace std;
constexpr int INF = 0x7fffffff;
void solve() {
    int n; cin >> n;
    vector<int> a(n), b(n - 1);
    for (int i = 0; i < n; ++ i) cin >> a[i];
    for (int i = 0; i < n - 1; ++ i) cin >> b[i];
    for (int i = 0; i < n; ++ i) b.emplace_back(a[i]);

    return;
}
signed main() {
    cin.tie(0) -> sync_with_stdio(0);
    int _ = 1; //cin >> _;
    while(_ --) solve();
    return 0;
}