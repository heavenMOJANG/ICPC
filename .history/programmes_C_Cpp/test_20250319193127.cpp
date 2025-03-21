#pragma GCC optimize(1)
#pragma GCC optimize(2)
#pragma GCC optimize(3, "Ofast", "inline")
#include <bits/stdc++.h>
#define int long long
using namespace std;
constexpr int INF = 0x7fffffff;
constexpr int N = 1e4 + 10;
struct HOUSE {
    long double area{}, tot{};
    int popu = 1;
} h[N];
struct DSU {
    vector<int> fa;
    DSU (int n) : fa(n + 1) { iota(fa.begin(), fa.end(), 0); }
    int findSet(int x) { return fa[x] == x ? x : fa[x] = findSet(fa[x]); }
    void unionSet(int x, int y) {
        x = findSet(x), y = findSet(y);
        if (x == y) return;
        if (x > y) fa[x] = y;
        else fa[y] = x;
    }
};
void solve() {
    int n; cin >> n;
    DSU dsu(N);
    set<int> s, hos;
    for (int i = 0; i < n; ++ i) {
        int id, fatId, motId, k; cin >> id >> fatId >> motId >> k;
        s.insert(id);
        if (fatId >= 0) s.insert(fatId), dsu.unionSet(id, fatId);
        if (motId >= 0) s.insert(motId), dsu.unionSet(id, motId);
        for (int j = 0; j < k; ++ j) {
            int kidId; cin >> kidId;
            dsu.unionSet(id, kidId);
        }
        hos.insert(dsu.fa[id]);
        int num, area; cin >> num >> area;
        h[id].area += area;
        h[id].tot += num;
    }
    for (auto x : s) {
        
    }
    return;
}
signed main() {
    cin.tie(0) -> sync_with_stdio(0);
    int _ = 1; //cin >> _;
    while(_ --) solve();
    return 0;
}