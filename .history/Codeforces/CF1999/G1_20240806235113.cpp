#pragma GCC optimize(1)
#pragma GCC optimize(2)
#pragma GCC optimize(3,"Ofast","inline")
#include<bits/stdc++.h>
#define int long long
using namespace std;
constexpr int INF = 0x7fffffff;
void solve() {
    int l = 2, r = 999;
    while (1) {
        int mid = l + r >> 1;
        cout << "? 1 " << mid << endl;
        int s; cin >> s;
        if (s == 1 * mid) {
            l = mid;
        } else if (s == 1 * (mid + 1))
    }
    return;
}
signed main() {
    cin.tie(0) -> sync_with_stdio(0);
    int _ = 1; cin >> _;
    while(_ --) solve();
    return 0;
}