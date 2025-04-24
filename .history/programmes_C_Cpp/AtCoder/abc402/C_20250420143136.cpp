#pragma GCC optimize(1)
#pragma GCC optimize(2)
#pragma GCC optimize(3, "Ofast", "inline")
#include <bits/stdc++.h>
#define int long long
using namespace std;
constexpr int INF = 0x7fffffff;
void solve() {
    unordered_map<int, vector<int>> mp;
    unordered_set<int> ans;
    int n, m; cin >> n >> m;
    for (int i = 1; i <= m; ++ i) {
        int k; cin >> k;
        for (int j{}; j < k; ++ j) {
            int x; cin >> x;
            mp[x].emplace_back(i);
        }
    }
    return;
}
signed main() {
    cin.tie(0) -> sync_with_stdio(0);
    int _ = 1; //cin >> _;
    while(_ --) solve();
    return 0;
}