#pragma GCC optimize(3, "Ofast", "inline")
#include <bits/stdc++.h>
#define int long long
using namespace std;
constexpr int INF = 0x7fffffff;
void solve() {
    int n; cin >> n;
    vector<string> s(n);
    int m{};
    for (auto && x : s) cin >> x, m = max(m, (int)x.size());
    for (int i{}; i < n; ++ i) {
        int k = (m - s[i].size()) / 2;
        for (int j{}; j < k; ++ j) s[i] = "." + s[i] + ".";
        cout << s[i] << "\n";
    }
    return;
}
signed main() {
    cin.tie(nullptr) -> sync_with_stdio(false);
    int _ = 1; //cin >> _;
    while(_ --) solve();
    return 0;
}