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
            if (L == h) {cout << ans << "\n"; return;}
            else {
                if (L > R) {
                    if (h > L) ans += n - h;
                    else if (h < R) ans += n - L + h - 1;
                    else ans += L - h;
                } else {
                    if (h < L) ans += L - h;
                    else if (h > R) ans += n - h + L - 1;
                    else ans += h - L;
                }
                L = h;
            }
        } else {
            if (R == h) {cout << ans << "\n"; return;}
            else {
                if (L > R) {
                    if (h < R) ans += R - h;
                    else if (h > L) ans += n - h + R - 1;
                    else ans += h - R;
                } else {
                    if (h > R) ans += h - R;
                    else if (h < L) ans += n - R + h - 1;
                    else ans += R - h;
                }
            }
            R = h;
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