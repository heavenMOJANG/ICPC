#pragma GCC optimize(1)
#pragma GCC optimize(2)
#pragma GCC optimize(3,"Ofast","inline")
#include<bits/stdc++.h>
#define int long long
using namespace std;
constexpr int INF = 0x7fffffff;
void solve() {
    int n, k; cin >> n >> k;
    vector<int> a(n), b(n), c(n);
    for (int i = 0; i < n; ++ i) cin >> a[i];
    sort(a.begin(), a.end());
    for (int i = 0; i < n; ++ i) b[i] = a[i] % (2 * k);
    int l = b[0], r = b[n - 1];
    for (int i = 0; i < n - 1; ++ i) {
        if (r - l < k) {
            cout << a[n - 1] + r - b[n - 1] << "\n";
            return;
        } else l = r, r = b[i] + 2 * k;
    }
    cout << "-1\n";
    return;
}
signed main() {
    cin.tie(0) -> sync_with_stdio(0);
    int _ = 1; cin >> _;
    while(_ --) solve();
    return 0;
}