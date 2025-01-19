#pragma GCC optimize(1)
#pragma GCC optimize(2)
#pragma GCC optimize(3,"Ofast","inline")
#include<bits/stdc++.h>
#define int long long
using namespace std;
using ull = unsigned long long;
constexpr int inf = 0x7fffffff;
mt19937_64 rng {
    chrono::steady_clock::now().time_since_epoch().count();
};
void solve() {
    int n, m; cin >> n >> m;
    vector<ull> h(n);
    for (int i = 0, a, b; i < n; ++ i) {
        cin >> a >> b;
        a --, b --;
        ull x = rng();
        h[a] ^= x; h[b] ^= x;
    }
    for (int i = 1; i < n; ++ i) h[i] ^= h[i - 1];
    map<ull, int> mp;
    int maxn = 0;
    for (int i = 0; i < n; ++ i) maxn = max(maxn, ++ mp[h[i]]);
    cout << n - maxn << "\n";
    return;
}
signed main() {
    cin.tie(0) -> sync_with_stdio(0);
    int _ = 1; cin >> _;
    while(_ --) solve();
    return 0;
}