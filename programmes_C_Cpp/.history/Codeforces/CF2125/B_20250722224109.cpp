#pragma GCC optimize(3, "Ofast", "inline")
#include <bits/stdc++.h>
#define int long long
using namespace std;
constexpr int INF = 0x7fffffff;
void solve() {
    int a, b, k; cin >> a >> b >> k;
    int nx = (a + k - 1) / k, ny = (b + k - 1) / k;
    int need = max(nx, ny), g = __gcd(a, b);
    cout << (g >= need ? "1\n" : "2\n");
    return;
}
signed main() {
    cin.tie(nullptr) -> sync_with_stdio(false);
    int _ = 1; cin >> _;
    while(_ --) solve();
    return 0;
}