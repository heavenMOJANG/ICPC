#pragma GCC optimize(1)
#pragma GCC optimize(2)
#pragma GCC optimize(3,"Ofast","inline")
#include<bits/stdc++.h>
#define int long long
using namespace std;
constexpr int inf = 0x7fffffff;
void solve() {
    int n, f, k; cin >> n >> f >> k;
    vector<int> a(n);
    for (int i = 0; i < n; ++ i) cin >> a[i];
    int p = a[f - 1], cnt0 = 0, cnt1 = 0;
    for (int i = 0; i < n; ++ i) {
        if (a[i] > a[f - 1]) cnt0 ++;
        if (a[i] == a[f - 1]) cnt1 ++;
    }
    if (k <= cnt0) cout << "NO\n";
    if (cnt0 < k && k < cnt0 + cnt1) cout << "MAYBE\n";
    if (k >= cnt0 + cnt1) cout << "YES\n";
    return;
}
signed main() {
    cin.tie(0) -> sync_with_stdio(0);
    int _ = 1; cin >> _;
    while(_ --) solve();
    return 0;
}