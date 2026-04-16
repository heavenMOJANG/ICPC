#pragma GCC optimize(3, "Ofast", "inline")
#include <bits/stdc++.h>
#define int long long
using namespace std;
constexpr int INF = 0x7fffffff;
constexpr int MOD = 998244353;
void solve() {
    int N, M; cin >> N >> M;
    vector<int> fac(M + 1, 1);
    for (int i = 1; i <= M; ++ i)
    vector<vector<int>> seg(N);
    for (int i{}; i < M; ++ i) {
        int x, y; cin >> x >> y;
        seg[y - 1].emplace_back(x);
    }
    return;
}
signed main() {
    cin.tie(nullptr) -> sync_with_stdio(false);
    int _ = 1; //cin >> _;
    while(_ --) solve();
    return 0;
}