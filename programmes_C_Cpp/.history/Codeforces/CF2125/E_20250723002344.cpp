#pragma GCC optimize(3, "Ofast", "inline")
#include <bits/stdc++.h>
#define int long long
using namespace std;
constexpr int INF = 0x7fffffff;
void solve() {
    int n, x; cin >> n >> x;
    if (n == 1) { cout << x << "\n"; return; }
    if (n >= 2 && n * (n - 1) / 2 >= x) { cout << "0\n"; return; }
    if (n >= 633) { cout << "0\n"; return; }
    
    return;
}
signed main() {
    cin.tie(nullptr) -> sync_with_stdio(false);
    int _ = 1; //cin >> _;
    while(_ --) solve();
    return 0;
}