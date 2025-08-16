#pragma GCC optimize(3, "Ofast", "inline")
#include <bits/stdc++.h>
#define int long long
using namespace std;
constexpr int INF = 0x7fffffff;
void solve() {
    int n, x; cin >> n >> x;
    string s; cin >> s;
    int l{}, r{};
    for (int i = x - 2; ~i; -- i) {
        if (s[i] == '#') break;
        l ++;
    }
    for (int i = x; i < n; ++ i) {
        if (s[i] == '#') break;
        r ++;
    }
    cout << l + r + 1 << "\n";
    return;
}
signed main() {
    cin.tie(nullptr) -> sync_with_stdio(false);
    int _ = 1; cin >> _;
    while(_ --) solve();
    return 0;
}