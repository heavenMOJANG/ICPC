#pragma GCC optimize(3, "Ofast", "inline")
#include <bits/stdc++.h>
#define int long long
using namespace std;
constexpr int INF = 4e18;
void solve() {
    int n; cin >> n;
    vector<int> p(n), a(n), b(n);
    for (int i{}; i < n; ++ i) cin >> p[i] >> a[i] >> b[i];
    map<int, pair<int, int>> mp; // f(m) = a * m + b in [L, LL - 1] -> map<L, (a, b)>
    mp[0] = {1, 0};
    for (int i{}; i < n; ++ i) {
        map<int, pair<int, int>> nxt;
        for (auto it = mp.begin(); it != mp.end(); ++ it) {
            int l = it -> first;
            auto [A, B] = it -> second;
            auto itt = next(it);
            int r = itt == mp.end() ? INF : (itt -> first - 1);
            if (A == 1) {
                int d0 = p[i] - B;
                if (l <= d0) {
                    int r1 = min(r, d0);
                    nxt[l] = {1, B + a[i]};
                }
                int dl = max(l, d0 + 1);
                if (dl <= r) {
                    int d1 = b[i] - B - 1;
                    if (dl <= d1) nxt[dl] = {0, 0};
                    int d2 = max(dl, d1 + 1);
                    if (d2 <= r) nxt[d2] = {1, B - b[i]};
                }
            } else {
                if (B <= p[i]) nxt[l] = {0, B + a[i]};
                else nxt[l] = {0, max(0ll, B - b[i])};
            }
        }
        mp.clear();
        for (auto [l, pii] : nxt)
            if (mp.empty()) mp[l] = pii;
            else {
                auto it = prev(mp.end());
                if (it -> second != pii) mp[l] = pii;
            }
    }
    int q; cin >> q;
    while(q --) {
        int x; cin >> x;
        auto it = mp.upper_bound(x);
        -- it;
        auto [A, B] = it -> second;
        int ans = A ? x + B : B;
        cout << ans << "\n";
    }
    return;
}
signed main() {
    cin.tie(nullptr) -> sync_with_stdio(false);
    int _ = 1; //cin >> _;
    while(_ --) solve();
    return 0;
}