#pragma GCC optimize(3, "Ofast", "inline")
#include <bits/stdc++.h>
#define int long long
using namespace std;
constexpr int INF = 0x7fffffff;
void solve() {
    int n, m; cin >> n >> m;
    string s, t; cin >> s >> t;
    int minn = INF;
    for (int i{}; i <= n - m; ++ i) {
        int cnt{};
        for (int j{}; j < m; ++ j) cnt += (s[i + j] - t[j] + 10) % 10; 
        minn = min(minn, cnt);
    }
    cout << minn << "\n";
    return;
}
signed main() {
    cin.tie(nullptr) -> sync_with_stdio(false);
    int _ = 1; //cin >> _;
    while(_ --) solve();
    return 0;
}