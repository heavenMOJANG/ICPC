#pragma GCC optimize(1)
#pragma GCC optimize(2)
#pragma GCC optimize(3,"Ofast","inline")
#include<bits/stdc++.h>
#define int long long
using namespace std;
constexpr int inf = 0x7fffffff;
void solve() {
    int n; cin >> n;
    vector<int> a(n), x(n);
    for (int i = 0; i < n; ++ i) cin >> a[i];
    int lcm = a[0] * a[1] / __gcd(a[0], a[1]);
    for (int i = 2; i < n; ++ i) {
        int g = __gcd(lcm, a[i]);
        lcm = lcm * a[i] / g;
    }
    for (int i = 0; i < n; ++ i) x[i] = lcm / a[i];
    int sum = 0;
    for (int i = 0; i < n; ++ i) sum += x[i];
    if (lcm <= sum) {cout << "-1\n"; return;}
    for (int i = 0; i < n; ++ i) cout << x[i] << " \n"[i == n - 1];
    return;
}
signed main() {
    cin.tie(0) -> sync_with_stdio(0);
    int _ = 1; cin >> _;
    while(_ --) solve();
    return 0;
}