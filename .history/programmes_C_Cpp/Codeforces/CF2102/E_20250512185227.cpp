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
    for (int i{}; i < n; ++ i) cin >> a[i].first;
    set<int> s;
    int ans{}, p{};
    for (int i = n; i; -- i) {
        while (p < n && a[p].first >= i) s.insert(a[p ++].second);
        if (s.size() >= 2) {
            auto l = s.begin(), r = prev(s.end());
            ans += *r - *l;
            s.erase(l);
            s.erase(r);
        }
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