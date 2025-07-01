#pragma GCC optimize(1)
#pragma GCC optimize(2)
#pragma GCC optimize(3, "Ofast", "inline")
#include <bits/stdc++.h>
#define int long long
using namespace std;
constexpr int INF = 0x7fffffff;
void solve() {
    int n; cin >> n;
    vector<int> a(n + 1);
    for (int i = 1; i <= n; ++ i) cin >> a[i];
    vector<int> p0, p1;
    for (int i = 2; i <= n; ++ i) {
        if (a[i - 1] < a[i] && a[i] > a[i + 1]) p0.emplace_back(i);
        if (a[i - 1] > a[i] && a[i] < a[i + 1]) p1.emplace_back(i);
    }
    for (int i = 1; i < n; ++ i) {
        
    }
    return;
}
signed main() {
    cin.tie(0) -> sync_with_stdio(0);
    int _ = 1; //cin >> _;
    while(_ --) solve();
    return 0;
}