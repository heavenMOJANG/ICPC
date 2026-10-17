#pragma GCC optimize(3, "Ofast", "inline")
#include <bits/stdc++.h>
#define int long long
using namespace std;
constexpr int INF = 0x7fffffff;
void solve() {
    int N; cin >> N;
    vector<int> Y(N + 1);
    for (int i{}; i < N; ++ i) {
        int x, y; cin >> x >> y;
        Y[x] = y;
    }
    int ans{}, miny = N + 1;
    for (int x{1}; x <= N; ++ x)
        if (Y[x] < miny) ans ++, miny = Y[x];
    cout << ans << "\n";
    return;
}
signed main() {
    cin.tie(nullptr) -> sync_with_stdio(false);
    int _ = 1; //cin >> _;
    while(_ --) solve();
    return 0;
}
