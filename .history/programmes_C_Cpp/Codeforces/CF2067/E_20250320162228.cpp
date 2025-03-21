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
    return;
}
signed main() {
    cin.tie(0) -> sync_with_stdio(0);
    int _ = 1; //cin >> _;
    while(_ --) solve();
    return 0;
}