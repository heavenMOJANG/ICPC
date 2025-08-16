#pragma GCC optimize(3, "Ofast", "inline")
#include <bits/stdc++.h>
#define int long long
using namespace std;
constexpr int INF = 4e18;
void solve() {
    struct INTERVAL { int L, R, A, B; };
    int n; cin >> n;
    vector<int> P(n), A(n), B(n);
    for (int i{}; i < n; ++ i) cin >> P[i] >> A[i] >> B[i];
    vector<INTERVAL> seg, nxt;
    seg.emplace_back(0ll, INF, 1ll, 0ll);
    for (int i{}; i < n; ++ i) {
        nxt.clear();
        for (auto s : seg) {
            auto [L, R, a, b] = s;
            if (a == 1) {
                int d0 = P[i] - b;
                if (L <= d0) nxt.emplace_back(L, min(R, d0), 1ll, b + A[i]);
                int dl = max(L, d0 + 1);
                if (dl <= R) {
                    int d1 = B[i] - b - 1;
                    if (dl <= d1) nxt.emplace_back(dl, min(R, d1), 0ll, 0ll);
                    int d2 = max(dl, d1 + 1);
                    if (d2 <= R) nxt.emplace_back(d2, R, 1ll, b - B[i]); 
                }
            } else {
                if (b <= P[i]) nxt.emplace_back(L, R, 0ll, b + A[i]);
                else {
                    int d = b - B[i];
                    if (d > 0) nxt.emplace_back(L, R, 0ll, d);
                    else nxt.emplace_back(L, R, 0ll, 0ll);
                }
            }
            seg.clear();
            for (auto s : nxt)
                if (seg.empty() || seg.back().A != s.A || seg.back().B != s.B || seg.back().R + 1 != s.L)
                    seg.emplace_back(s);
                else seg.back().R = s.R;
        }
    }
    int q; cin >> q;
    while (q --) {
        int x; cin >> x;
        int l{}, r = seg.size() - 1;
        while (l < r) {
            int mid = l + r >> 1;
            if (seg[mid].R < x) l = mid + 1;
            else r = mid;
        }
        int ans = seg[l].A ? x + seg[l].B : seg[l].B;
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