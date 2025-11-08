#pragma GCC optimize(3, "Ofast", "inline")
#include <bits/stdc++.h>
#define int long long
using namespace std;
constexpr int INF = 0x7fffffff;
void solve() {
    int n, m; cin >> n >> m;
    vector<string> a(n);
    for (auto && x : a) cin >> x;
    map<string, int> mp;
    for (int i{}; i + m <= n; ++ i) {
        for (int j{}; j + m <= n; ++ j) {
            string s{};
            for (int x{}; x < m; ++ x)
                for (int y{}; y < m; ++ y) s += a[i + x][j + y];
            mp[s] ++;
        }
    }
    cout << mp.size() << "\n";
    return;
}
signed main() {
    cin.tie(nullptr) -> sync_with_stdio(false);
    int _ = 1; //cin >> _;
    while(_ --) solve();
    return 0;
}