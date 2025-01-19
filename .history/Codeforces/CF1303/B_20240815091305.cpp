#pragma GCC optimize(1)
#pragma GCC optimize(2)
#pragma GCC optimize(3,"Ofast","inline")
#include<bits/stdc++.h>
#define int long long
using namespace std;
constexpr int INF = 0x7fffffff;
void solve() {
    int n, g, b; cin >> n >> g >> b;
    if (g >= b) {cout << n << "\n"; return;}
    int need = (n + 1) / 2;
    int k = (need + g - 1) / (g - 1);
    int ans = k * (g + b) + need - k * g;
    cout << max(ans, n) << "\n";
}
signed main() {
    cin.tie(0) -> sync_with_stdio(0);
    int _ = 1; cin >> _;
    while(_ --) solve();
    return 0;
}