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
    vector<int> suf(n + 2);
    set<int> s; int mex{};
    for (int i = n; i; -- i) {
        s.insert(a[i]);
        while (s.count(mex)) mex ++;
        suf[i] = mex;
    }
    vector<int> pre(n + 1);
    pre[0] = INF;
    for (int i = 1; i <= n; ++ i) {
        pre[i] = pre[i - 1];
        if (a[i]) pre[i] = min(pre[i], a[i]);
    }
    int ans{}, ok = 1;
    for (int i = 1; i <= n && a[i]; ++ i)
        if (pre[i] < suf[i + 1]) { ok = 0; break;}
    if (ok && mex) ans ++;
    for (int i = 1; i <= n; ++ i) ans += a[i] > 0;
    cout << ans << "\n";
    return;
}
signed main() {
    cin.tie(0) -> sync_with_stdio(0);
    int _ = 1; //cin >> _;
    while(_ --) solve();
    return 0;
}