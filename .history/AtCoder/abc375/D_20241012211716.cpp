#pragma GCC optimize(1)
#pragma GCC optimize(2)
#pragma GCC optimize(3,"Ofast","inline")
#include<bits/stdc++.h>
#define int long long
using namespace std;
constexpr int INF = 0x7fffffff;
void solve() {
    string s; cin >> s;
    int n = s.size();
    vector<int> a[26], pre[26];
    for (int i = 0; i < 26; ++ i) a[i].emplace_back(0);
    for (int i = 0; i < n; ++ i)
        a[s[i] - 'A'].emplace_back(i);
    int ans = 0;
    for (int i = 0; i < 26; ++ i) {
        int m = a[i].size();
        if (m <= 1) continue;
        for (int j = 0; j < m; ++ j) {
            int p = lower_bound(a[i].begin() + j, a[i].end(), a[i][j] + 1) - a[i].begin();
            if (p == m) break;

        }
    }
    cout << ans << "\n";
    return;
}
signed main() {
    cin.tie(0) -> sync_with_stdio(0);
    int _ = 1; //cin >> _;
    while(_ --) solve();
    return 0;
}