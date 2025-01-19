#pragma GCC optimize(1)
#pragma GCC optimize(2)
#pragma GCC optimize(3,"Ofast","inline")
#include <bits/stdc++.h>
#define int long long
using namespace std;
constexpr int INF = 0x7fffffff;
void solve() {
    int n; cin >> n;
    string s; cin >> s;
    if (s[0] == '1' || s[n - 1] == '1') {cout << "YES\n"; return;}
    for (int i = 1; i < n; ++ i) if (s[i] == '1' && s[i - 1] == '1') {cout << "YES\n"; return;}
    cout << "NO\n"; 
    return;
}
signed main() {
    cin.tie(0) -> sync_with_stdio(0);
    int _ = 1; cin >> _;
    while(_ --) solve();
    return 0;
}