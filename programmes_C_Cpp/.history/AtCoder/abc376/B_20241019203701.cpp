#pragma GCC optimize(1)
#pragma GCC optimize(2)
#pragma GCC optimize(3,"Ofast","inline")
#include <bits/stdc++.h>
#define int long long
using namespace std;
constexpr int INF = 0x7fffffff;
void solve() {
    int n, q; cin >> n >> q;
    int L = 1, R = 2, ans{};
    while (q --) {
        int h;
        string t;
        cin >> t >> h;
        if (t == "L") {
            if (L == h) continue;
            else {
                int flag{}, cnt{};
                while (L != h) {
                    L ++, cnt ++;
                    if (L == n + 1) L = 1;
                    if (L == R) flag = 1;
                }
                if (flag) cnt = n - cnt;
                ans += cnt;
            }
        } else {
            if (R == h) continue;
            else {
                int flag{}, cnt{};
                while (R != h) {
                    R ++, cnt ++;
                    if (R == n + 1) R = 1;
                    if (L == R) flag = 1;
                }
                if (flag) cnt = n - cnt;
                ans += cnt;
            }
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