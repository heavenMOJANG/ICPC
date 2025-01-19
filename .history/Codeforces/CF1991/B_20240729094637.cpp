#pragma GCC optimize(1)
#pragma GCC optimize(2)
#pragma GCC optimize(3,"Ofast","inline")
#include<bits/stdc++.h>
#define int long long
using namespace std;
constexpr int inf = 0x7fffffff;
void solve() {
    int n; cin >> n;
    vector<int> a(n + 1, 0), b(n);
    for (int i = 0; i < n - 1; ++ i) cin >> b[i];
    a[0] = b[0]; a[n - 1] = b[n - 2];
    for (int i = 1; i < n - 1; ++ i) a[i] = b[i - 1] | b[i];
    for (int i = 0; i < n - 1; ++ i)
        if (a[i] & a[i + 1] != b[i]) {cout << "-1\n"; return;}
    for (int i = 0; i < n; ++ i) cout << a[i] << " \n"[i == n - 1];
    return;
}
signed main() {
    cin.tie(0) -> sync_with_stdio(0);
    int _ = 1; cin >> _;
    while(_ --) solve();
    return 0;
}