#pragma GCC optimize(1)
#pragma GCC optimize(2)
#pragma GCC optimize(3, "Ofast", "inline")
#include <bits/stdc++.h>
#define int long long
using namespace std;
constexpr int INF = 0x7fffffff;
void solve() {
    int r; cin >> r;
    int ans{};
    for (int i = -r + 1; i <= r - 1; ++ i) {
        int jl = max(-r + 1, -(int)sqrt(r * r - i * i));
        int jr = min(r - 1, (int)sqrt(r * r - i * i));
        ans += jr - jl + 1;
    }
    cout << ans << "\n";
    return;
}
signed main() {
    cin.tie(0) -> sync_with_stdio(0);
    int _ = 1; //cin >> _;
    while(_ --) solve();
    return 0;
}