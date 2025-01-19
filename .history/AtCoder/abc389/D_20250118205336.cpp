#pragma GCC optimize(1)
#pragma GCC optimize(2)
#pragma GCC optimize(3, "Ofast", "inline")
#include <bits/stdc++.h>
#define int long long
using namespace std;
constexpr int INF = 0x7fffffff;
constexpr double EXP = 1e-6;
int check(double i, double j, double r) {
    if (i * i + j * j - r * r > EXP) return 0;
    return 1;
}
void solve() {
    int r; cin >> r;
    int ans{};
    for (int i = -r + 1; i <= r - 1; ++ i) {
        double jd = max(-r + 1, -(int)sqrt(r * r - i * i));
        double ju = min(r - 1, (int)sqrt(r * r - i * i));
        if (!check(i, ju + 0.5, r)) ju --;
        if (!check(i, jd - 0.5, r)) jd ++;
        cout << ju << " " << jd << "\n";
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