#pragma GCC optimize(1)
#pragma GCC optimize(2)
#pragma GCC optimize(3,"Ofast","inline")
#include <bits/stdc++.h>
//#define int long long
#define pii pair<int, int>
using namespace std;
constexpr int INF = 0x7fffffff;
class Dsu{
public:
    vector<int> fa, siz;
    Dsu(int x) : fa(x + 1), siz(x + 1, 1) {iota(fa.begin(), fa.end(), 0);}
    int findSet(int x) {return fa[x] == x ? x : fa[x] = findSet(fa[x]);}
    void unionSet(int x, int y) {
        x = findSet(x), y = findSet(y);
        if (x == y) return;
        if (siz[x] < siz[y]) fa[x] = y, siz[y] += siz[x];
        else fa[y] = x, siz[x] += siz[y];
    }
};
void solve() {
    int n, m; cin >> n >> m;
    Dsu dsu(n);
    vector<vector<int>> diff(n + 100, vector<int>(20, 0)), vis(n + 100, vector<int>(20, 0));
    for (int i = 0; i < m; ++ i) {
        int a, d, k; cin >> a >> d >> k;
        int l = a, r = a + k * d;
        diff[l + d][d] ++;
        diff[r + d][d] --;
    }
    for (int i = 1; i <= n; ++ i)
        for (int j = 1; j <= min(10, i); ++ j) diff[i][j] += diff[i - j][j];
    for (int i = 2; i <= n; ++ i) 
        for (int j = 1; j <= min(i - 1, 10); ++ j) if (diff[i][j]) dsu.unionSet(i, i - j);
    int ans{};
    for (int i = 1; i <= n; ++ i) ans += dsu.fa[i] == i;
    cout << ans << "\n";
    return;
}
signed main() {
    cin.tie(0) -> sync_with_stdio(0);
    int _ = 1; cin >> _;
    while(_ --) solve();
    return 0;
}