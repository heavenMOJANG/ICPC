#pragma GCC optimize(3, "Ofast", "inline")
#include <bits/stdc++.h>
#define int long long
using namespace std;
constexpr int INF = 0x7fffffff;
void solve() {
    int n, m; cin >> n >> m;
    vector<int> A(n), B(n);
    for (auto && x : A) cin >> x;
    for (auto && x : B) cin >> x;
    multiset<int> ms(A.begin(), A.end());
    int ans{};
    for (int b : B) {
        auto p = ms.lower_bound(m - b);
        if (p == ms.end()) p = ms.begin(), ans += *p + b;
        else {
            int wp = *p + b - m, nwp = *ms.begin() + b;
            if (wp <= nwp) ans += wp;
            else ans += nwp, p = ms.begin();
        }
        ms.erase(p);
    }
    cout << ans << "\n";
    return;
}
signed main() {
    cin.tie(nullptr) -> sync_with_stdio(false);
    int _ = 1; cin >> _;
    while(_ --) solve();
    return 0;
}