#pragma GCC optimize(1)
#pragma GCC optimize(2)
#pragma GCC optimize(3,"Ofast","inline")
#include<bits/stdc++.h>
#define int long long
using namespace std;
constexpr int INF = 0x7fffffff;
void solve() {
    int n; cin >> n;
    string s; cin >> s;
    map<char, int> mp;
    for (int i = 0; i < 4 * n; ++ i) {
        mp[s[i]] ++;
    }
    int ans = 0;
    for (char c = 'A'; c <= 'D'; ++ c) {
        ans += max(mp[c], n);
    }
    cout << ans << "\n";
    return;
}
signed main() {
    cin.tie(0) -> sync_with_stdio(0);
    int _ = 1; cin >> _;
    while(_ --) solve();
    return 0;
}