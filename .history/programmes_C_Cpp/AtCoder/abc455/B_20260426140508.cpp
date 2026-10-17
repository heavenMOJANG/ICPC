#pragma GCC optimize(3, "Ofast", "inline")
#include <bits/stdc++.h>
#define int long long
using namespace std;
constexpr int INF = 0x7fffffff;
void solve() {
    int H, W; cin >> H >> W;
    vector<string> g(H + 1);
    for (int i = 1; i <= H; ++ i) {
        cin >> g[i];
        g[i].insert(0, " ");
    }

    return;
}
signed main() {
    cin.tie(nullptr) -> sync_with_stdio(false);
    int _ = 1; //cin >> _;
    while(_ --) solve();
    return 0;
}
