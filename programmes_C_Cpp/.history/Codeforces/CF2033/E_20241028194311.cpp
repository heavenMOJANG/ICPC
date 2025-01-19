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
    Dsu(int n) : f(n + 1), siz(n + 1, 0) {iota(f.begin(), f.end(), 0);}
    int findSet(int x) {return f[x] == x ? x : f[x] = findSet(f[x]);}
    bool unionSet(int x, int y) {
        x = findSet(x), y = findSet(y);
        if (x == y) return 0;
    }
};
void solve() {
    int n; cin >> n;
    vector<int> p(n + 1);
    for (int i = 1; i <= n; ++ i) cin >> p[i];

    return;
}
signed main() {
    cin.tie(0) -> sync_with_stdio(0);
    int _ = 1; //cin >> _;
    while(_ --) solve();
    return 0;
}