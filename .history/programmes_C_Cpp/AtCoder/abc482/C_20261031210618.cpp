#pragma GCC optimize(3, "Ofast", "inline")
#include <bits/stdc++.h>
#define int long long
using namespace std;
constexpr int INF = 0x7fffffff;
void solve() {
    int H, W, N, Q; cin >> H >> W >> N >> Q;
    vector<int> R(N), C(N);
    for (int i : views::iota(0, N)) cin >> R[i] >> C[i];
    ranges::sort(R); ranges::sort(C);
    while (Q --) {
        int t, l, r; cin >> t >> l >> r;
        cout << (t == 1 ?
            ranges::upper_bound(R, r) - ranges::lower_bound(R, l) :
            ranges::upper_bound(C, r) - ranges::lower_bound(C, l)
        ) << "\n";
    }
    return;
}
signed main() {
    cin.tie(nullptr) -> sync_with_stdio(false);
    int _ = 1; //cin >> _;
    while(_ --) solve();
    return 0;
}