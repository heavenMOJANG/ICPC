#pragma GCC optimize(1)
#pragma GCC optimize(2)
#pragma GCC optimize(3, "Ofast", "inline")
#include <bits/stdc++.h>
#define int long long
using namespace std;
constexpr int INF = 0x7fffffff;
constexpr int a[] = {9, 99, 999, 9999, 99999, 999999, 9999999, 99999999, 999999999};
void solve() {
    int n; cin >> n;
    int minn = INF;
    for (int i = 0; i < 9; ++ i) {
        int x = n, cnt{};
        for (int j = 0; j < 20; ++ j) {
            string s = to_string(x);
            for (auto c : s) if (c == '7') minn = min(minn, cnt);
            x += a[i];
            cnt ++;
        }
    }
    cout << minn << "\n";
    return;
}
signed main() {
    cin.tie(0) -> sync_with_stdio(0);
    int _ = 1; cin >> _;
    while(_ --) solve();
    return 0;
}