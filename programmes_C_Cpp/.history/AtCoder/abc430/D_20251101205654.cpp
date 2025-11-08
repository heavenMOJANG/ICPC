#pragma GCC optimize(3, "Ofast", "inline")
#include <bits/stdc++.h>
#define int long long
using namespace std;
constexpr int INF = 0x7fffffff;
void solve() {
    int n; cin >> n;
    vector<int> X(n);
    for (auto && x : X) cin >> x;
    set<int> s; s.insert(0);
    int ans{};
    for (int i{}; i < n; ++ i) {
        auto iR = s.lower_bound(X[i]);
        auto iL = (iR == s.begin() ? s.end() : prev(iR));
        int dL = iL != s.end() ? X[i] - *iL : INF, dR = iR != s.end() ? *iR - X[i] : INF;
        int d = min(dL, dR);
        ans += d;
        if (iL != s.end()) {
            auto iLL = iL == s.begin() ? s.end() : prev(iL);
            int dLL = iLL != s.end() ? *iL - *iLL : INF;
            int pR = iR != s.end() ? *iR - *iL : INF, pL = min(dLL, pR), nL = min(dLL, dL);
            if (pL == INF) pL = 0;
            ans += nL - pL;
        }
        if (iR != s.end()) {
            auto iRR = next(iR);
            int dRR = iRR != s.end() ? *iRR - *iR : INF;
            int pL = iL != s.end() ? *iR - *iL : INF, pR = min(dRR, pL), nR = min(dRR, dR);
            if (pR == INF) pR = 0;
            ans += nR - pR;
        }
        s.insert(X[i]);
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