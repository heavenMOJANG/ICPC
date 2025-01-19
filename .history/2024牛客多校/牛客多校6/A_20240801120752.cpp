#pragma GCC optimize(1)
#pragma GCC optimize(2)
#pragma GCC optimize(3,"Ofast","inline")
#include<bits/stdc++.h>
#define int long long
using namespace std;
constexpr int INF = 0x7fffffff;
void solve() {
    string s;cin >> s;
    int n = s.size();
    int cnt3 = 0, cnt4 = 0, cnt5 = 0, cntu = 0;
    for (int i = 1; i <= n; ++ i) {
        if (s[i] == '3') cnt3 ++;
        if (s[i] == '4') cnt4 ++;
        if (s[i] == '5') cnt5 ++;
        if (s[i] == 'U') cntu ++;
    }
    return;
}
signed main() {
    cin.tie(0) -> sync_with_stdio(0);
    int _ = 1; cin >> _;
    while(_ --) solve();
    return 0;
}