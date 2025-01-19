#pragma GCC optimize(1)
#pragma GCC optimize(2)
#pragma GCC optimize(3, "Ofast", "inline")
#include <bits/stdc++.h>
#define int long long
using namespace std;
constexpr int INF = 0x7fffffff;
void solve() {
    string s; cin >> s;
    int n = s.size();
    if (n < 2) { cout << "-1\n"; return; }
    for (int i = 0; i < n - 1; ++ i) {
        if (s[i] == s[i + 1]) { cout << s[i] << s[i + 1] << "\n"; return; }
        if (i + 2 < n && s[i] != s[i + 1] && s[i + 1] != s[i + 2] && s[i] != s[i + 2]) { cout << s.substr(i, 3) << "\n"; return; }
    }
    return;
}
signed main() {
    cin.tie(0) -> sync_with_stdio(0);
    int _ = 1; //cin >> _;
    while(_ --) solve();
    return 0;
}