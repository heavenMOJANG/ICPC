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
    for (int i = 1; i <= n; ++ i) cin >> a[i];
    int p = 0;
    for (int i = n; i >= 2; -- i) 
        if (a[i] >= a[i - 1]) {
            p = i;
            break;
        }
    int sum = 0, len = 0;
    for (int i = p; i >= 2;) {
        if (a[i] >= a[i - 1]) {
            sum += a[i];
            len ++;
            -- i;
        } else {
            int q = sum / len;
            int r = sum % len;
            if (a[i - 1] <= q + r) {
                sum += a[i];
                len ++;
                -- i;
            } else {
                for (int j = i; j <= p; ++ j) a[j] = q;
                for (int k = 1; k <= r; ++ k) a[i + k - 1] ++;
                sum = 0, len = 0;
                while (a[p] < a[p - 1]) p--;
                i = p;
            }
        }
        cout << sum << "\n";
    }
    if (sum) {
        int q = sum / len;
        int r = sum % len;
        for (int i = 1; i <= p; ++ i) a[i] = q;
        for (int j = 1; j <= r; ++ j) a[j] ++;
    }
    for (int i = 1; i <= n; ++ i) cout << a[i] << " \n"[i == n];
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