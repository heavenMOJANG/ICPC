#pragma GCC optimize(1)
#pragma GCC optimize(2)
#pragma GCC optimize(3, "Ofast", "inline")
#include <bits/stdc++.h>
#define int long long
using namespace std;
constexpr int INF = 0x7fffffff;
void solve() {
    int k; cin >> k;
    vector<pair<int, int>> ans;
    ans.emplace_back(0, 0);
    int i = 1;
    for (; (i + 1) * i / 2 <= k; ++ i) ans.emplace_back(i, 0);
    k -= i * (i - 1) / 2;
    vector<pair<int, int>> tmp;
    int h = 1;
    for (int j = 0; j < ans.size(); ++ j) {
        i = 1;
        for (; (i + 1) * i / 2 <= k; ++ i) tmp.emplace_back(ans[j].first, h ++);
        k -= i * (i - 1) / 2;
    }
    ans.insert(ans.end(), tmp.begin(), tmp.end());
    cout << ans.size() << "\n";
    for (auto [x, y] : ans) cout << x << " " << y << "\n";
    return;
}
signed main() {
    cin.tie(0) -> sync_with_stdio(0);
    int _ = 1; cin >> _;
    while(_ --) solve();
    return 0;
}