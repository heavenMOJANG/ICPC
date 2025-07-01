#pragma GCC optimize(1)
#pragma GCC optimize(2)
#pragma GCC optimize(3, "Ofast", "inline")
#include <bits/stdc++.h>
#define int long long
using namespace std;
constexpr int INF = 0x7fffffff;
void solve() {
    string s; cin >> s;
    vector<int> a(26, 0);
    for (int i{}; i < s.size(); ++ i) a[s[i] - 'a'] ++;
    for (int i{}; i < 26; ++ i) if (!vis[i]) { cout << char('a' + i) << "\n"; break; }
    return;
}
signed main() {
    cin.tie(0) -> sync_with_stdio(0);
    int _ = 1; //cin >> _;
    while(_ --) solve();
    return 0;
}