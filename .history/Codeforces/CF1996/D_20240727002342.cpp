#pragma GCC optimize(1)
#pragma GCC optimize(2)
#pragma GCC optimize(3,"Ofast","inline")
#include<bits/stdc++.h>
#define int long long
using namespace std;
constexpr int inf = 0x7fffffff;
void solve() {
    int n, x; cin >> n >> x;
    if (x < 3 || n < 2 * x - 3) {cout << "0\n"; return;}
    int ans = 0;
    for (int a = 1; a <= x - 2; ++ a) {
        int l = 1, r = x - a - 1;
        while (l < r) {
            int b = l + r >> 1;
            int c = x - a - b;
            if (a * b + b * c + a * c <= n) l = b + 1;
            else r = b;
        }
        ans += l * (x - a - l);
    }
    cout << ans << "\n";
    return;
}
signed main() {
    cin.tie(0) -> sync_with_stdio(0);
    int _ = 1; cin >> _;
    while(_ --) solve();
    return 0;
}