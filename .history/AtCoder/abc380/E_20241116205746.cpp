#pragma GCC optimize(1)
#pragma GCC optimize(2)
#pragma GCC optimize(3, "Ofast", "inline")
#include <bits/stdc++.h>
#define int long long
using namespace std;
constexpr int INF = 0x7fffffff;
void solve() {
    int n, q; cin >> n >> q;
    vector<int> fa(n + 1), siz(n + 1, 1);
    iota(fa.begin(), fa.end(), 0);
    function<int(int)> findSet = [&](int x) { return fa[x] == x ? x : fa[x] = findSet(fa[x]); };
    function<void(int, int)> unionSet = [&](int x, int y) {
        x = findSet(x), y = findSet(y);
        if (x == y) return;
        if (siz[x] < siz[y]) fa[x] = y, siz[y] += siz[x];
        else if (siz[x] > siz[y]) fa[y] = x, siz[x] += siz[y];
    };
    while (q --) {
        int op, x, c; cin >> op;
        if (op == 1) {
            cin >> x >> c;
        } else {
            cin >> c;
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