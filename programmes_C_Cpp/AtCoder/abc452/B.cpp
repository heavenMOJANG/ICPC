#pragma GCC optimize(3, "Ofast", "inline")
#include <bits/stdc++.h>
#define int long long
using namespace std;
constexpr int INF = 0x7fffffff;
void solve() {
    int H, W; cin >> H >> W;
    for (int i{}; i < H; ++ i) {
        for (int j{}; j < W; ++ j)
            cout << (i == 0 || i == H - 1 || j == 0 || j == W - 1 ? "#" : ".");
        cout << "\n";
    }
    return;
}
signed main() {
    cin.tie(nullptr) -> sync_with_stdio(false);
    int _ = 1; //cin >> _;
    while(_ --) solve();
    return 0;
}
