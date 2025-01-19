#pragma GCC optimize(1)
#pragma GCC optimize(2)
#pragma GCC optimize(3,"Ofast","inline")
#include <bits/stdc++.h>
#define int long long
#define pii pair<int, int>
using namespace std;
constexpr int INF = 0x7fffffff;
struct Dsu {
    vector<int> fa, ht;
    Dsu(int n) : fa(n + 1), ht(n + 1, 1) {iota(fa.begin(), fa.end(), 0);}
    int findSet(int x) {return fa[x] == x ? x : fa[x] = findSet(fa[x]);}
    void unionSet(int x, int y) {
        x = findSet(x), y = findSet(y);
        if (x != y) {
            if (ht[x] < ht[y]) fa[x] = y;
            else {
                fa[y] = x;
                if (ht[x] == ht[y]) ht[x] ++;
            }
        }
    }
};
void solve() {
    int n, m; cin >> n >> m;
    Dsu dsu(n);
    vector<vector<int>> diff(n + 100, vector<int>(20, 0)), vis(n + 100, vector<int>(20, 0));
    for (int i = 0; i < m; ++ i) {
        int a, d, k; cin >> a >> d >> k;
        int r = a % d;
        seg[d][r].emplace_back(a, a + k * d);
    }
    for (int i = 1; i <= m; ++ i)
    return;
}
signed main() {
    cin.tie(0) -> sync_with_stdio(0);
    int _ = 1; cin >> _;
    while(_ --) solve();
    return 0;
}