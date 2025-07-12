#pragma GCC optimize(3, "Ofast", "inline")
#include <bits/stdc++.h>
#define int long long
using namespace std;
constexpr int INF = 0x7fffffff;
void solve() {
    int a, n; cin >> a >> n;
    auto check = [&](int x, int b) {
        vector<int> t;
        while (x) {
            t.emplace_back(x % b);
            x /= b;
        }
        for (int i{}; i < t.size() / 2; ++ i) if (t[i] != t[t.size() - 1 - i]) return 0ll;
        return 1ll;
    };
    int ans{}, maxl = to_string(n).size();
    for (int i = 1; i <= maxl; ++ i) {
        int h = (i + 1) / 2;
        int l = h == 1 ? 1ll : pow(10ll, h - 1), r = pow(10ll, h) - 1;
        for (int j = l; j <= r; ++ j) {
            int p = j, t = j;
            if (i & 1) t /= 10;
            while (t) {
                p = p * 10 + t % 10;
                t /= 10;
            }
            if (p > n) break;
            if (check(p, a)) ans += p;
        }
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