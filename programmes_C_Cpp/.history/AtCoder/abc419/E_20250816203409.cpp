#pragma GCC optimize(3, "Ofast", "inline")
#include <bits/stdc++.h>
#define int long long
using namespace std;
constexpr int INF = 0x7fffffff;
void solve() {
    int n, m, l; cin >> n >> m >> l;
    vector<int> a(n); for (auto && x : a) cin >> x;
    vector cnt(l, vector<int> (m, 0)), need = cnt;
    for (int i{}; i < n; ++ i) cnt[i % l][a[i] % m] ++;
    for (int i{}; i < l; ++ i)
        for (int j{}; j < m; ++ j) {
            int res{};
            for (int k{}; k < m; ++ k) res += (j - k + m) % m * cnt[i][k];
            need[i][j] = res;
        }
    vector<int> dp(m, INF), ndp = np;
    
    return;
}
signed main() {
    cin.tie(nullptr) -> sync_with_stdio(false);
    int _ = 1; //cin >> _;
    while(_ --) solve();
    return 0;
}