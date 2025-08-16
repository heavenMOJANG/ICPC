#pragma GCC optimize(3, "Ofast", "inline")
#include <bits/stdc++.h>
#define int long long
using namespace std;
constexpr int INF = 0x7fffffff;
void solve() {
    int n, x; cin >> n >> x;
    string s; cin >> s; s = "." + s + '.';
    int ls = -1, rs = -1;
    for (int i = x - 1; i >= 1; -- i) if (s[i] == '#') { ls = i; break; }
    for (int i = x + 1; i <= n; ++ i) if (s[i] == '#') { rs = i; break; }
    if (x == 1 || x == n || (ls == -1 && rs == -1)) { cout << "1\n"; return; }
    if (ls == -1) {
        cout << min(x, n - rs + 2) << "\n";
        return;
    }
    if (rs == -1) {
        cout << min(n - x + 1, ls + 1) << "\n";
        return;
    }
    cout << min(max(x, n - rs + 2),
                max(n - x + 1, ls + 1))
         << "\n";
    return;
}
signed main() {
    cin.tie(nullptr) -> sync_with_stdio(false);
    int _ = 1; cin >> _;
    while(_ --) solve();
    return 0;
}