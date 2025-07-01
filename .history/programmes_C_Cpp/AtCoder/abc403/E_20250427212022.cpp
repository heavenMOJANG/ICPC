#pragma GCC optimize(1)
#pragma GCC optimize(2)
#pragma GCC optimize(3, "Ofast", "inline")
#include <bits/stdc++.h>
#define int long long
using namespace std;
constexpr int INF = 0x7fffffff;
constexpr int N = 2e6 + 10;
int tx[N][26], ed[N], idx = 1;
int ty[N][26], cnt[N], idy = 1;
void solve() {
    int q; cin >> q;
    int ans{};
    while (q --) {
        string t, s; cin >> t >> s;
        if (t == "2") {
            int u = 1;
            for (auto ch : s) {
                int c = ch - 'a';
                if (!ty[u][c]) ty[u][c] = ++ idy;
                u = ty[u][c];
                cnt[u] ++;
            }
            u = 1;
            bool flag{};
            for (auto ch : s) {
                int c = ch - 'a';
                if (!tx[u][c]) break;
                u = tx[u][c];
                if (ed[u]) { flag = 1; break; }
            }
            if (!flag) ans ++;
        } else {
            int u = 1;
            for (auto ch : s) {
                int c = ch - 'a';
                if (!tx[u][c]) tx[u][c] = ++ idx;
                u = tx[u][c];
            }
            if (!ed[u]) {
                ed[u] = 1;
                int v = 1;
                vector<int> pt;
                for (auto ch : s) {
                    int c = ch - 'a';
                    if (!ty[v][c]) { v = 0; break; }
                    v = ty[v][c];
                    pt.emplace_back(v);
                }
                if (v) {
                    int d = cnt[v];
                    ans -= d;
                    for (auto x : pt) cnt[x] -= d;
                }
            }
        }
        cout << ans << "\n";
    }
    return;
}
signed main() {
    cin.tie(0) -> sync_with_stdio(0);
    int _ = 1; //cin >> _;
    while(_ --) solve();
    return 0;
}