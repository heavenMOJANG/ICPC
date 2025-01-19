#pragma GCC optimize(1)
#pragma GCC optimize(2)
#pragma GCC optimize(3,"Ofast","inline")
#include<bits/stdc++.h>
#define int long long
using namespace std;
constexpr int inf = 0x7fffffff;
constexpr int mod = 998244353;
struct Node{int sum, len;};
void solve() {
    int n; cin >> n;
    vector<int> a(n + 1, 0);
    for (int i = 1; i <= n; ++ i) cin >> a[i];
    int sum = 0, len = 0;
    queue<pair<int, int>> q;
    for (int i = n; i >= 1; -- i) {
        sum += a[i];
        len ++;
        if (i == 1) {
            int q = sum / len;
            int r = sum % len;
            for (int j = 1; j <= len; ++ j) a[i + j - 1] = q;
            for (int j = 1; j <= r; ++ j) a[i + j - 1] ++;
            break;
        }
        if (a[i] < a[i - 1]) {
            int q = sum / len;
            int r = sum % len;
            if (a[i - 1] > q + r) {
                q.push({sum, len});
                sum = 0;
                len = 0;
            } else continue;
        }
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