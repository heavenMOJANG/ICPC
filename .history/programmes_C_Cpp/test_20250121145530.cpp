#pragma GCC optimize(1)
#pragma GCC optimize(2)
#pragma GCC optimize(3, "Ofast", "inline")
#include <bits/stdc++.h>
#define int long long
using namespace std;
constexpr int INF = 0x7fffffff;
void solve() {
    int n; cin >> n;
    map<int, int> mp;
    vector<int> a(n);
    for (int i = 0; i < n; ++ i) cin >> a[i], mp[a[i]] ++;
    int ans{};
    for (int i = 0; i < n; ++ i) {
        vector<int> f;
        for (int j = 1; j <= sqrt(a[i]); ++ j) {
            if (a[i] % j == 0) f.emplace_back(j);
            if (j * j != a[i]) f.emplace_back(a[i] / j);
        }
        for (auto x : f) {
            int b = a[i] ^ x;
            if (mp[b] && __gcd(a, b) == x) {
                if (a[i] == b) ans += mp[b] - 1;
                else ans += mp[b];
            }
        }
    }
    cout << ans / 2 << "\n";
    return;
}
signed main() {
    cin.tie(0) -> sync_with_stdio(0);
    int _ = 1; //cin >> _;
    while(_ --) solve();
    return 0;
}