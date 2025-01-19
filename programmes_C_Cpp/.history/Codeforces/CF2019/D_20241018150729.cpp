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
    for (int i = 1; i <= n; ++ i) cin >> a[i];
    vector<int> pre(n + 2, 0), suf(n + 2, 0);

    return;
}
signed main() {
    cin.tie(0) -> sync_with_stdio(0);
    int _ = 1; //cin >> _;
    while(_ --) solve();
    return 0;
}