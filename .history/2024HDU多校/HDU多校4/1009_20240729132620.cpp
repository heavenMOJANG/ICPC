#pragma GCC optimize(1)
#pragma GCC optimize(2)
#pragma GCC optimize(3,"Ofast","inline")
#include<bits/stdc++.h>
#define int long long
using namespace std;
constexpr int inf = 0x7fffffff;
void solve() {
    int n, m; cin >> n >> m;
    string s, t; cin >> s;
    for (int i = 1; i <= n; ++ i) {
        cin >> t;
        int p1 = 0, p2 = 0;
        while (p1 < t.size() && p2 < s.size()) {
            if (t[p1] == s[p2]) p1 ++;
            p2 ++;
        }
    }
    return;
}
signed main() {
    cin.tie(0) -> sync_with_stdio(0);
    int _ = 1; cin >> _;
    while(_ --) solve();
    return 0;
}