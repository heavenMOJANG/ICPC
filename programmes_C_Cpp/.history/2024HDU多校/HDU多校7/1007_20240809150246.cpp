#pragma GCC optimize(1)
#pragma GCC optimize(2)
#pragma GCC optimize(3,"Ofast","inline")
#include<bits/stdc++.h>
#define int long long
using namespace std;
constexpr int INF = 0x7fffffff;
void solve() {
    int n, m, k; cin >> n >> m >> k;
    vector<int> a(n + 1);
    for (int i = 1; i <= n; ++ i) cin >> a[i];
    vector<int> l (n + 1, 0), r(n + 1, 0), dp(n + 1, 0);
    l[1] = 1;
    for (int i = 2; i <= n; ++ i) {
        int j = i - 1;
        while (j && abs(a[i]- a[j]) <= k) j --;
        l[i] = j + 1;
    }
    r[n] = n;
    for (int i = n - 1; i; -- i) {
        int j = i - 1;
        while (j <= n && abs(a[i] - a[j]) <= k) j ++;
        r[i] = j + 1;
    }
    deque<int> dq;
    for (int i = 1; i <= n; ++ i) {
        while(!dq.empty() && dq.front() < l[i]) dq.pop_front();
        if (dq.empty()) dp[i] = i - 1;
        else {
            int j = dq.front();
            dp[i] = dp[j] + (i - j + 1);
        }
        while (!dq.empty() && dp[dq.back()] - dq.back() >= dp[i] - i) dq.pop_back();
        dq.push_back(i);
    }
    int q; cin >> q;
    while (q --) {
        int L, R; cin >> L >> R;
        cout << dp[R] - dp[L] - (R - L + 1) << "\n";
    }
}
signed main() {
    cin.tie(0) -> sync_with_stdio(0);
    int _ = 1; cin >> _;
    while(_ --) solve();
    return 0;
}