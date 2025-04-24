#pragma GCC optimize(1)
#pragma GCC optimize(2)
#pragma GCC optimize(3, "Ofast", "inline")
#include <bits/stdc++.h>
#define int long long
using namespace std;
constexpr int INF = 0x7fffffff;
void solve() {
    int n; cin >> n;
    unordered_map<int, vector<int>> mp;
    vector<int> a(n + 1, 0), b(n + 1, 0);
    for (int i = 1; i <= n; ++ i) cin >> a[i];
    for (int i = 1; i <= n; ++ i) cin >> b[i], mp[a[i] + b[i]].emplace_back(i), a[i] += a[i - 1];
    int maxn{};
    for (auto [d, v] : mp) {
        int l{};
        for (int r{}; r < v.size(); ++ r)
            if (r == v.size() - 1 || v[r + 1] != v[r] + 1) {
                maxn = max(maxn, (a[v[r]] - a[v[l] - 1]) * (r - l + 1));
                l = r + 1;
            }
    }
    cout << maxn << "\n";
    return;
}
signed main() {
    cin.tie(0) -> sync_with_stdio(0);
    int _ = 1; cin >> _;
    while(_ --) solve();
    return 0;
}