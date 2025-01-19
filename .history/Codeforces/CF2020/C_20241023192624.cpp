#pragma GCC optimize(1)
#pragma GCC optimize(2)
#pragma GCC optimize(3,"Ofast","inline")
#include <bits/stdc++.h>
#define int long long
using namespace std;
constexpr int INF = 0x7fffffff;
void solve() {
    int b, c, d; cin >> b >> c >> d;
    int a{};
    for (int i = 0; i < 62; ++ i) {
        int bx = b & (1ll << i), cx = c & (1ll << i), dx = d & (1ll << i);
        if (dx) {
            if (bx && cx) a += 0;
            if (bx && !cx) a += 0;
        } else {

        }
    }
    cout << a << "\n";
    return;
}
signed main() {
    cin.tie(0) -> sync_with_stdio(0);
    int _ = 1; //cin >> _;
    while(_ --) solve();
    return 0;
}