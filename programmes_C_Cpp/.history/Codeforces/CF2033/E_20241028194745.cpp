#pragma GCC optimize(1)
#pragma GCC optimize(2)
#pragma GCC optimize(3,"Ofast","inline")
#include <bits/stdc++.h>
#define int long long
using namespace std;
constexpr int INF = 0x7fffffff;
class Dsu {
public:
    vector<int> f, siz;
    Dsu(int n) : f(n + 1), siz(n + 1, 1) {iota(f.begin(), f.end(), 0);}
    int findSet(int x) {return f[x] == x ? x : f[x] = findSet(f[x]);}
    bool unionSet(int x, int y) {
        x = findSet(x), y = findSet(y);
        if (x == y) return 0;
        if (siz[x] < siz[y]) {
            f[x] = y;
            siz[y] += siz[x];
        } else {
            f[y] = x;
            siz[x] += siz[y];
        }
    }
};
void solve() {
    int n; cin >> n;
    vector<int> p(n + 1);
    Dsu dsu(n);
    for (int i = 1; i <= n; ++ i) cin >> p[i];
    int f0{}, f1{};
    for (int i = 1; i <= n; ++ i) {
        if (p[i] == i) f0 ++;
        if (p[i] == p[p[i]]) f1 ++;
    }
    if (f0 == n || f1 == n) {cout << "0\n"; return;}
    for (int i = 1; i <= n; ++ i)
        if (dsu.f[i] == i) {
            int cur = i;
            while(p[cur] != i) {
                cur = p[cur];
                dsu.unionSet(i, cur);
            }
        }
    int ans{};
    for (int i = 1; i <= n; ++ i) ans += (dsu.siz[i] - 1) / 2;
    cout << ans << "\n";
    return;
}
signed main() {
    cin.tie(0) -> sync_with_stdio(0);
    int _ = 1; cin >> _;
    while(_ --) solve();
    return 0;
}