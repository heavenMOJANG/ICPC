#pragma GCC optimize(1)
#pragma GCC optimize(2)
#pragma GCC optimize(3,"Ofast","inline")
#include<bits/stdc++.h>
#define int long long
using namespace std;
constexpr int INF = 0x7fffffff;
void solve() {
    int n, k; cin >> n >> k;
    vector<int> a(n), b(n);
    for (int i = 0; i < n; ++ i) cin >> a[i];
    sort(a.begin(), a.end());
    set<int> s;
    for (int i = 0; i < n; ++ i) b[i] = a[i] % (2 * k), s.insert(b[i]);
    if (s.size() == 1) {cout << a[n - 1] << "\n"; return;}
    vector<int> c;
    for(auto x : s) c.emplace_back(x);
    int m = c.size(), l = c[0], r = c[m - 1];
    for (int i = 0; i < m; ++ i) {
        if (r - l < k) {
            cout << a[n - 1] + r - b[n - 1] << "\n";
            return;
        } else l = c[i + 1], r = c[i] + 2 * k;
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