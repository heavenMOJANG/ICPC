#pragma GCC optimize(3, "Ofast", "inline")
#include <bits/stdc++.h>
#define int long long
using namespace std;
constexpr int INF = 0x7fffffff;
void solve() {
    int s, a, b, x; cin >> s >> a >> b >> x;
    if (x <= a) cout << s * x << "\n";
    else if ( x <= a + b) cout << s * a << "\n";
    else cout << s * (x - b) << "\n";
    return;
}
signed main() {
    cin.tie(nullptr) -> sync_with_stdio(false);
    int _ = 1; //cin >> _;
    while(_ --) solve();
    return 0;
}