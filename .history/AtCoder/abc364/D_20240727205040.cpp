#pragma GCC optimize(1)
#pragma GCC optimize(2)
#pragma GCC optimize(3,"Ofast","inline")
#include<bits/stdc++.h>
#define int long long
using namespace std;
constexpr int inf = 0x7fffffff;
void solve() {
    int n, q; cin >> n >> q;
    vector<int> a(n);
    map<int, int> mp;
    for (int i = 0; i < n; ++ i) cin >> a[i];
    sort (a.begin(), a.end());
    while (q --) {
        int b, k; cin >> b >> k;
    }
    return;
}
signed main() {
    cin.tie(0) -> sync_with_stdio(0);
    int _ = 1; //cin >> _;
    while(_ --) solve();
    return 0;
}