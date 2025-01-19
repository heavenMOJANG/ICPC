#pragma GCC optimize(1)
#pragma GCC optimize(2)
#pragma GCC optimize(3, "Ofast", "inline")
#include <bits/stdc++.h>
#define int long long
using namespace std;
constexpr int INF = 0x7fffffff;
constexpr double EXP = 1e-18;

void solve() {
    int r; cin >> r;
    int ans{};
    for (int i = -r + 1; i <= r - 1; ++ i) {
        int jd = -sqrt(r * r - i * i);
        int ju = sqrt(r * r - i * i);
        if (jd < -r + 1) jd ++;
        if (ju > r - 1) ju --;
        ans += ju - jd + 1;
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