#pragma GCC optimize(3, "Ofast", "inline")
#include <bits/stdc++.h>
#define int long long
using namespace std;
constexpr int INF = 0x7fffffff;
void solve() {
    int N; cin >> N;
    vector<int> X(N);
    for (auto && x : X) cin >> x;
    for (int i : views::iota(0, N)) {
        int ans{LLONG_MAX};
        if (i > 0) ans = min(ans, max(X[i] - X[0], X[N - 1] - X[i - 1]) / 2);
        if (i < N - 1) ans = min(ans, max(X[i + 1] - X[0], X[N - 1] - X[i]) / 2);
        cout << (N == 1 ? 0 : ans) << "\n";
    }
    return;
}
signed main() {
    cin.tie(nullptr) -> sync_with_stdio(false);
    int _ = 1; //cin >> _;
    while(_ --) solve();
    return 0;
}