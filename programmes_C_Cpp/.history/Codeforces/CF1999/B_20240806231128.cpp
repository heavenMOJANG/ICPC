#pragma GCC optimize(1)
#pragma GCC optimize(2)
#pragma GCC optimize(3,"Ofast","inline")
#include<bits/stdc++.h>
#define int long long
using namespace std;
constexpr int INF = 0x7fffffff;
void solve() {
    int x1, x2, y1, y2; cin >> x1 >> x2 >> y1 >> y2;
    int ans = 0;
    if (x1 > y1 && x2 == y2 || x1 > y2 && x2 == y1) {cout << "2\n"; return;}
    if (x1 > y1 && x2 > y2 || x1 > y2 && x2 > y1) {cout << "2\n"; return;}
    cout << ans * 2 << "\n";
    return;
}
signed main() {
    cin.tie(0) -> sync_with_stdio(0);
    int _ = 1; cin >> _;
    while(_ --) solve();
    return 0;
}