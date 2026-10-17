#pragma GCC optimize(3, "Ofast", "inline")
#include <bits/stdc++.h>
#define int long long
using namespace std;
constexpr int INF = 0x7fffffff;
void solve() {
    int N; cin >> N;
    string S; cin >> S;
    vector<int> X(N);
    for (auto && x : X) cin >> x;
    vector<int> Y(N - 1);
    for (auto && y : Y) cin >> y;
    int dps{S[0] == 'S' ? 0ll : -X[0]}, dpr{S[0] == 'R' ? 0ll : -X[0]};
    for (int i{1}; i < N; ++ i) {
        int ws{S[i] == 'S' ? 0ll : -X[i]}, wr{S[i] == 'R' ? 0ll : -X[i]};
        int ns{max(dps, dpr + Y[i - 1]) + ws}, nr{max(dps, dpr) + wr};
        dps = ns, dpr = nr;
    }
    cout << max(dps, dpr) << "\n";
    return;
}
signed main() {
    cin.tie(nullptr) -> sync_with_stdio(false);
    int _ = 1; //cin >> _;
    while(_ --) solve();
    return 0;
}