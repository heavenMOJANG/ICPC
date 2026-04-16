#pragma GCC optimize(3, "Ofast", "inline")
#include <bits/stdc++.h>
#define int long long
using namespace std;
constexpr int INF = 0x7fffffff;
struct DSU {
    vector<int> fat, siz, xr, c0, c1;
    int ans{}, bi = 1;
    DSU (int n) : fat(n + 1), siz(n + 1, 1), xr(n + 1, 0), c0(n + 1, 1), c1(n + 1, 0) {
        iota(fat.begin(), fat.end(), 0);
    }
    pair<int, int> find(int i) {
        if (fat[i] == i) return {i, 0ll};
        auto [rt, val] = find(fat[i]);
        fat[i] = rt;
        xr[i] = xr[i] ^ val;
        return {fat[i], xr[i]};
    }
    void unite(int u, int v) {
        if (!bi) return;
        pair<int, int> root_u = find(u);
        pair<int, int> root_v = find(v);
        if (root_u.first == root_v.first) {
            if (root_u.second == root_v.second) {
                bi = false;
            }
            return;
        }
        int r1 = root_u.first;
        int r2 = root_v.first;
        if (comp_size[r1] > comp_size[r2]) {
            swap(r1, r2);
            swap(root_u, root_v);
        }
        min_black_total -= min(sz0[r1], sz1[r1]);
        min_black_total -= min(sz0[r2], sz1[r2]);
        fat[r1] = r2;
        int link_p = root_u.second ^ root_v.second ^ 1;
        xr[r1] = link_p;

        if (link_p == 0) {
            sz0[r2] += sz0[r1];
            sz1[r2] += sz1[r1];
        } else {
            sz0[r2] += sz1[r1];
            sz1[r2] += sz0[r1];
        }
        comp_size[r2] += comp_size[r1];
        min_black_total += min(sz0[r2], sz1[r2]);
    }
}
void solve() {
    int N, Q; cin >> N >> Q;

    return;
}
signed main() {
    cin.tie(nullptr) -> sync_with_stdio(false);
    int _ = 1; //cin >> _;
    while(_ --) solve();
    return 0;
}