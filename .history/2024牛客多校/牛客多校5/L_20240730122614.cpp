#pragma GCC optimize(1)
#pragma GCC optimize(2)
#pragma GCC optimize(3,"Ofast","inline")
#include<bits/stdc++.h>
#define int long long
using namespace std;
constexpr int inf = 0x7fffffff;
constexpr int mod = 998244353;
void solve() {
    int n; cin >> n;
    vector<int> a(n + 1);
    int sum = 0;
    for (int i = 1; i <= n; ++ i) cin >> a[i], sum += a[i];;
    int q = sum / n;
    for (int i = n; i >= 2; -- i)
        if (a[i] > q){
            a[i - 1] += a[i] - q;
            a[i] = q;
        } else if (a[i] > a[i - 1]) {
            int x = (a[i] + a[i - 1]);
            a[i] = x / 2;
            a[i - 1] = x - a[i];
        }
    int ans = 1;
    for (int i = 1; i <= n; ++ i) ans = (ans * a[i]) % mod;
    cout << ans << "\n";
    return;
}
signed main() {
    cin.tie(0) -> sync_with_stdio(0);
    int _ = 1; cin >> _;
    while(_ --) solve();
    return 0;
}