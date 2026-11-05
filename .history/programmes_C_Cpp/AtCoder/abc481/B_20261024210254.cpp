#pragma GCC optimize(3, "Ofast", "inline")
#include <bits/stdc++.h>
#define int long long
using namespace std;
constexpr int INF = 0x7fffffff;
void solve() {
    int N, K; cin >> N >> K;
    int cur{}, pre{};
    cin >> pre;
    int ans{};
    for (int i : views::iota(1, N)) {
        cin >> cur;
        if ((cur - K) * (pre - K) <= 0) ans ++;
        pre = cur;
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