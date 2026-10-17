#pragma GCC optimize(3, "Ofast", "inline")
#include <bits/stdc++.h>
#define int long long
using namespace std;
constexpr int INF = 0x7fffffff;
void solve() {
    int N, Q; cin >> N >> Q;
    vector<int> up(N + 1, 0), down(N + 1, 0);
    for (int i{1}; i <= N; ++ i) {
        int C, P; cin >> C >> P;
        int prev = down[C];
        if (prev != 0) up[prev] = 0;
        down[C] = P;
        up[P] = C;
    }
    vector<int> ans(N + 1, 0);
    for (int i = 1; i <= N; ++ i)
        if (down[i] == 0) {
            int cnt{}, cur = i;
            while (cur != 0) cnt ++, cur = up[cur];
            cur = i;
            while (cur != 0) ans[cur] = cnt, cur = up[cur];
        }
    for (int i = 1; i <= N; ++ i) cout << ans[i] << " \n"[i == N];
    return;
}
signed main() {
    cin.tie(nullptr) -> sync_with_stdio(false);
    int _ = 1; //cin >> _;
    while(_ --) solve();
    return 0;
}
