#pragma GCC optimize(3, "Ofast", "inline")
#include <bits/stdc++.h>
#define int long long
using namespace std;
constexpr int INF = 0x7fffffff;
void solve() {
    int n; cin >> n;
    string s, t; cin >> s >> t;
    for (int i{}; i < n; ++ i) {
        if (s[i] == 'o' && t[i] == 'o') { cout << "Yes\n"; return; }
    }
    cout << "No\n";
    return;
}
signed main() {
    cin.tie(0) -> sync_with_stdio(0);
    int _ = 1; //cin >> _;
    while(_ --) solve();
    return 0;
}