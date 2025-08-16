#pragma GCC optimize(3, "Ofast", "inline")
#include <bits/stdc++.h>
#define int long long
using namespace std;
constexpr int INF = 0x7fffffff;
void solve() {
    int n, k, x; cin >> n >> k >> x;
    vector<string> a(n);
    for (int i{}; i < n; ++ i) cin >> a[i];
    string tmp{};
    vector<string> ans;
    function<void(int, string)> dfs = [&](int d, string& cur) {
        if (d == k) {
            ans.emplace_back(cur);
            return;
        }
        for (int i{}; i < n; ++ i)
    };
    return;
}
signed main() {
    cin.tie(nullptr) -> sync_with_stdio(false);
    int _ = 1; //cin >> _;
    while(_ --) solve();
    return 0;
}