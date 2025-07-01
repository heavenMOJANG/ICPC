#pragma GCC optimize(1)
#pragma GCC optimize(2)
#pragma GCC optimize(3, "Ofast", "inline")
#include <bits/stdc++.h>
#define int long long
using namespace std;
constexpr int INF = 0x7fffffff;
void solve() {
    int n, k; cin >> n >> k;
    vector<int> a(n + 1);
    for (int i = 1; i <= n; ++ i) cin >> a[i];
    vector<int> sum(n + 1, 0);
    for (int i = 1; i <= n; ++ i) {
        if (a[i] <= k) sum[i] ++;
        sum[i] += sum[i - 1]; 
    }
    vector<int> pre, suf;
    for (int i = 1; i <= n; ++ i)
        if (sum[i] >= (i + 1) / 2) pre.emplace_back(i);
    for (int i = 1; i <= n; ++ i)
        if (sum[n] - sum[i - 1] >= (n - i + 2) / 2) suf.emplace_back(i);
    if (pre.size() && suf.size() && pre[0] + 1 < suf.back()) cout << "YES\n";
    else {
        if (pre.size() > 2 || suf.size() > 2) { cout << "YES\n"; return; }
        if (pre.size() == 2 && (sum[pre[1]] - sum[pre[0]]) >= (pre[1] - pre[0] + 1) / 2) { cout << "YES\n"; return; }
        if (suf.size() == 2 && (sum[suf[1] - 1] - sum[suf[0] - 1]) >= (suf[1] - suf[0] + 1) / 2) { cout << "YES\n"; return; }
    }
    cout << "NO\n";
    return;
}
signed main() {
    cin.tie(0) -> sync_with_stdio(0);
    int _ = 1; cin >> _;
    while(_ --) solve();
    return 0;
}