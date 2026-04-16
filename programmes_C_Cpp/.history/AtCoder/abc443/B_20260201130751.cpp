#pragma GCC optimize(3, "Ofast", "inline")
#include <bits/stdc++.h>
#define int long long
using namespace std;
constexpr int INF = 0x7fffffff;
void solve() {
    int n, k; cin >> n >> k;
    int l = n, r = 1e9;
    while (l < r) {
        int m = l + r >> 1;
        if ((n + m) * (m - n + 1) / 2 >= k) r = m;
        else l = m - 1;
    }
    cout << l << "\n";
    return;
}
signed main() {
    cin.tie(nullptr) -> sync_with_stdio(false);
    int _ = 1; //cin >> _;
    while(_ --) solve();
    return 0;
}