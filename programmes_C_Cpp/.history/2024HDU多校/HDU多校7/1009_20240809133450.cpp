#pragma GCC optimize(1)
#pragma GCC optimize(2)
#pragma GCC optimize(3,"Ofast","inline")
#include<bits/stdc++.h>
#define int long long
using namespace std;
constexpr int INF = 0x7fffffff;
void solve() {
    int n, k; cin >> n >> k;
    vector<int> t(n + 1, 0), isMat(n + 1, 0);
    vector<pair<int, int>> g[n + 1];
    map<pair<int, int>, int> mp;
    for (int i = 1; i <= n; ++ i) {
        int p, tt; cin >> p >> tt;
        if (p == 1) {
            for (int j = 0; j < tt; ++ j) {
                int x, a; cin >> x >> a;
                g[i].emplace_back(a, x);
            }
        } else {
            t[i] = tt;
        }
    }

}
signed main() {
    cin.tie(0) -> sync_with_stdio(0);
    int _ = 1; //cin >> _;
    while(_ --) solve();
    return 0;
}