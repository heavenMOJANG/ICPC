#pragma GCC optimize(1)
#pragma GCC optimize(2)
#pragma GCC optimize(3, "Ofast", "inline")
#include <bits/stdc++.h>
#define int long long
using namespace std;
constexpr int INF = 0x7fffffff;
void solve() {
    int n; cin >> n;
    unordered_map<int, queue<int>> mp;
    vector<int> a(n);
    for (int i = 0; i < n; ++ i) cin >> a[i], mp[a[i]].push(i);
    int maxn{};
    for (int i = 0; i < n; ++ i) {
        mp[a[i]].pop();
        if (!mp[a[i]].empty()) maxn = max(maxn, mp[a[i]].front() - i + 1);
    }
    cout << maxn << "\n";
    return;
}
signed main() {
    cin.tie(0) -> sync_with_stdio(0);
    int _ = 1; //cin >> _;
    while(_ --) solve();
    return 0;
}