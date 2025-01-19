#pragma GCC optimize(1)
#pragma GCC optimize(2)
#pragma GCC optimize(3,"Ofast","inline")
#include<bits/stdc++.h>
#define int long long
using namespace std;
constexpr int INF = 0x7fffffff;
void solve() {
    int n; cin >> n;
    string s[n];
    int m = 0;
    for (int i = 0; i < n; ++ i) cin >> s[i], m = max(m, (int)s[i].size());
    reverse(s, s + n);
    vector<vector<char>> g(m, vector<char>(n));
    vector<vector<int>> vis(m, vector<int>(n, 0));
    vector<int> p(m, 0);
    for (int j = 0; j < n; ++ j)
        for (int i = 0; i < s[j].size(); ++ i)
            g[i][j] = s[j][i], vis[i][j] = 1;
    for (int i = 0; i < m; ++ i)
        for (int j = 0; j < n; ++ j)
            if ('a' <= g[i][j] && g[i][j] <= 'z') p[i] = max(p[i], j);
    for (int i = 0; i < m; ++ i)
        for (int j = 0; j < n; ++ j)
            if (j < p[i] && s[j].size() i) g[i][j] = '*';
    for (int i = 0; i < m; ++ i){
        for (int j = 0; j < n; ++ j) cout << g[i][j];
        cout << "\n";
    }
}
signed main() {
    cin.tie(0) -> sync_with_stdio(0);
    int _ = 1; //cin >> _;
    while(_ --) solve();
    return 0;
}