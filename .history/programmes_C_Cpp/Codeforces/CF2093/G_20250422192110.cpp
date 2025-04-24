#pragma GCC optimize(1)
#pragma GCC optimize(2)
#pragma GCC optimize(3, "Ofast", "inline")
#include <bits/stdc++.h>
#define int long long
using namespace std;
constexpr int INF = 0x7fffffff;
void solve() {
    int n, k; cin >> n >> k;
    vector<int> a(n + 1);
    for (int i = 1; i <= n; ++ i) cin >> a[i];
    struct Node {
        int x, maxSon, ch[2];
        Node(): x(0), maxSon(0) { ch[0] = ch[1] = -1; }
    };
    int cnt{};
    vector<Node> tr(n * 61);
    auto insert = [&](int x, int id) {
        int cur{};
        for (int i = 30; ~i; -- i) {
            int b = (x >> i) & 1;
            if (tr[cur].ch[b] == -1) {
                tr[cur].ch[b] = ++ cnt;
                tr[cnt] = Node();
            }
            cur = tr[cur].ch[b];
            tr[cur].maxSon = max(tr[cur].maxSon, id);
        }
        tr[cur].x = id;
    };
    auto query = [&](int x) {
        int cur{}, res{};
        for (int i = 30; ~i; -- i) {
            int bK = (k >> i) & 1, bX = (x >> i) & 1;
            if (bK == 1) cur = tr[cur].ch[bX ^ 1];
            else {
                if (tr[cur].ch[bX ^ 1] != -1) res = max(res, tr[tr[cur].ch[bX ^ 1]].maxSon);
                cur = tr[cur].ch[bX];
            }
            if (cur == -1) break;
        }
        if (cur != -1) res = max(res, tr[cur].maxSon);
        return res;
    };
    int ans = INF;
    for (int i = 1; i <= n; ++ i) {
        insert(a[i], i);
        int res = query(a[i]);
        if (res > 0) ans = min(ans, i - res + 1);
    }
    cout << (ans == INF ? -1ll : ans) << "\n";
    return;
}
signed main() {
    cin.tie(0) -> sync_with_stdio(0);
    int _ = 1; cin >> _;
    while(_ --) solve();
    return 0;
}