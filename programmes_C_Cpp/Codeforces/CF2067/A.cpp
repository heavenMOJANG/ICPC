#pragma GCC optimize(1)
#pragma GCC optimize(2)
#pragma GCC optimize(3, "Ofast", "inline")
#include <bits/stdc++.h>
#define int long long
using namespace std;
constexpr int INF = 0x7fffffff;
void solve() {
    int x, y; cin >> x >> y;
    if (x > y) {
        if ((x - y + 1) % 9 == 0) { cout << "Yes\n"; return; }
    }
    if (x < y) {
        if (x + 1 == y) { cout << "Yes\n"; return; }
    }
    cout << "No\n";
    return;
}
signed main() {
    cin.tie(0) -> sync_with_stdio(0);
    int _ = 1; cin >> _;
    while(_ --) solve();
    return 0;
}