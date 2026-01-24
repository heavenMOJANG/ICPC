#pragma GCC optimize(3, "Ofast", "inline")
#include <bits/stdc++.h>
#define int long long
using namespace std;
constexpr int INF = 0x7fffffff;
void solve() {
    int n; cin >> n;
    vector<int> cnt(n + 1, 0);
    for (int x = 1; x <= sqrt(n); ++ x) {
        int xs = x * x;
        for (int y = x + 1; y <= sqrt(x); ++ y) {
            int ns = xs + y * y;
            if (ns > n) break;
            cnt[ns] ++;
        }
    }
    vector<int> ans;
    for (int i = 1; i <= n; ++ i) if (cnt[i] == 1) ans.emplace_back(i);
    cout << ans.size() << "\n";
    for (auto x : ans) cout << x << " ";
    cout << "\n";
    return;
}
signed main() {
    cin.tie(nullptr) -> sync_with_stdio(false);
    int _ = 1; //cin >> _;
    while(_ --) solve();
    return 0;
}