#pragma GCC optimize(1)
#pragma GCC optimize(2)
#pragma GCC optimize(3,"Ofast","inline")
#include<bits/stdc++.h>
#define int long long
using namespace std;
constexpr int INF = 0x7fffffff;
map<char, int> d = {{'B', 0}, {'G', 1}, {'R', 2}, {'Y', 3}};
void solve() {
    int n, q; cin >> n >> q;
    map<pair<int, int>, vector<int>> mp = {
        {{0, 1}, vector<int>()},
        {{0, 2}, vector<int>()},
        {{0, 3}, vector<int>()},
        {{1, 2}, vector<int>()},
        {{1, 3}, vector<int>()},
        {{2, 3}, vector<int>()}
    };
    vector<vector<int>> a(n + 1, vector<int>(4, 0)); 
    for (int i = 1; i <= n; ++ i) {
        string s; cin >> s;
        a[i][d[s[0]]] = a[i][d[s[1]]] = 1;
        mp[{d[s[0]], d[s[1]]}].emplace_back(i);
    }
    for (auto & [s, v] : mp) sort(v.begin(), v.end());
    auto calc = [&](int u, int v, const vector<int> & b) {
        int res = INF;
        auto p = lower_bound(b.begin(), b.end(), u) - b.begin();
        if (p != b.end()) res = abs(*p - u) + abs(v - *p);
        else res = abs(b.back() - u) + abs(b.back() - v);
        return res;
    };
    while (q --) {
        int u, v; cin >> u >> v;
        if (u > v) swap(u, v);
        int ans = INF;
        for (int i = 0; i < 4; ++ i)
            if (a[u][i] && a[v][i]) ans = min(ans, abs(u - v));
        for (int i = 0; i < 4; ++ i)
            for (int j = 0; j < 4; ++ j)
                if (a[u][i] && a[v][j] && i != j) {
                    int fir = i, sec = j;
                    if (fir > sec) swap(fir, sec);
                    ans = min(ans, calc(u, v, mp[{fir, sec}]));
                }
        if (ans == INF) cout << "-1\n";
        else cout << ans << "\n";
    }
}
signed main() {
    cin.tie(0) -> sync_with_stdio(0);
    int _ = 1; cin >> _;
    while(_ --) solve();
    return 0;
}