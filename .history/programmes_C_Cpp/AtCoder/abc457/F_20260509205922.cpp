#pragma GCC optimize(3, "Ofast", "inline")
#include <bits/stdc++.h>
#define int long long
using namespace std;
constexpr int INF = 0x7fffffff;
constexpr int MOD = 998244353;
void solve() {
    int N; cin >> N;
    vector<int> D(N);
    for (int i{1}; i < N; ++ i) cin >> D[i];
    if (D[N - 1] != 1) { cout << "0\n"; return; }
    int ans{2};
    for (int i = N - 2; i >= 1; -- i) {
        if (D[i] > D[i + 1] + 1) { cout << "0\n"; return; }
        if (D[i] == D[i + 1] + 1) (ans *= 2) %= MOD;
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
