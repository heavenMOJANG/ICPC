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
    vector<vector<char>> g(m, vector<char>(n, ' '));
    for (int i = m; i >= 0; -- i) {
        for (int j = 0; j < s[j].size(); ++ j)
    }
}
signed main() {
    cin.tie(0) -> sync_with_stdio(0);
    int _ = 1; //cin >> _;
    while(_ --) solve();
    return 0;
}