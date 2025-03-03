#pragma GCC optimize(1)
#pragma GCC optimize(2)
#pragma GCC optimize(3, "Ofast", "inline")
#include <bits/stdc++.h>
#define int long long
using namespace std;
constexpr int INF = 0x7fffffff;
void solve() {
    int n, m; cin >> n >> m;
    vector<int> a(n), b(m);
    int tot{};
    for (int i = 0; i < n; ++ i) cin >> a[i], tot += a[i] > 1;
    for (int i = 0; i < m; ++ i) cin >> b[i];
    sort(a.begin(), a.end());
    sort(b.begin(), b.end());
    int p{}, q{}, k{};
    while (q < m) {
        while (p < n || q < m) {
            if (p < n && a[p] < k) p ++, k ++;
            else if (j < m && b[q] <= k) q ++, k ++;
            else break;
        }
        if (q < m) {
            if (tot >= b[q] - k) {
                tot -= b[q] - k, b[q] = k;
                q ++, k ++;
            } else break;
        }
    }
    cout << (q == m ? "YES\n" : "NO\n");
    return;
}
signed main() {
    cin.tie(0) -> sync_with_stdio(0);
    int _ = 1; cin >> _;
    while(_ --) solve();
    return 0;
}