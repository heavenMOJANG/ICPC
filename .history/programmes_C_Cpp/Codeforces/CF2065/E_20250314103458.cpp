#pragma GCC optimize(1)
#pragma GCC optimize(2)
#pragma GCC optimize(3, "Ofast", "inline")
#include <bits/stdc++.h>
#define int long long
using namespace std;
constexpr int INF = 0x7fffffff;
void solve() {
    int n, m, k; cin >> n >> m >> k;
    if (k < abs(n - m) || k > max(n, m)) { cout << "-1\n"; return; }
    string s{};
    int flag = m > n;
    while (n || m) {
        if (flag) {
            int d = min(k, m);
            for (int i = 0; i < d; ++ i) s += "1";
            m -= d;
        } else {
            int d = min(k, n);
            for (int i = 0; i < d; ++ i) s += "0";
            n -= d;
        }
        flag ^= 1;
    }
    cout << s << "\n";
    return;
}
signed main() {
    cin.tie(0) -> sync_with_stdio(0);
    int _ = 1; cin >> _;
    while(_ --) solve();
    return 0;
}