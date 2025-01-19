#pragma GCC optimize(1)
#pragma GCC optimize(2)
#pragma GCC optimize(3, "Ofast", "inline")
#include <bits/stdc++.h>
#define int long long
using namespace std;
constexpr int INF = 0x7fffffff;
constexpr double EXP = 1e-15;

void solve() {
    int r; cin >> r;
    int ans{};
    auto check = [&](double x, double y) {
        if (abs((x + 0.5l) * (x + 0.5l) + (y + 0.5l) * (y + 0.5l) - (double)r * (double)r) > EXP) return 0;
        if (abs((x + 0.5l) * (x + 0.5l) + (y - 0.5l) * (y - 0.5l) - (double)r * (double)r) > EXP) return 0;
        if (abs((x - 0.5l) * (x - 0.5l) + (y + 0.5l) * (y + 0.5l) - (double)r * (double)r) > EXP) return 0;
        if (abs((x - 0.5l) * (x - 0.5l) + (y - 0.5l) * (y - 0.5l) - (double)r * (double)r) > EXP) return 0;
        return 1;
    };
    for (int i = -r + 1; i <= r - 1; ++ i) {
        int jd = -sqrt(r * r - i * i);
        int ju = sqrt(r * r - i * i);
        if (!check((double)i, (double)ju)) ju --;
        if (!check((double)i, (double)jd)) jd ++;
        //cout << ju << " " << jd << "\n";
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