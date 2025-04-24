#pragma GCC optimize(1)
#pragma GCC optimize(2)
#pragma GCC optimize(3, "Ofast", "inline")
#include <bits/stdc++.h>
#define int long long
using namespace std;
constexpr int INF = 0x7fffffff;
void solve() {
    int n, q; cin >> n >> q;
    function<int(int, int, int)> dfs0 = [&](int x, int y, int n) {
        if (n == 0) return 1ll;
        int d = 1ll << n, res = d * d / 4;
        if (x <= d / 2 && y <= d / 2) return dfs0(x, y, n - 1);
        if (x > d / 2 && y > d / 2) return dfs0(x - d / 2, y - d / 2, n - 1) + res;
        if (x > d / 2 && y <= d / 2) return dfs0(x - d / 2, y, n - 1) + res * 2;
        if (x <= d / 2 && y > d / 2) return dfs0(x, y - d / 2, n - 1) + res * 3;
    };
    while (q --) {
        string op; cin >> op;
        if (op == "->") {
            int x, y; cin >> x >> y;
        } else {
            int d; cin >> d;
        }
    }
    return;
}
signed main() {
    cin.tie(0) -> sync_with_stdio(0);
    int _ = 1; //cin >> _;
    while(_ --) solve();
    return 0;
}