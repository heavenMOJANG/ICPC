#pragma GCC optimize(1)
#pragma GCC optimize(2)
#pragma GCC optimize(3,"Ofast","inline")
#include<bits/stdc++.h>
#define int long long
using namespace std;
constexpr int INF = 0x7fffffff;
void solve() {
    int x1, x2, y1, y2; cin >> x1 >> x2 >> y1 >> y2;
    auto [a1, a2] = minmax(x1, x2);
    auto [b1, b2] = minmax(y1, y2);
    int ans = 0;
    if (a2 >= a1 && a1 > b2) {cout << "4\n"; return;}
    else cout << "0\n";
    return;
}
signed main() {
    cin.tie(0) -> sync_with_stdio(0);
    int _ = 1; cin >> _;
    while(_ --) solve();
    return 0;
}