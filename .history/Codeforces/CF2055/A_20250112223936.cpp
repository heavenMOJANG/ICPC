#pragma GCC optimize(1)
#pragma GCC optimize(2)
#pragma GCC optimize(3, "Ofast", "inline")
#include <bits/stdc++.h>
#define int long long
using namespace std;
constexpr int INF = 0x7fffffff;
void solve() {
    int n, a, b; cin >> n >> a >> b;
    if (a < b) {
        int d = b - a - 1;
        if (d & 1) cout << "YES\n";
        else cout << "NO\n";
    } else {
        int d = a - b - 1;
        if (d & 1) cout << "YES\n";
        else cout << "NO\n";
    }
    return;
}
signed main() {
    cin.tie(0) -> sync_with_stdio(0);
    int _ = 1; cin >> _;
    while(_ --) solve();
    return 0;
}