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
    map<pair<int, int>, vector<int>> mp;
    vector<vector<int>> a(n, vector<int>(4, 0)); 
    for (int i = 1; i <= n; ++ i) {
        string s; cin >> s;
        if (s[0] == 'B' || s[1] == 'B') a[i][0] = 1;
        if (s[0] == 'G' || s[1] == 'G') a[i][1] = 1;
        if (s[0] == 'R' || s[1] == 'R') a[i][2] = 1;
        if (s[0] == 'Y' || s[1] == 'Y') a[i][3] = 1;
        mp[{}].emplace_back(i);
    }
    for (auto & [s, v] : mp) sort(v.begin(), v.end());
    while (q --) {
        int u, v; cin >> u >> v;
        if (u > v) swap(u, v);
        for (int i = 0; i < 4; ++ i)
            if (a[u][i] & a[v][i]) {cout << abs(u - v) << "\n"; continue;}
        for (int i = 0; i < 4; ++ i)
            for (int j = 0; j < 4; ++ j)
    }
}
signed main() {
    cin.tie(0) -> sync_with_stdio(0);
    int _ = 1; //cin >> _;
    while(_ --) solve();
    return 0;
}