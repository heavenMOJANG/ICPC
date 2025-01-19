#pragma GCC optimize(1)
#pragma GCC optimize(2)
#pragma GCC optimize(3, "Ofast", "inline")
#include <bits/stdc++.h>
#define int long long
using namespace std;
constexpr int INF = 0x7fffffff;
int fac(int x) {
    int res = 1;
    for (int i = 2; i <= x; ++ i) res *= i;
    return res;
}
void solve() {
    int n, k; cin >> n >> k;
    if (n == 1 && k == 1) { cout << "YES\n1\n"; return; }
    if (n == 1 || k == 1) { cout << "NO\n"; return; }
    if (!(n & 1) && k & 1) { cout << "NO\n"; return; }
    if (n <= 6 && (k > fac(n) || k + 1 == fac(n))) { cout << "NO\n"; return; }
    vector<int> p(n + 1);
    iota(p.begin(), p.end(), 0);
    if (k & 1) {
        for (int i = 1; i <= n; ++ i)
    }
    cout << "NO\n";
    return;
}
signed main() {
    cin.tie(0) -> sync_with_stdio(0);
    int _ = 1; cin >> _;
    while(_ --) solve();
    return 0;
}