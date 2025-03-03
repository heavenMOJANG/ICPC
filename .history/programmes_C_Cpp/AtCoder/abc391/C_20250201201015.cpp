#pragma GCC optimize(1)
#pragma GCC optimize(2)
#pragma GCC optimize(3, "Ofast", "inline")
#include <bits/stdc++.h>
#define int long long
using namespace std;
constexpr int INF = 0x7fffffff;
void solve() {
    int n, q; cin >> n >> q;
    vector<int> home(n + 1, 0), siz(n + 1, 0);
    int cur{};
    while (q --) {
        int op; cin >> op;
        if (op == 1) {
            int p, h; cin >> p >> h;
            if (!home[p]) home[p] = h, siz[h] ++;
            else {
                siz[home[p]] --;
                if (!siz[home[p]]) cur --;
                home[p] = h;
                siz[h] ++;
            }
        } else {
            cout << cur << "\n";
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