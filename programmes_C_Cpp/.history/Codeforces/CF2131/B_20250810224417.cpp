#pragma GCC optimize(3, "Ofast", "inline")
#include <bits/stdc++.h>
#define int long long
using namespace std;
constexpr int INF = 0x7fffffff;
void solve() {
    int n; cin >> n;
    if (n & 1) {
        for (int i{}; i < n; ++ i)
            if (i & 1) cout << 3 << " \n"[i == n - 1];
            else cout << -1 << " \n"[i == n - 1];
    } else {
        for (int i{}; i < n - 1; ++ i)
            if (i & 1) cout << "3 ";
            else cout << "-1 ";
        cout << "2\n";
    }
    return;
}
signed main() {
    cin.tie(nullptr) -> sync_with_stdio(false);
    int _ = 1; cin >> _;
    while(_ --) solve();
    return 0;
}