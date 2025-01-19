#pragma GCC optimize(1)
#pragma GCC optimize(2)
#pragma GCC optimize(3,"Ofast","inline")
#include<bits/stdc++.h>
#define int long long
using namespace std;
constexpr int INF = 0x7fffffff;
void solve() {
    int n; cin >> n;
    map<string, int> mp1, mp2;
    vector<pair<string, int>> v;
    int maxn = 0;
    for (int i = 0; i < n; ++ i) {
        string s; int x; cin >> s >> x;
        v
        mp1[s] += x;
        maxn = max(maxn, mp1[s]);
    }
    for (int i = 0; i < n; ++ i) {

    }
}
signed main() {
    cin.tie(0) -> sync_with_stdio(0);
    int _ = 1; //cin >> _;
    while(_ --) solve();
    return 0;
}