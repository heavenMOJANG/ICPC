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
    cout << n << "\n";
    for (int i = n; i >= 2; ++ i) {
        int i3 = i * i * i;
        if (i3 <= N) break;
        int j = cbrt(i3 - N), j3 = j * j * j;
        if (i3 - j3 == N) { cout << i << " " << j << "\n"; return; }
    }
    cout << cbrt(342756ll * 342756ll * 342756ll - 39977273855577088ll) << "\n";
    cout << "-1\n";
    return;
}
signed main() {
    cin.tie(0) -> sync_with_stdio(0);
    int _ = 1; //cin >> _;
    while(_ --) solve();
    return 0;
}