#pragma GCC optimize(3, "Ofast", "inline")
#include <bits/stdc++.h>
#define int long long
using namespace std;
constexpr int INF = 0x7fffffff;
void solve() {
    int n, x; cin >> n >> x;
    string s; cin >> s;
    int l{}, r{};
    for (int i{}; i < x - 1; ++ i) if (s[i] == '#') { l = 1; break; }
    for (int i = x; x < n; ++ i) if (s[i] == '#') { r = 1; break; }
    if (!l || !r) cout << "1\n";
    else cout << min(x - 1, n - x) + 1 << "\n";
    return;
}
signed main() {
    cin.tie(nullptr) -> sync_with_stdio(false);
    int _ = 1; cin >> _;
    while(_ --) solve();
    return 0;
}