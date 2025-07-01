#pragma GCC optimize(3, "Ofast", "inline")
#include <bits/stdc++.h>
#define int long long
using namespace std;
constexpr int INF = 0x7fffffff;
constexpr int N = 3e5 + 10;
struct Edge { int u, v; } e[N];
int fa[N], sz[N];
int findSet(int x) { return fa[x] == x ? x : fa[x] = findSet(fa[x]); }

void solve() {
    int n, m; cin >> n >> m;
    fill(sz + 1, sz + 1 + N, 1);
    iota(fa + 1, fa + N, 1);
    vector<unordered_map<int, int>> mp(n + 1);
    for (int i = 1; i <= m; ++ i) {
        int u, v; cin >> u >> v;
        e[i] = {u, v};
        mp[u][v] ++, mp[v][u] ++;
    }
    int q; cin >> q;
    int cur = m;
    while (q --) {
        int x; cin >> x;
        auto [u, v] = e[x];
        int fu = findSet(u), fv = findSet(v);
        if (fu != fv) {
            auto it = mp[fu].find(fv);
            if (it != mp[fu].end()) {
                int cnt = it -> second;
                cur -= cnt;
                if (mp[fu].size() < mp[fv].size()) swap(fu, fv);
                for (auto [id, c]: mp[fv]) {
                    if (id == fu) continue;
                    mp[fu][id] += c;
                    mp[id][fu] += c;
                    mp[id].erase(fv);
                }
                mp[fv].clear();
                fa[fv] = fu;
                sz[fu] += sz[fv];
            }
        }
        cout << cur << "\n";
    }
    return;
}
signed main() {
    cin.tie(0) -> sync_with_stdio(0);
    int _ = 1; //cin >> _;
    while(_ --) solve();
    return 0;
}