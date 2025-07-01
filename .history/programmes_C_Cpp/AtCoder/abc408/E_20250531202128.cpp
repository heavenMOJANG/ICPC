#pragma GCC optimize(3, "Ofast", "inline")
#include <bits/stdc++.h>
#define int long long
using namespace std;
constexpr int INF = 0x7fffffff;
struct DSU {
    int n;
    vector<int> fa, rk;
    DSU(int _n): n(_n), fa(n + 1), rk(n + 1, 0) { iota(fa.begin(), fa.end(), 0); }
}
void solve() {
    return;
}
signed main() {
    cin.tie(0) -> sync_with_stdio(0);
    int _ = 1; //cin >> _;
    while(_ --) solve();
    return 0;
}