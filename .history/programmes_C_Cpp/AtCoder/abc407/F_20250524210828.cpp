#pragma GCC optimize(1)
#pragma GCC optimize(2)
#pragma GCC optimize(3, "Ofast", "inline")
#include <bits/stdc++.h>
#define int long long
using namespace std;
constexpr int INF = 0x7fffffff;
void solve() {
    int n; cin >> n;
    vector<int> a(n + 2, INF), l(n + 2), r(n + 2);
    for (int i = 1; i <= n; ++ i) cin >> a[i];
    stack<int> s; s.push(0);
    for (int i = 1; i <= n; ++ i) {
        while (!s.empty() && a[s.top()] <= a[i]) s.pop();
        l[i] = s.top();
        s.push(i);
    }
    while (!s.empty()) s.pop(); s.push(n + 1);
    for (int i = n; i; -- i) {
        while (!s.empty() && a[s.top()] < a[i]) s.pop();
        r[i] = s.top();
        s.push(i);
    }
    vector<int> d0(n + 2), d1(n + 2);
    for (int i = 1; i <= n; ++ i) {
        auto [L, R] = minmax_element(i - l[i], r[i] - i);
        if (L >= 1) d1[1] += a[i], d1[L + 1] -= a[i];
        if (L + 1 <= R) d0[L + 1] += a[i] * L, d0[R + 1] -= a[i] * L;
        if (R + 1 <= r[i] - l[i] - 1) {
            d1[R + 1] -= a[i], d1[r[i] - l[i] - 1] += a[i];
            d0[R + 1] += a[i] * (r[i] - l[i] - 1), d0[r[i] - l[i] - 1] -= a[i] * (r[i] - l[i] - 1);
    }
    vector<int> p0(n + 2, 0), p1(n + 2, 0);
    vector<int> ans(n);
    for (int i = 1; i <= n; ++ i) {
        p1[i] = p1[i - 1] + d1[i];
        p0[i] = p0[i - 1] + d0[i];
    }
    return;
}
signed main() {
    cin.tie(0) -> sync_with_stdio(0);
    int _ = 1; //cin >> _;
    while(_ --) solve();
    return 0;
}