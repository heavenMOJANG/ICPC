#pragma GCC optimize(3, "Ofast", "inline")
#include <bits/stdc++.h>
#define int long long
using namespace std;
constexpr int INF = 0x7fffffff;
void solve() {
    int n; cin >> n;
    string a; cin >> a;
    int m; cin >> m;
    string b, c; cin >> b >> c;
    for (int i{}; i < m; ++ i)
        if (c[i] == 'V') a = b[i] + a;
        else a = a + b[i];
    cout << a << '\n';
    return;
}
signed main() {
    cin.tie(nullptr) -> sync_with_stdio(false);
    int _ = 1; cin >> _;
    while(_ --) solve();
    return 0;
}