#pragma GCC optimize(1)
#pragma GCC optimize(2)
#pragma GCC optimize(3, "Ofast", "inline")
#include <bits/stdc++.h>
#define int long long
using namespace std;
constexpr int INF = 0x7fffffff;
void solve() {
    int n; cin >> n;
    string s, t; cin >> s >> t;
    unordered_map<char, char> mp;
    vector<vector<int>> g(26, vector<int> (26, INF));
    for (int i = 0; i < n; ++ i) {
        if (mp.count(s[i])) {
            if (mp[s[i]] != t[i]) { cout << "-1\n"; return; }
        } else {

        }
    }
    return;
}
signed main() {
    cin.tie(0) -> sync_with_stdio(0);
    int _ = 1; //cin >> _;
    while(_ --) solve();
    return 0;
}