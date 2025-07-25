#pragma GCC optimize(1)
#pragma GCC optimize(2)
#pragma GCC optimize(3, "Ofast", "inline")
#include <bits/stdc++.h>
#define int long long
using namespace std;
constexpr int INF = 0x7fffffff;
class DSU {
private:
    int len;
    vector<int> fat, siz;
    
    bool isSame (int x, int y) { return x == y; }
public:
    DSU(int x) : len(x), fat(x + 1), siz(x + 1, 1) { iota(fat.begin(), fat.end(), 0); }
    int findSet(int x) { return fat[x] == x ? x : fat[x] = findSet(fat[x]); }
    void mergeSet(int x, int y) {
        x = findSet(x), y = findSet(y);
        if (isSame(x, y)) return;
        if (siz[x] > siz[y]) fat[y] = x, siz[x] += siz[y];
        else fat[x] = y, siz[y] += siz[x];
        return;
    }
    int getVal(int x) { return fat[x]; }
};
void solve() {
    int n; cin >> n;
    vector<int> a(n + 1);
    for (int i = 1; i <= n; ++ i) cin >> a[i];
    DSU dsu(n);
    return;
}
signed main() {
    cin.tie(0) -> sync_with_stdio(0);
    int _ = 1; cin >> _;
    while(_ --) solve();
    return 0;
}