#pragma GCC optimize(1)
#pragma GCC optimize(2)
#pragma GCC optimize(3,"Ofast","inline")
#include<bits/stdc++.h>
#define int long long
using namespace std;
constexpr int INF = 0x7fffffff;
void solve() {
    string s, t; cin >> s >> t;
    int ps = 0, pt = 0;
    while (ps < s.size()) {
        if (s[ps] == t[pt] || s[ps] == '?') ps ++, pt ++;
        else ps ++;
    }
    if (pt < t.size()) cout << "NO\n";
    else cout << "YES\n";
    return;
}
signed main() {
    cin.tie(0) -> sync_with_stdio(0);
    int _ = 1; cin >> _;
    while(_ --) solve();
    return 0;
}