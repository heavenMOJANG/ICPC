#pragma GCC optimize(3, "Ofast", "inline")
#include <bits/stdc++.h>
#define int long long
using namespace std;
constexpr int INF = 0x7fffffff;
void solve() {
    int n; cin >> n;
    string s; cin >> s; s = ' ' + s;
    vector<pair<char, int>> a;
    vector<int> pre0(n + 1, 0), pre1(n + 1, 0);
    for (int i = 1; i <= n; ++ i) {
        pre0[i] = pre0[i - 1] + (s[i] == '0');
        pre1[i] = pre1[i - 1] + (s[i] == '1');
    }
    a.emplace_back(s[1], 1);
    for (int i = 2; i <= n; ++ i)
        if (s[i] == a.back().first) a.back().second ++;
        else a.emplace_back(s[i], 1);
    int m = a.size();
    if (m <= 1) { cout << "0\n"; return; }
    int l{}, ans = INF;
    for (int i = 1; i <= m; ++ i) {
        int r = l + a[i].second - 1;
        if (a[i].first == '0') {
            int cost = pre1[l] + (pre0[n] - pre0[r]) * 2;
            ans = min(ans, cost);
        } else {
            int cost = pre0[l] + (pre1[n] - pre1[r]) * 2;
            ans = min(ans, cost);
        }
        l += a[i].second;
    }
    cout << ans << "\n";
    return;
}
signed main() {
    cin.tie(nullptr) -> sync_with_stdio(false);
    int _ = 1; cin >> _;
    while(_ --) solve();
    return 0;
}