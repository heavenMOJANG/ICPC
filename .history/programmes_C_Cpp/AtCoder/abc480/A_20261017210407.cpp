#pragma GCC optimize(3, "Ofast", "inline")
#include <bits/stdc++.h>
#define int long long
using namespace std;
constexpr int INF = 0x7fffffff;
void solve() {
    string s0, s1; cin >> s0 >> s1;
    for (char c : s0) if (c == 'A') c = '0';
    for (char c : s1) if (c == 'A') c = '0';
    cout << (s0[0] == s0[1] || s0[0] == s1[0] || s1[0] == s1[1] || s0[1] == s1[1] ? "Yes\n" : "No\n");
    return;
}
signed main() {
    cin.tie(nullptr) -> sync_with_stdio(false);
    int _ = 1; //cin >> _;
    while(_ --) solve();
    return 0;
}