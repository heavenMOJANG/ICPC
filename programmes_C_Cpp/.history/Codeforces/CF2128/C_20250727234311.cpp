#pragma GCC optimize(3, "Ofast", "inline")
#include <bits/stdc++.h>
#define int long long
using namespace std;
constexpr int INF = 0x7fffffff;
void solve() {
    int n; cin >> n;
    vector<int> b(n);
    for (auto && x : b) cin >> x;
    int m = b[0], ok = 1;
    for (int i = 1; i < n; ++ i)
        if (b[i] >= m * 2) { ok = 0; break; }
        
    return;
}
signed main() {
    cin.tie(nullptr) -> sync_with_stdio(false);
    int _ = 1; cin >> _;
    while(_ --) solve();
    return 0;
}