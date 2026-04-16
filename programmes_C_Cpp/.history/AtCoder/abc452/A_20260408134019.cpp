#pragma GCC optimize(3, "Ofast", "inline")
#include <bits/stdc++.h>
#define int long long
using namespace std;
constexpr int INF = 0x7fffffff;
void solve() {
    int M, D; cin >> M >> D;
    if ((M == 1 && D == 7) || (M == 3 && D == 3) || (M == 5 && D == 5) || (M == 7 && D == 7) || (M == 9 && D == 9)) cout << "Yes\n";
    else cout < "No\n";
    return;
}
signed main() {
    cin.tie(nullptr) -> sync_with_stdio(false);
    int _ = 1; //cin >> _;
    while(_ --) solve();
    return 0;
}
