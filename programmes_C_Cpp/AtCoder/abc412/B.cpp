#pragma GCC optimize(3, "Ofast", "inline")
#include <bits/stdc++.h>
#define int long long
using namespace std;
constexpr int INF = 0x7fffffff;
void solve() {
    string s, t; cin >> s >> t;
    int ans = 1;
    for (int i = 1; i < s.size(); ++ i)
        if ('A' <= s[i] && s[i] <= 'Z')
            if (t.find(s[i - 1]) == -1) ans = 0;
    cout << (ans ? "Yes\n" : "No\n");
    return;
}
signed main() {
    cin.tie(0) -> sync_with_stdio(0);
    int _ = 1; //cin >> _;
    while(_ --) solve();
    return 0;
}