#pragma GCC optimize(3, "Ofast", "inline")
#include <bits/stdc++.h>
#define int long long
using namespace std;
constexpr int INF = 0x7fffffff;
void solve() {
    int h, w, q; cin >> h >> w >> q;
    vector a(h + 1, vector<int>(w + 1, 1));
    while (q --) {
        int op, x; cin >> op >> x;
        if (op == 1) {
            cout << x * w << "\n";
            h -= x;
        } else {
            cout << x * h << "\n";
            w -= x;
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