#pragma GCC optimize(1)
#pragma GCC optimize(2)
#pragma GCC optimize(3,"Ofast","inline")
#include <bits/stdc++.h>
#define int long long
#define pii pair<int, int>
using namespace std;
constexpr int INF = 0x7fffffff;
void solve() {
    int n, k; cin >> n >> k;
    map<int, int> mp;
    for (int i = 0, x; i < n; ++ i) cin >> x, mp[x] ++;
    priority_queue<pii, vector<pii>, greater<>> pq;
    for (auto it = mp.begin(); it != mp.end(); ++ it) pq.push({it -> first, it -> second});
    int ans{}, cnt{};
    while (!pq.empty()) {
        auto [x, y] = pq.top();
        x -= cnt;
        int d = min(k, x * (int)pq.size());
        k -= d;
        ans += d;
        if (!k) {cout << ans << "\n"; return;}
        n -= y;
        ans += n;
        cnt += x;
        pq.pop();
        cout << ans << "\n";
    }
    cout << ans << "\n";
    return;
}
signed main() {
    cin.tie(0) -> sync_with_stdio(0);
    int _ = 1; cin >> _;
    while(_ --) solve();
    return 0;
}