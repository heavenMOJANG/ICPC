#pragma GCC optimize(3, "Ofast", "inline")
#include <bits/stdc++.h>
#define int long long
using namespace std;
constexpr int INF = 4e18;
void solve() {
    int n; cin >> n;
    vector<int> X(n);
    for (auto && x : X) cin >> x;
    set<int> pos; pos.insert(0);
    int ans{};
    for (int i{}; i < n; ++ i) {
        auto iR = pos.lower_bound(X[i]);
        auto iL = (iR == pos.begin() ? pos.end() : prev(iR));
        int dL = iL != pos.end() ? X[i] - *iL : INF, dR = iR != pos.end() ? *iR - X[i] : INF;
        int d = min(dL, dR);
        ans += d;
        if (iL != pos.end()) {
            auto iLL = iL == pos.begin() ? pos.end() : prev(iL);
            int dLL = iLL != pos.end() ? *iL - *iLL : INF;
            int pR = iR != pos.end() ? *iR - *iL : INF, pL = min(dLL, pR), nL = min(dLL, dL);
            if (pL == INF) pL = 0;
            ans += nL - pL;
        }
        if (iR != pos.end()) {
            auto iRR = next(iR);
            int dRR = iRR != pos.end() ? *iRR - *iR : INF;
            int pL = iL != pos.end() ? *iR - *iL : INF, pR = min(dRR, pL), nR = min(dRR, dR);
            if (pR == INF) pR = 0;
            ans += nR - pR;
        }
        pos.insert(X[i]);
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