#pragma GCC optimize(3, "Ofast", "inline")
#include <bits/stdc++.h>
#define int long long
using namespace std;
constexpr int INF = 0x7fffffff;
void solve() {
    int Px, Py, Qx, Qy, Rx, Ry, Sx, Sy;
    cin >> Px >> Py >> Qx >> Qy >> Rx >> Ry >> Sx >> Sy;
    int v0{Qx - Px}, v1{Qy - Py}, v2{Sx - Rx}, v3{Sy - Ry};
    __int128 cp{(__int128)v0 *v3 - (__int128)v1 * v2};
    if (cp != 0) { cout << "Yes\n"; return; }
    int Mx{Rx + Sx - Px - Qx}, My{Ry + Sy - Py - Qy};
    __int128 dp{(__int128)Mx * v0 + (__int128)My * v1};
    cout << (dp == 0 ? "Yes\n" : "No\n");
    return;
}
signed main() {
    cin.tie(nullptr) -> sync_with_stdio(false);
    int _ = 1; //cin >> _;
    while(_ --) solve();
    return 0;
}