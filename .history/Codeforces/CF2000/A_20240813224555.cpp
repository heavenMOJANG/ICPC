#pragma GCC optimize(1)
#pragma GCC optimize(2)
#pragma GCC optimize(3,"Ofast","inline")
#include<bits/stdc++.h>
#define int long long
using namespace std;
constexpr int INF = 0x7fffffff;
void solve() {
    string s; cin >> s;
    if (s.substr(0, 2) != "10") {cout << "NO\n"; return;}
    int p = 2, res = 0;
    while (s[p] == '0') p ++;
    if (p != 2) {cout << "NO\n"; return;}
    while (p < s.size()) res = res * 10 + s[p ++] - '0';
    if (res >= 2) cout << "YES\n";
    else cout << "NO\n";
}
signed main() {
    cin.tie(0) -> sync_with_stdio(0);
    int _ = 1; cin >> _;
    while(_ --) solve();
    return 0;
}