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
    set<int> s;
    for (int i{}; i < n; ++ i) if (a[i] % minn == 0) s.insert(a[i]);
    s.erase(s.begin());
    if (s.empty()) { cout << "No\n"; return; }
     
    return;
}
signed main() {
    cin.tie(0) -> sync_with_stdio(0);
    int _ = 1; //cin >> _;
    while(_ --) solve();
    return 0;
}