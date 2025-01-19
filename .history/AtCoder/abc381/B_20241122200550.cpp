#pragma GCC optimize(1)
#pragma GCC optimize(2)
#pragma GCC optimize(3, "Ofast", "inline")
#include <bits/stdc++.h>
#define int long long
using namespace std;
constexpr int INF = 0x7fffffff;
void solve() {
    string s; cin >> s;
    if (s.size() & 1) { cout << "No\n"; return; }
    map<char, int> mp;
    for (auto ch : s) mp[ch] ++;
    for (int i = 0; i < s.size(); i += 2)
        if (s[i] != s[i + 1] || mp[s[i]] != 2) { cout << "No\n"; return; }
    cout << "Yes\n";
    return;
}
signed main() {
    cin.tie(0) -> sync_with_stdio(0);
    int _ = 1; //cin >> _;
    while(_ --) solve();
    return 0;
}