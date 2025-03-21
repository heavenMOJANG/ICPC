#pragma GCC optimize(1)
#pragma GCC optimize(2)
#pragma GCC optimize(3, "Ofast", "inline")
#include <bits/stdc++.h>
#define int long long
#define i128 __int128
using namespace std;
constexpr int INF = 0x7fffffff;
void solve() {
    int n; cin >> n;
    for (int i = 1; i * i * i <= n; ++ i) {
        if (n % i) continue;
        int m = n / i;
        function<int(int, int, int)> f = [&](int a, int b, int c) {
            int l{}, r = 6e8 + 1;
            while (l + 1 < r) {
                int mid = l + r >> 1;
                if (a * mid * mid + b * mid + c <= 0) l = mid;
                else r = mid;
            }
            return a * l * l + b * l + c == 0 ? l : -1;
        };
        int x = f(3, 3 * i, i * i - m);
        if (x > 0) { cout << x + i << " " << x << "\n"; return; }
    }
    cout << "-1\n";
    return;
}
signed main() {
    cin.tie(0) -> sync_with_stdio(0);
    int _ = 1; //cin >> _;
    while(_ --) solve();
    return 0;
}