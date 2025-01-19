#pragma GCC optimize(1)
#pragma GCC optimize(2)
#pragma GCC optimize(3,"Ofast","inline")
#include<bits/stdc++.h>
#define int long long
using namespace std;
constexpr int INF = 0x7fffffff;
void solve() {
    int n, k; cin >> n >> k;
    vector<int>a(n + 1);
    vector go(n + 1, vector<int>(60));
    for (int i = 1; i <= n; ++ i) cin >> go[i][0];
    for (int i = 1; i <= n; ++ i) cin >> a[i];
    for (int j = 1; j < 60; ++ j)
        for (int i = 1; i <= n; ++ i) go[i][j] = go[go[i][j - 1]][j - 1];
    vector<int> b(n + 1);
    iota(b.begin() + 1, b.end(), 1);
    for (int j = 0; j < 60; ++ j) {
        if (k & 1) for (int i = 1; i <= n; ++ i) b[i] = go[b[i]][j];
        k >>= 1;
    }
    for (int i = 1; i <= n; ++ i) cout << a[b[i]] << " \n"[i == n];
}
signed main() {
    cin.tie(0) -> sync_with_stdio(0);
    int _ = 1; //cin >> _;
    while(_ --) solve();
    return 0;
}