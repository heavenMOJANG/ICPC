#pragma GCC optimize(3, "Ofast", "inline")
#include <bits/stdc++.h>
#include <atcoder/all>
#define int long long
using namespace std;
constexpr int INF = 0x7fffffff;
constexpr int N = 2e12;
void solve() {
    int h, w; cin >> h >> w;
    vector a(h, vector<int> (w));
    for (auto && row : a)
        for (auto && x : row) cin >> x;
    
    return;
}
signed main() {
    cin.tie(0) -> sync_with_stdio(0);
    int _ = 1; //cin >> _;
    while(_ --) solve();
    return 0;
}