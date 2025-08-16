#pragma GCC optimize(3, "Ofast", "inline")
#include <bits/stdc++.h>
#define int long long
using namespace std;
constexpr int INF = 0x7fffffff;
void solve() {
    auto cal = [&](int x) {
        int res{};
        while (x) {
            res += x % 10;
            x /= 10;
        }
        return res % 5 == 0;
    };
    int ans{};
    for (int i = 1; i <= 202504; ++ i) ans += cal(i);
    cout << ans << "\n";
    return;
}
signed main() {
    cin.tie(nullptr) -> sync_with_stdio(false);
    int _ = 1; //cin >> _;
    while(_ --) solve();
    return 0;
}