#pragma GCC optimize(1)
#pragma GCC optimize(2)
#pragma GCC optimize(3,"Ofast","inline")
#include <bits/stdc++.h>
#define int long long
using namespace std;
constexpr int INF = 0x7fffffff;
int calc(int x, int y) {
    return x & y;
}
void solve() {
    int b, c, d; cin >> b >> c >> d;
    int a{};
    for (int i = 0; i < 62; ++ i)
        if (d & (1ll << i)) {
            if ((b & (1ll << i)))
        } else {

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