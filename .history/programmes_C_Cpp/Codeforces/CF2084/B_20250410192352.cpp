#pragma GCC optimize(1)
#pragma GCC optimize(2)
#pragma GCC optimize(3, "Ofast", "inline")
#include <bits/stdc++.h>
#define int long long
using namespace std;
constexpr int INF = 0x7fffffff;
void solve() {
    int n; cin >> n;
    int minn = LLONG_MAX;
    vector<int> a(n);
    for (int i{}; i < n; ++ i) cin >> a[i], minn = min(minn, a[i]);
    multiset<int> s;
    for (int i{}; i < n; ++ i) if (a[i] % minn == 0) s.insert(a[i]);
    s.erase(s.begin());
    for (auto x : s) cout << x << " ";
    cout << "\n";
    if (s.empty()) { cout << "No\n"; return; }
    int g = *s.begin();
    for (auto x : s) g = __gcd(g, x);
    cout << (g == minn ? "Yes\n" : "No\n"); 
    return;
}
signed main() {
    cin.tie(0) -> sync_with_stdio(0);
    int _ = 1; cin >> _;
    while(_ --) solve();
    return 0;
}