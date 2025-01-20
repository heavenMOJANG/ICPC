#pragma GCC optimize(1)
#pragma GCC optimize(2)
#pragma GCC optimize(3, "Ofast", "inline")
#include <bits/stdc++.h>
#define int long long
using namespace std;
constexpr int INF = 0x7fffffff;
void solve() {
    int n; cin >> n;
    vector<int> w(n), s[64];
    for (int i = 0; i < n; ++ i) {
        cin >> w[i];
        for (int j = 0; j < 64; ++ j) if (w[i] & (1ll << j)) s[j].emplace_back(i);
    }
    vector<int> fa(n + 1);
    iota(fa.begin(), fa.end(), 0);
    vector<int> siz(n + 1, 1);
    function<int(int)> findSet = [&](int x) { return fa[x] == x ? x : fa[x] = findSet(fa[x]); };
    function<void(int, int)> unionSet = [&](int x, int y) {
        x = findSet(x), y = findSet(y);
        if (x == y) return;
        if (siz[x] == siz[y]) fa[y] = x, siz[x] += siz[y];
        else if (siz[x] < siz[y]) fa[x] = y, siz[y] += siz[x];
        else fa[y] = x, siz[x] += siz[y];
        return;
    };
    for (int i = 0; i < 64; ++ i) {
        if (s[i].size() < 2) continue;
        for (int j = 1; j < s[i].size(); ++ j) unionSet(s[0], s[j]);
    }
    int maxn{};
    for (int i)
}
signed main() {
    cin.tie(0) -> sync_with_stdio(0);
    int _ = 1; cin >> _;
    while(_ --) solve();
    return 0;
}