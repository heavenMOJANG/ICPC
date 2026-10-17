#pragma GCC optimize(3, "Ofast", "inline")
#include <bits/stdc++.h>
#define int long long
using namespace std;
constexpr int INF = 0x7fffffff;
void solve() {
    int H, W; cin >> H >> W;
    vector<string> C(H);
    for (auto && c : C) cin >> c;
    int l{}, r{W - 1}, u{}, d{H - 1};
    for (;;) {
        int f{};
        for (int j{l}; j <= r; ++ j) if (C[u][j] == '#') f = 1;
        if (!f) u ++;
        else break;
    }
    for (;;) {
        int f{};
        for (int j{l}; j <= r; ++ j) if (C[d][j] == '#') f = 1;
        if (!f) d --;
        else break;
    }
    for (;;) {
        int f{};
        for (int i{u}; i <= d; ++ i) if (C[i][l] == '#') f = 1;
        if (!f) l ++;
        else break;
    }
    for (;;) {
        int f{};
        for (int i{u}; i <= d; ++ i) if (C[i][r] == '#') f = 1;
        if (!f) r --;
        else break;
    }
    for (int i{u}; i <= d; ++ i) {
        for (int j{l}; j <= r; ++ j) cout << C[i][j];
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