#pragma GCC optimize(1)
#pragma GCC optimize(2)
#pragma GCC optimize(3,"Ofast","inline")
#include<bits/stdc++.h>
#define int long long
using namespace std;
constexpr int INF = 0x7fffffff;
void solve() {
    int xc, yc, k; cin >> xc >> yc >> k;
    if (k % 2 == 0) {
        for (int i = 1; i <= k / 2; ++ i)
            cout << xc + 1 << " " << yc + 1 << "\n" << xc - 1 << " " << yc - 1 << "\n";
    } else {
        cout << xc << " " << yc << "\n";
        for (int i = 1; i < k / 2; ++ i)
            cout << xc + 1 << " " << yc + 1 << "\n" << xc - 1 << " " << yc - 1 << "\n"; 
    }
}
signed main() {
    cin.tie(0) -> sync_with_stdio(0);
    int _ = 1; cin >> _;
    while(_ --) solve();
    return 0;
}