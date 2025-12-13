#pragma GCC optimize(3, "Ofast", "inline")
#include <bits/stdc++.h>
#define int long long
using namespace std;
constexpr int INF = 0x7fffffff;
void solve() {
    int n; cin >> n;
    vector<int> a(n + 1);
    cin >> a[1];
    for (int i = 2; i <= n; ++ i) a[i] = (a[i - 1] * 3703 + 1047) % n + 1;
    map<int, int> mp;
    int cnt{};
    for (int i = 1; i <= n; ++ i) {
        cnt ++;
        mp[a[i]] += cnt > 4 ? 4ll : cnt;
        if (i == n || a[i] != a[i + 1]) cnt = 0;
    }
    int ans{}, maxn{};
    for (map<int, int> :: iterator it = mp.begin(); it != mp.end(); ++ it) {
        int k = it -> first, v = it -> second;
        if (v > maxn) {
            maxn = v;
            ans = k;
        } else if (v == maxn) ans = min(ans, k);
    }
    cout << ans << "\n";
    return;
}
signed main() {
    cin.tie(nullptr) -> sync_with_stdio(false);
    int _ = 1; //cin >> _;
    while(_ --) solve();
    return 0;
}