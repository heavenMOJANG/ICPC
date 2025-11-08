#pragma GCC optimize(3, "Ofast", "inline")
#include <bits/stdc++.h>
#define int long long
using namespace std;
constexpr int INF = 0x7fffffff;
void solve() {
    int n, m; cin >> n >> m;
    vector<string> g(n);
    for (auto && x : g) cin >> x;
    bitset<144> s;
    int si = -1, sj = -1;
    for (int i{}; i < n; ++ i)
        for (int j{}; j < m; ++ j) {
            if (g[i][j] == '#') s[i * m + j] = 1;
            else if (g[i][j] == 'T') si = i, sj = j;
        }
    return;
}
signed main() {
    cin.tie(nullptr) -> sync_with_stdio(false);
    int _ = 1; //cin >> _;
    while(_ --) solve();
    return 0;
}