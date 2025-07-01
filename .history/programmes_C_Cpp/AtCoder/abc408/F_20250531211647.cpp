#pragma GCC optimize(3, "Ofast", "inline")
#include <bits/stdc++.h>
#define int long long
using namespace std;
constexpr int INF = 0x7fffffff;
void solve() {
    int n, d, r; cin >> n >> d >> r;
    vector<int> h(n), p(n);
    for (int i{}; i < n; ++ i) {
        cin >> h[i];
        p[h[i]] = i;
        
    }
    return;
}
signed main() {
    cin.tie(0) -> sync_with_stdio(0);
    int _ = 1; //cin >> _;
    while(_ --) solve();
    return 0;
}