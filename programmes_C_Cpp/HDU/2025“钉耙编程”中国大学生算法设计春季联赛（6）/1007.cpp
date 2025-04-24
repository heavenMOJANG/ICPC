#pragma GCC optimize(1)
#pragma GCC optimize(2)
#pragma GCC optimize(3, "Ofast", "inline")
#include <bits/stdc++.h>
#define int long long
using namespace std;
constexpr int INF = 0x7fffffff;
void solve() {
    int n; cin >> n;
    vector<int> a(n + 1);
    for (int i = 1; i <= n; ++ i) cin >> a[i];
    string s; cin >> s; s = " " + s;
    vector<int> r, b;
    for (int i = 1; i <= n; ++ i)
        if (s[i] == 'R') r.emplace_back(a[i]);
        else b.emplace_back(a[i]);
    sort(r.begin(), r.end(), greater<int>());
    sort(b.begin(), b.end(), greater<int>());
    int len = min(r.size(), b.size());
    int ans{};
    for (int i{}; i < len; ++ i) ans += r[i] + b[i];
    if (r.size() > len) ans += r[len];
    cout << ans << "\n";
    return;
}
signed main() {
    cin.tie(0) -> sync_with_stdio(0);
    int _ = 1; cin >> _;
    while(_ --) solve();
    return 0;
}