#pragma GCC optimize(3, "Ofast", "inline")
#include <bits/stdc++.h>
#define int long long
using namespace std;
constexpr int INF = 0x7fffffff;
void solve() {
    string S[5]; for (int i : views::iota(0, 5)) cin >> S[i];
    int ans{5};
    for (int i : views::iota(0, 5)) {
        int r{}, c{};
        for (int j : views::iota(0, 5)) {
            if (S[i][j] == '.') r ++;
            if (S[j][i] == '.') c ++;
        }
        ans = min({ans, r, c});
    }
    int d0{}, d1{};
    for (int i : views::iota(0, 5)) {
        if (S[i][i] == '.') d0 ++;
        if (S[i][4 - i] == '.') d1 ++;
    }
    ans = min({ans, d0, d1});
    cout << ans << "\n";
    return;
}
signed main() {
    cin.tie(nullptr) -> sync_with_stdio(false);
    int _ = 1; //cin >> _;
    while(_ --) solve();
    return 0;
}