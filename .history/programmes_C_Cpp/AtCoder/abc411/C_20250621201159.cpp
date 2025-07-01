#pragma GCC optimize(3, "Ofast", "inline")
#include <bits/stdc++.h>
#define int long long
using namespace std;
constexpr int INF = 0x7fffffff;
void solve() {
    int n, q; cin >> n >> q;
    vector<int> a(n + 1, 0);
    int cur{};
    while (q --) {
        int x; cin >> x;
        if (a[x] == 1) {
            if (x > 1) {
                if (a[x - 1] == 1) cur ++;
            }
            if (x < n) {
                if (a[x + 1] == 1) cur ++;
            }
            a[x] = 0;
        } else {
            a[x] = 1;
        }
    }
    return;
}
signed main() {
    cin.tie(0) -> sync_with_stdio(0);
    int _ = 1; //cin >> _;
    while(_ --) solve();
    return 0;
}