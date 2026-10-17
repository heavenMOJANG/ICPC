#pragma GCC optimize(3, "Ofast", "inline")
#include <bits/stdc++.h>
#define int long long
using namespace std;
constexpr int INF = 0x7fffffff;
constexpr int MAXN = 1e6;
void solve() {
    int N, D; cin >> N >> D;
    vector<int> diff(MAXN + 10, 0);
    for (int i{}; i < N; ++ i) {
        int S, T; cin >> S >> T;
        int l = S, r = T - D;
        if (l <= r) {
            diff[l] ++;
            diff[r + 1] --;
        }
    }
    int cur{}, ans{};
    for (int i{}; i <= MAXN; ++ i) {
        cur += diff[i];
        if (cur >= 2) ans += cur * (cur - 1) / 2;
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
