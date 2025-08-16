#pragma GCC optimize(3, "Ofast", "inline")
#include <bits/stdc++.h>
#define int long long
using namespace std;
constexpr int INF = 0x7fffffff;
void solve() {
    int n; cin >> n;
    vector<int> b(n);
    for (auto && x : b) cin >> x;
    int c{}, ok = 1;
    for (int i = n - 1; ~i; -- i) {
        c = b[i] - c;
        if (c < 0) { ok = 0; break; }
    }
    cout << (ok && c == 0 ? "YES\n" : "NO\n");
    return;
}
signed main() {
    cin.tie(nullptr) -> sync_with_stdio(false);
    int _ = 1; cin >> _;
    while(_ --) solve();
    return 0;
}