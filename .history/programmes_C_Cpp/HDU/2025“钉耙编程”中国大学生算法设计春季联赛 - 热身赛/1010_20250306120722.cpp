#pragma GCC optimize(1)
#pragma GCC optimize(2)
#pragma GCC optimize(3, "Ofast", "inline")
#include <bits/stdc++.h>
#define int long long
using namespace std;
constexpr int INF = 0x7fffffff;
void solve() {
    int n; cin >> n;
    vector<int> a(n + 1);
    for (int i = 1; i <= n; ++ i) cin >> a[i];
    vector<int> pre(n + 1, 0);
    int sum = a[1];
    pre[1] = abs(sum);
    for (int i = 2; i <= n; ++ i) {
        if (abs(sum + a[i]) < abs(sum)) {
            sum = a[i];
            pre[i] += abs(a[i]);
        } else {
            sum += a[i];
            pre[i] = pre[i - 1] + abs(sum);
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