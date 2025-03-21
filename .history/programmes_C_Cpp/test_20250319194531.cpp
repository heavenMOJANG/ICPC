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
int fa[N];
int findSet(int x) { return fa[x] == x ? x : fa[x] = findSet(fa[x]); }
void unionSet(int x, int y) {
    x = findSet(x), y = findSet(y);
    if (x == y) return;
    if (x > y) fa[x] = y;
    else fa[y] = x;
}
void solve() {
    iota(fa, fa + N, 0);
    int n; cin >> n;
    set<int> s, hos;
    for (int i = 0; i < n; ++ i) {
        int id, fatId, motId, k; cin >> id >> fatId >> motId >> k;
        s.insert(id);
        if (fatId >= 0) s.insert(fatId), unionSet(id, fatId);
        if (motId >= 0) s.insert(motId), unionSet(id, motId);
        for (int j = 0; j < k; ++ j) {
            int kidId; cin >> kidId;
            unionSet(id, kidId);
        }
        int num, area; cin >> num >> area;
        h[id].area += area;
        h[id].tot += num;
    }
    for (auto x : s) {
        int f = findSet(x);
        if (x != f) {
            h[f].popu ++;
            h[f].area += h[x].area;
            h[f].tot += h[x].tot;
        }
        hos.insert(fa[x]);
    }
    for (auto x : hos) {
        h[x].area /= h[x].popu;
        h[x].tot /= h[x].popu;
    }
    auto cmp = [&](int a, int b) {
        if (h[a].tot == h[b].tot) return fa[a] < fa[b];
        return h[a].tot > h[b].tot;
    };
    sort(h, h + N, cmp);
    cout << hos.size() << "\n";
    for (auto x : hos)
        cout << setw(4) << setfill('0') << fa[x] << " " << h[x].popu << " " << setprecision(3) << h[x].tot << " " << h[x].area << "\n";
    return;
}
signed main() {
    cin.tie(0) -> sync_with_stdio(0);
    int _ = 1; //cin >> _;
    while(_ --) solve();
    return 0;
}