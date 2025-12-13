#pragma GCC optimize(3, "Ofast", "inline")
#include <bits/stdc++.h>
#define int long long
using namespace std;
constexpr int INF = 0x7fffffff;
void solve() {
    int n; cin >> n;
    vector<int> a(n + 1), p(n + 1);
    for (int i = 1; i <= n; ++ i) cin >> a[i], p[a[i]] = i;
    set<int> s;
    int ans{};
    for (int i = 1; i <= n; ++ i) {
        int x = p[i];
        auto it = s.lower_bound(x);
        int r = (it == s.end() ? n + 1 : *it);
        int l = (it == s.begin() ? 0ll : *-- it);
        ans += (x - l) * (r - x);
        s.insert(x);
    }
    cout << ans << "\n";
    return;
}
signed main() {
    cin.tie(nullptr) -> sync_with_stdio(false);
    int _ = 1; //cin >> _;
    while(_ --) solve();
    return 0;
}