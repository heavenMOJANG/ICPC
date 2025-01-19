#pragma GCC optimize(1)
#pragma GCC optimize(2)
#pragma GCC optimize(3,"Ofast","inline")
#include<bits/stdc++.h>
#define int long long
using namespace std;
constexpr int INF = 0x7fffffff;
void solve() {
    int a1, a2, b1, b2; cin >> a1 >> a2 >> b1 >> b2;
    cout << (a1 > b1 & a1 == b2) + (a1 > b2 & a2 == b1) + (a2 > b1 & a1 == b2) + (a2 > b2 & a1 == b1) << "\n";
    return;
}
signed main() {
    cin.tie(0) -> sync_with_stdio(0);
    int _ = 1; cin >> _;
    while(_ --) solve();
    return 0;
}