#pragma GCC optimize(3, "Ofast", "inline")
#include <bits/stdc++.h>
#define int long long
using namespace std;
constexpr int INF = 0x7fffffff;
void solve() {
    int n; cin >> n;
    vector<int> a(n + 1, 0), d(n + 1, 0);
    for (int i = 1; i < n; ++ i) cin >> d[i];
    for (int i = 1; i < n; ++ i) {
        int cur{};
        for (int j = i; j < n; ++ j) {
            cur += d[j];
            cout << cur << " \n"[j == n - 1];
        }
    }
    return;
}
signed main() {
    cin.tie(0) -> sync_with_stdio(0);
    int _ = 1; //cin >> _;
    while(_ --) solve();
    return 0;
}