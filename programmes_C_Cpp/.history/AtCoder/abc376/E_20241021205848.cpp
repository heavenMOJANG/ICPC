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
    vector<pii> a(n + 1);
    for (int i = 1; i <= n; ++ i) cin >> a[i].first;
    for (int i = 1; i <= n; ++ i) cin >> a[i].second;
    sort(a.begin(), a.end());
    priority_queue<int, vector<int>, greater<int>> pq;
    int ans = LLONG_MAX, sum{};
    for (int i = 1; i <= n; ++ i) {
        if (pq.size() == k - 1) ans = min(ans, a[i].first * (sum + a[i].second));
        pq.push(-a[i].second);
        sum += a[i].second;
        if (pq.size() > k - 1) sum -= -pq.top(), pq.pop();
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