#pragma GCC optimize(1)
#pragma GCC optimize(2)
#pragma GCC optimize(3, "Ofast", "inline")
#include <bits/stdc++.h>
#define int long long
using namespace std;
constexpr int INF = 0x7fffffff;
void solve() {
    int n; cin >> n;
    set<int> s[n + 1];
    for (int i = 1; i <= n; ++ i) {
        int k; cin >> k;
        for (int j = 0; j < k; ++ j) {
            int x; cin >> x;
            s[i].insert(x);
        }
    }
    int q; cin >> q;
    while (q --) {
        int a, b; cin >> a >> b;
        int t = s[a].size() + s[b].size(), cnt{};
        for (auto x : s[a]) if (s[a].find(x) != s[a].end()) cnt ++; 
    }
    return;
}
signed main() {
    cin.tie(0) -> sync_with_stdio(0);
    int _ = 1; //cin >> _;
    while(_ --) solve();
    return 0;
}