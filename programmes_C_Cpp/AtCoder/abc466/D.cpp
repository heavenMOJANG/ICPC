#pragma GCC optimize(3, "Ofast", "inline")
#include <bits/stdc++.h>
#define int long long
#define pii pair<int, int>
using namespace std;
constexpr int INF = 0x7fffffff;
void solve() {
    int N, M; cin >> N >> M;
    vector<pii> O(M);
    for (auto &&[x, y] : O) cin >> x >> y;
    vector<bool> R(N + 1, false), C = R;
    int ans{};
    for (int i{M - 1}; ~i; -- i) {
        auto [r, c] = O[i];
        if (!R[r] && !C[c]) ans ++;
        R[r] = C[c] = true;
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