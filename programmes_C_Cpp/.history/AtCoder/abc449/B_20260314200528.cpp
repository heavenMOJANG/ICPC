#pragma GCC optimize(3, "Ofast", "inline")
#include <bits/stdc++.h>
#define int long long
using namespace std;
constexpr int INF = 0x7fffffff;
void solve() {
    int h, w, q; cin >> h >> w >> q;
    vector a(h + 1, vector<int>(w + 1, 1));
    while (q --) {
        int op; cin >> op;
        if (op == 1) {
            int r; cin >> r;
            int ans{};
            for (int i = h; i > n - r; -- i)
                for (int j = 1; j <= w; ++ j)
                    if (a[i][j]) ans ++, a[i][j] = 0;
            cout << ans << "\n";
        }
        if (op == 2) {
            int c; cin >> c;
            int ans{};
            for (int i = 1; i <= h; ++ i)
                for (int j = w - c + 1; j <= w; ++ j)
                    if (a[i][j]) ans ++, a[i][j] = 0;
            cout << ans << "\n";
        }
    }
    return;
}
signed main() {
    cin.tie(nullptr) -> sync_with_stdio(false);
    int _ = 1; //cin >> _;
    while(_ --) solve();
    return 0;
}