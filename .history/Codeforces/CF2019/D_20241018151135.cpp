#pragma GCC optimize(1)
#pragma GCC optimize(2)
#pragma GCC optimize(3,"Ofast","inline")
#include <bits/stdc++.h>
#define int long long
using namespace std;
constexpr int INF = 0x7fffffff;
void solve() {
    int n; cin >> n;
    vector<int> a(n + 2);
    a[0] = a[n + 1] = INF;
    int minn = -1;
    for (int i = 1; i <= n; ++ i) {
        cin >> a[i];
        if (minn == -1 || a[minn] > a[i]) minn = i;
    }
    vector<int> pre(n + 2, 0), suf(n + 2, 0);
    for (int i = 1; i <= n; ++ i) {
        pre[i] = pre[i - 1];
        if (!pre[i - 1] || a[i] < a[pre[i - 1]]) pre[i] = i;
    }
    for (int i = n; i; -- i) {
        suf[i] = suf[i + 1];
        if (!suf[i + 1] || a[i] < a[suf[i + 1]]) suf[i] = i;
    }
    auto check = [&](int x) {
        if (!x) return 0;
        int l = x, r = x, cur = 1;
        while (l > 1 || r < n) {
            if (a[pre[l - 1]] < a[suf[r + 1]]) {
                for (int i = l - 1; i >= pre[l - 1]; -- i) {
                    cur ++;
                    if (a[i] < cur) return 0;
                }
                l = pre[l - 1];
            } else {
                for (int i = r + 1; i <= suf[r + 1]; ++ i) {
                    cur ++;
                    if (a[i] < cur) return 0;
                }
                r = suf[r + 1];
            }
        }
        return 1;
    };
    return;
}
signed main() {
    cin.tie(0) -> sync_with_stdio(0);
    int _ = 1; //cin >> _;
    while(_ --) solve();
    return 0;
}