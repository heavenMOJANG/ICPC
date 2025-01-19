#pragma GCC optimize(1)
#pragma GCC optimize(2)
#pragma GCC optimize(3,"Ofast","inline")
#include<bits/stdc++.h>
#define int long long
using namespace std;
constexpr int INF = 0x7fffffff;
void solve() {
    int n; cin >> n;
    map<int, int> mp1, mp2;
    for (int i = 0, x; i < n; ++ i) cin >> x, mp1[x] ++;
    for (int i = 0, x; i < n; ++ i) cin >> x, mp2[x] ++;
    vector<int> v1, v2;
    int tmp = 0;
    for (auto [a, b] : mp1)
        if (b == 2) v1.emplace_back(a);
        else tmp += a;
}
signed main() {
    cin.tie(0) -> sync_with_stdio(0);
    int _ = 1; cin >> _;
    while(_ --) solve();
    return 0;
}