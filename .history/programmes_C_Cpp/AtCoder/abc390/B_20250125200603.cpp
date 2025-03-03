#pragma GCC optimize(1)
#pragma GCC optimize(2)
#pragma GCC optimize(3, "Ofast", "inline")
#include <bits/stdc++.h>
#define int long long
using namespace std;
constexpr int INF = 0x7fffffff;
void solve() {
    int n; cin >> n;
    vector<int> a(n);
    for (int i = 0; i < n; ++ i) cin >> a[i];
    if (n == 2) { cout << "Yes\n"; return; }
    for (int i = 0; i < n - 2; ++ i) if ( a[i + 1] * a[i + 1] != a[i] * a[i + 2]) { cout << "No\n"; return; }
    cout << "Yes\n";
    return;
}
signed main() {
    cin.tie(0) -> sync_with_stdio(0);
    int _ = 1; //cin >> _;
    while(_ --) solve();
    return 0;
}