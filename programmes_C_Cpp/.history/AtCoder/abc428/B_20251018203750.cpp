#pragma GCC optimize(3, "Ofast", "inline")
#include <bits/stdc++.h>
#define int long long
using namespace std;
constexpr int INF = 0x7fffffff;
void solve() {
    int n, k; string s; cin >> n >> k >> s;
    int maxn{};
    map<string, int> mp;
    for (int i{}; i + k < n; ++ i) {
        string t = s.substr(i, k);
        int cnt{};
        for (int j{}; j + k < n; j ++) if (s.substr(j, k) == t) ++ cnt;
        mp[t] = cnt;
        maxn = max(maxn, cnt);
    }
    vector<string> ans;
    for (auto [x, y] : mp) if (y == maxn) ans.push_back(x);
    sort(ans.begin(), ans.end());
    for (int i{}; i < ans.size(); ++ i) cout << ans[i] << " \n"[i + 1 == ans.size()];
    return;
}
signed main() {
    cin.tie(nullptr) -> sync_with_stdio(false);
    int _ = 1; //cin >> _;
    while(_ --) solve();
    return 0;
}