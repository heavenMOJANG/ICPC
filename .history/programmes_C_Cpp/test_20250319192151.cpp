#pragma GCC optimize(1)
#pragma GCC optimize(2)
#pragma GCC optimize(3, "Ofast", "inline")
#include <bits/stdc++.h>
#define int long long
using namespace std;
constexpr int INF = 0x7fffffff;
struct DSU {
    vector<int> fa;
    DSU (int n) : fa(n + 1) { iota(fa.begin(), fa.end(), 0); }
    int find(int x) { return fa[x] == x ? x : fa[x] = find(fa[x]); }
    void union(int x, int y) {
        x = find(x), y = find(y);
        if (x == y) return;
        if (x > y) fa[x] = y;
        else fa[y] = x;
    }
};
void solve() {
    int n; cin >> n;
    for (int i = 0; i < n; ++ i) {
        string id, fatId, motId; cin >> id >> fatId >> motId;
        if (fatId == "-1" && motId == "-1") 
    }
    return;
}
signed main() {
    cin.tie(0) -> sync_with_stdio(0);
    int _ = 1; //cin >> _;
    while(_ --) solve();
    return 0;
}