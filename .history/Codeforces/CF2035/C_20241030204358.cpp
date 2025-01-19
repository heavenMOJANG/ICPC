#pragma GCC optimize(1)
#pragma GCC optimize(2)
#pragma GCC optimize(3, "Ofast", "inline")
#include <bits/stdc++.h>
#define int long long
using namespace std;
constexpr int INF = 0x7fffffff;
void solve() {
    int n; cin >> n;
    if (n == 6) {cout << "7\n2 3 4 5 1 6\n"; return;}
    vector<int> vis(n + 1, 0);
    if (n & 1) {
        vis[3] = vis[1] = vis[n - 1] = vis[n] = 1;
        cout << n << "\n";
        for (int i = 1; i <= n; ++ i) {
            if (vis[i]) continue;
            cout << i << " ";
        }
        cout << "3 1 " << n - 1 << " " << n << "\n";
    } else {
        int x = __lg(n);
        vis[3] = vis[1] = vis[(1ll << x) - 2] = vis[(1ll << x) - 1] = vis[n] = 1;
        cout << (1ll << x + 1) - 1 << "\n";
        for (int i = 1; i <= n; ++ i) {
            if (vis[i]) continue;
            cout << i << " ";
        }
        cout << "3 1 " << (1ll << x + 1) - 2 << " " << (1ll << x + 1) - 1 << " " << n << "\n";
    }
    return;
}
signed main() {
    cin.tie(0) -> sync_with_stdio(0);
    int _ = 1; cin >> _;
    while(_ --) solve();
    return 0;
}