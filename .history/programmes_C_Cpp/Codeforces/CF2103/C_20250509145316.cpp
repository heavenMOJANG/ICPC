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

    return;
}
signed main() {
    cin.tie(0) -> sync_with_stdio(0);
    int _ = 1; //cin >> _;
    while(_ --) solve();
    return 0;
}