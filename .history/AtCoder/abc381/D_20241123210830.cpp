#pragma GCC optimize(1)
#pragma GCC optimize(2)
#pragma GCC optimize(3, "Ofast", "inline")
#include <bits/stdc++.h>
#define int long long
using namespace std;
constexpr int INF = 0x7fffffff;
int cnt[200010];
int calc(vector<int> v) {
    if (!v.size()) return 0;
    int l{}, r{}, res{};
    while (r < v.size()) {
        if (v[r] == -1) {
            for (int i = l; i < r; ++ i) cnt[v[i]] --, l ++;
            l = r = r + 1;
            continue;
        }
        cnt[v[r]] ++;
        while (l < r && cnt[v[r]] > 1) cnt[v[l]] --, l ++;
        res = max(res, (r - l + 1) * 2);
    }
}
void solve() {
    int n; cin >> n;
    vector<int> a(n);
    for (int i = 0; i < n; ++ i) cin >> a[i];
    int maxn{};
    vector<int> b0, b1;
    for (int i = 0; i + 1 < n; i += 2)
        if (a[i] == a[i + 1]) b0.emplace_back(a[i]);
        else b0.emplace_back(-1);
    for (int i = 1; i + 1 < n; i += 2)
        if (a[i] == a[i + 1]) b1.emplace_back(a[i]);
        else b1.emplace_back(-1);
    cout << maxn << "\n";
    return;
}
signed main() {
    cin.tie(0) -> sync_with_stdio(0);
    int _ = 1; //cin >> _;
    while(_ --) solve();
    return 0;
}