#pragma GCC optimize(1)
#pragma GCC optimize(2)
#pragma GCC optimize(3,"Ofast","inline")
#include<bits/stdc++.h>
#define int long long
using namespace std;
constexpr int INF = 0x7fffffff;
void solve() {
    int n, x, y; cin >> n >> x >> y;
    int l = (n + x - 1) / x, r = (n + y - 1) / y;
    if (l != r) cout << "Yes\nYes\n";
    else cout << (l & 1? "Yes\nNo\n" : "No\nYes\n");
}
signed main() {
    cin.tie(0) -> sync_with_stdio(0);
    int _ = 1; cin >> _;
    while(_ --) solve();
    return 0;
}