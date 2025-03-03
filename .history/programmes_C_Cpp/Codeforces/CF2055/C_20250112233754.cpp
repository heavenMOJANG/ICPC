#pragma GCC optimize(1)
#pragma GCC optimize(2)
#pragma GCC optimize(3, "Ofast", "inline")
#include <bits/stdc++.h>
#define int long long
using namespace std;
constexpr int INF = 0x7fffffff;
void solve() {
    int n, m; cin >> n >> m;
    string path; cin >> path;
    vector g(n, vector<int>(m));
    for (int i = 0; i < n; ++ i)
        for (int j = 0; j < m; ++ j) cin >> g[i][j];
    int gcd = __gcd(n, m), lcm = n / gcd * m;
    if (path[0] == 'R') {
        int sum{};
        for (int i = 1; i < n; ++ i) sum += g[i][0];
        g[0][0] = sum / lcm * lcm - sum;
        sum += g[0][0];
        
    } else {

    }
    return;
}
signed main() {
    cin.tie(0) -> sync_with_stdio(0);
    int _ = 1; //cin >> _;
    while(_ --) solve();
    return 0;
}