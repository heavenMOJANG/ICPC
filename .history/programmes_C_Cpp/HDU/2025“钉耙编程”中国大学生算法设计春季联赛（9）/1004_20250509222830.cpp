#pragma GCC optimize(1)
#pragma GCC optimize(2)
#pragma GCC optimize(3, "Ofast", "inline")
#include <bits/stdc++.h>
#define int long long
using namespace std;
constexpr int INF = 0x7fffffff;
void solve() {
    int v, w; cin >> v >> w;
    if (w == 1) { cout << v << "\n"; return; }
    if (w == 2) { cout << (v + 1) / 2 << "\n"; return; }
    int k{};
    if (w & 1) {
        k = v / (w / 2 + 1);
        if (!k) k ++;
    } else {
        k = v / (w / 2 + 1);
        if (!k) k ++;
    }
    cout << k << "\n";
    return;
}
signed main() {
    cin.tie(0) -> sync_with_stdio(0);
    int _ = 1; cin >> _;
    while(_ --) solve();
    return 0;
}