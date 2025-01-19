#pragma GCC optimize(1)
#pragma GCC optimize(2)
#pragma GCC optimize(3,"Ofast","inline")
#include<bits/stdc++.h>
#define int long long
using namespace std;
constexpr int INF = 0x7fffffff;
void solve() {
    int n, q; cin >> n >> q;
    map<char, vector<int>> mp = {
        {'B', vector<int>()},
        {'G', vector<int>()},
        {'R', vector<int>()},
        {'Y', vector<int>()}
    };
    for (int i = 1; i <= n; ++ i) {
        string s; cin >> s;
        [s[0]].push_back(i);
        portals[s[1]].push_back(i);
    }
}
signed main() {
    cin.tie(0) -> sync_with_stdio(0);
    int _ = 1; //cin >> _;
    while(_ --) solve();
    return 0;
}