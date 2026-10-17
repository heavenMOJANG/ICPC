#pragma GCC optimize(3, "Ofast", "inline")
#include <bits/stdc++.h>
#define int long long
using namespace std;
constexpr int INF = 0x7fffffff;
void solve() {
    int M, D; cin >> M >> D;
    vector<int> diff(M + 2, 0);
    string S; cin >> S;
    for (int i : views::iota(0, M))
        if (S[i] == 'G') {
            int l{max(1ll, i + 1 - D)}, r{min(M, i + 1 + D)};
            diff[l] ++;
            diff[r + 1] --;
        }
    int ans{};
    for (int i : views::iota(1, M + 1)) {
        diff[i] += diff[i - 1];
        if (diff[i] == 0) ans ++;
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