#pragma GCC optimize(1)
#pragma GCC optimize(2)
#pragma GCC optimize(3, "Ofast", "inline")
#include <bits/stdc++.h>
#define int long long
using namespace std;
constexpr int INF = 0x7fffffff;
constexpr int N = 5e5 + 10;
int cnt[N];
void solve() {
    int n; cin >> n;
    vector<int> a(n);
    for (auto && x: a) cin >> x;
    int maxn = *max_element(a.begin(), a.end());
    fill(cnt, cnt + 1 + n, 0);
    for (auto x : a) cnt[x] ++;
    int ans{};
    for (int d = 1; d <= maxn; ++ d)
        for (int k = 1; (k + 1) * d <= maxn; ++ k)
            ans += cnt[k * d] * cnt[(k + 1) * d];
    cout << ans << "\n";
    return;
}
signed main() {
    cin.tie(0) -> sync_with_stdio(0);
    int _ = 1; cin >> _;
    while(_ --) solve();
    return 0;
}