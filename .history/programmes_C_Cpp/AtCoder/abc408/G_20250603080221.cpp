#pragma GCC optimize(3, "Ofast", "inline")
#include <bits/stdc++.h>
#define int long long
using namespace std;
constexpr int INF = 0x7fffffff;
pair<int, int> get(int a, int b, int c, int d) {
    int n = a / b;
    a -= n * b, c -= n * d;
    if (c > d) return {n + 1, 1};
    auto [p, q] = get(d, c, b, a);
    return {p * n + q, p};
}
void solve() {
    int a, b, c, d; cin >> a >> b >> c >> d;
    cout << get(a, b, c, d).second << "\n";
    return;
}
signed main() {
    cin.tie(0) -> sync_with_stdio(0);
    int _ = 1; cin >> _;
    while(_ --) solve();
    return 0;
}