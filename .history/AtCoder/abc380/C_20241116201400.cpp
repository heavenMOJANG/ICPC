#pragma GCC optimize(1)
#pragma GCC optimize(2)
#pragma GCC optimize(3, "Ofast", "inline")
#include <bits/stdc++.h>
#define int long long
using namespace std;
constexpr int INF = 0x7fffffff;
void solve() {
    int n, k; cin >> n >> k;
    string s; cin >> s;
    cout << s << "\n";
    vector<string> ans;
    string t;
    cout << t << "\n";
    for (int i = 1; i < n; ++ i) {
        if (s[i] != s[i - 1]) ans.emplace_back(t), t = s[i];
        else t += s[i];
    }
    if (t != "") ans.emplace_back(t);
    int cnt = 1;
    for (int i = 0; i < ans.size(); ++ i) {
        if (cnt == k - 1) cout << ans[i] << ans[i + 2] << ans[i + 1], i += 3;
        else {
            if (ans[i][0] == '1') cnt ++;
            cout << ans[i];
        }
    }
    cout << "\n";
    return;
}
signed main() {
    cin.tie(0) -> sync_with_stdio(0);
    int _ = 1; //cin >> _;
    while(_ --) solve();
    return 0;
}