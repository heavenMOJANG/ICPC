#pragma GCC optimize(1)
#pragma GCC optimize(2)
#pragma GCC optimize(3, "Ofast", "inline")
#include <bits/stdc++.h>
#define int long long
using namespace std;
constexpr int INF = 0x7fffffff;
void solve() {
    int n; cin >> n;
    string s, t; cin >> s >> t;
    s = " " + s, t = " " + t;
    vector<int> cnt(2, 0);
    for (int i = 1; i <= n; i += 2) {
        if (s[i] == '0') cnt[1] ++;
        if (t[i] == '0') cnt[0] ++;
    }
    for (int i = 2; i <= n; i += 2) {
        if (s[i] == '0') cnt[0] ++;
        if (t[i] == '0') cnt[1] ++;
    }
    if (cnt[1] < n - n / 2) { cout << "NO\n"; return; }
    if (cnt[0] < n / 2) { cout << "NO\n"; return; }
    cout << "YES\n";
    return;
}
signed main() {
    cin.tie(0) -> sync_with_stdio(0);
    int _ = 1; cin >> _;
    while(_ --) solve();
    return 0;
}