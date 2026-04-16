#pragma GCC optimize(3, "Ofast", "inline")
#include <bits/stdc++.h>
#define int long long
using namespace std;
constexpr int INF = 0x7fffffff;
void solve() {
    int N; cin >> N;
    vector<int> L(N);
    for (auto && x : L) cin >> x;
    int maxn{};
    for (int i{}; i < (1ll << N); ++ i) {
        int res{}, pre = 1;
        for (int j{}; j < N; ++ j) {
            int cur;
            if ((1ll << j) & i) cur = pre + 2 * L[j];
            else cur = pre - 2 * L[j];
            if ((pre > 0) != (cur > 0)) res ++;
            pre = cur;
        }
        maxn = max(maxn, res);
    }
    cout << maxn << "\n";
    return;
}
signed main() {
    cin.tie(nullptr) -> sync_with_stdio(false);
    int _ = 1; //cin >> _;
    while(_ --) solve();
    return 0;
}