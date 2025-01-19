#pragma GCC optimize(1)
#pragma GCC optimize(2)
#pragma GCC optimize(3, "Ofast", "inline")
#include <bits/stdc++.h>
#define int long long
using namespace std;
constexpr int INF = 0x7fffffff;
void solve() {
    int n; cin >> n;
    vector<int> a(n + 1), Lmax(n + 1);;
    for (int i = 1; i <= n; ++ i) cin >> a[i];
    vector<int> st(n + 1), dp(n + 1);
    int top = -1;
    for (int i = 1; i <= n; ++ i) {
        while (top && st[top] <= a[i]) top --;
        dp[i] = top == -1 ? a[i] : max(st[top], a[i]);
    }
    return;
}
signed main() {
    cin.tie(0) -> sync_with_stdio(0);
    int _ = 1; //cin >> _;
    while(_ --) solve();
    return 0;
}