#pragma GCC optimize(1)
#pragma GCC optimize(2)
#pragma GCC optimize(3,"Ofast","inline")
#include<bits/stdc++.h>
#define int long long
using namespace std;
constexpr int INF = 0x7fffffff;
void solve() {
    string s; cin >> s;
    int pl = -1;
    for (int i = 0; i < s.size(); ++ i)
        if (s[i] == '1') {pl = i; break;}
    if (pl == -1) {cout << "0\n"; return;}
    int pr;
    for (int i = s.size() - 1; ~i; -- i)
        if (s[i] == '1') {pr = i; break;}
    int ans = 0;
    for (int i = pl; i <= pr; ++ i) if (s[i] == '0') ans ++;
    cout << ans << "\n";
}
signed main() {
    cin.tie(0) -> sync_with_stdio(0);
    int _ = 1; cin >> _;
    while(_ --) solve();
    return 0;
}