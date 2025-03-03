#pragma GCC optimize(1)
#pragma GCC optimize(2)
#pragma GCC optimize(3, "Ofast", "inline")
#include <bits/stdc++.h>
#define int long long
using namespace std;
constexpr int INF = 0x7fffffff;
void solve() {
    char c0, c1; cin >> c0 >> c1;
    for (char c = 'a'; c <='h'; ++ c) {
        if (c == c0) continue;
        cout << c << c1 << endl;
    }
    for (char c = '8'; c >= '1'; -- c) {
        if (c == c1) continue;
        cout << c0 << c << endl;
    }
    return;
}
signed main() {
    cin.tie(0) -> sync_with_stdio(0);
    int _ = 1; //cin >> _;
    while(_ --) solve();
    return 0;
}