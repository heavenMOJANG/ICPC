#pragma GCC optimize(1)
#pragma GCC optimize(2)
#pragma GCC optimize(3,"Ofast","inline")
#include<bits/stdc++.h>
#define int long long
using namespace std;
constexpr int INF = 0x7fffffff;
void solve() {
    int l = 2, r = 999;
    int cnt = 10;
    while (cnt --) {
        int mid = l + r >> 1;
        cout << "? 1 " << mid << endl;
        int s; cin >> s;
        if (s == 1 * mid) l = mid + 1;
        else r = mid;
    }
    cout << "! " << l << endl;
    return;
}
signed main() {
    cin.tie(0) -> sync_with_stdio(0);
    int _ = 1; cin >> _;
    while(_ --) solve();
    return 0;
}