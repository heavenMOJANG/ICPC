#pragma GCC optimize(1)
#pragma GCC optimize(2)
#pragma GCC optimize(3, "Ofast", "inline")
#include <bits/stdc++.h>
#define int long long
using namespace std;
constexpr int INF = 0x7fffffff;
void solve() {
    int N; cin >> N;
    int n = cbrt(4 * N);
    for (int i = 1; i <= n; ++ i) {
        int t = 4 * N - i * i * i;
        if (t < 0) continue;
        int s = 3 * i * t;
        int k = sqrt(s);
        if (k * k != s) continue;
        if (k <= 3 * i * i) continue;
        int num = k - 3 * i * i;
        if (num % (6 * i)) continue;
        int y = num / (6 * i);
        if (y <= 0) continue;
        int x = y + i;
        if (x * x * x - y * y * y == N) { cout << x << " " << y << "\n"; return; }
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