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
    while (!s.empty()) s.pop();
    s.push(n + 1);
    return;
}
signed main() {
    cin.tie(0) -> sync_with_stdio(0);
    int _ = 1; //cin >> _;
    while(_ --) solve();
    return 0;
}