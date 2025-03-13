#pragma GCC optimize(1)
#pragma GCC optimize(2)
#pragma GCC optimize(3, "Ofast", "inline")
#include <bits/stdc++.h>
#define int long long
using namespace std;
constexpr int INF = 0x7fffffff;
void solve() {
    int n, m; cin >> n >> m;
    vector<int> b(n), w(m);
    for (auto && x : b) cin >> x;
    for (auto && x : w) cin >> x;
    sort(b.begin(), b.end(), greater<int>());
    sort(w.begin(), w.end(), greater<int>());
    if (m > n) m = n;
    int maxn{};
    int p{}, q{}, sum{};
    while (p < n && sum + b[p] >= sum) sum += b[p ++];
    cout << sum << "\n";
    while (p < n && q < m) {
        if (q < p) {
            if (sum + w[q] >= sum) sum += b[q ++];
            else break;
        } else if (q == p) {
            if (sum + b[p] + w[q] >= sum) sum += w[p ++] + b[q ++];
            else break;
        }
    }
    cout << max(maxn, sum) << "\n";
    return;
}
signed main() {
    cin.tie(0) -> sync_with_stdio(0);
    int _ = 1; //cin >> _;
    while(_ --) solve();
    return 0;
}