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
    set<int> s;
    for (int i = 0; i < n; ++ i) s.insert(a[i] % (2 * k));
    int l = *s.begin(), r = *(--s.end());
    for (auto it = s.begin(); it != (--s.end()); ++ it) {
        if (r - l < k) {
            cout << a[n - 1] + r - *(--s.end()) << "\n";
            return;
        } else l = b[i + 1], r = *it + 2 * k;
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