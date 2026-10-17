#pragma GCC optimize(3, "Ofast", "inline")
#include <bits/stdc++.h>
#define int long long
using namespace std;
constexpr int INF = 0x7fffffff;
void solve() {
    int N; cin >> N;
    vector<int> H(N), L(N);
    for (int i{}; i < N; ++ i) cin >> H[i] >> L[i];
    vector<int> suf(N);
    suf[N - 1] = H[N - 1];
    for (int i{N - 2}; ~i; -- i) suf[i] = max(H[i], suf[i + 1]);
    int Q; cin >> Q;
    while (Q --) {
        int T; cin >> T;
        auto it{ranges::upper_bound(L, T)};
        int idx{ranges::distance(L.begin(), it)};
        cout << suf[idx] << "\n";
    }
    return;
}
signed main() {
    cin.tie(nullptr) -> sync_with_stdio(false);
    int _ = 1; //cin >> _;
    while(_ --) solve();
    return 0;
}