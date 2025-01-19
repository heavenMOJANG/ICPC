#pragma GCC optimize(1)
#pragma GCC optimize(2)
#pragma GCC optimize(3, "Ofast", "inline")
#include <bits/stdc++.h>
#define int long long
using namespace std;
constexpr int INF = 0x7fffffff;
int check(int x) {
    int f = floor(sqrt(x));
    return f * f == x;
}
void solve() {
    int n; cin >> n;
    if (n & 1) {
        int f{};
        for (int i = 2; i <= sqrt(n); ++ i) {
            if (n % i == 0) 
            {
                int k1 = i, k2 = n / i;
                if (check(k1) && (k1 & 1)) { f = k1; break; }
                if (check(k2) && (k2 & 1)) { f = k2; break; }
            }
        }
        if (f) {
            for (int i = 1; i <= n; ++ i) cout << i % f + 1 << " \n"[i == n];
            return;
        }
        f = 0;
        for (int i = 2; i <= sqrt(n - 1); ++ i) {
            if ((n - 1) % i == 0) 
            {
                int k1 = i, k2 = (n - 1) / i;
                if (check(k1) && (k1 & 1)) { f = k1; break; }
                if (check(k2) && (k2 & 1)) { f = k2; break; }
            }
        }
        if (f) {
            vector<int> ans(n + 1);
            int ff{}, cnt = 2;
            for (int i = 1; i <= n; ++ i) {
                if ((i - 1) % f == 0) ans[i] = 1;
                else {
                    if (ff) ans[i] = cnt ++;
                    else ans[i] = cnt;
                    ff ^= 1;
                }
            }
            for (int i = 1; i <= n; ++ i) cout << ans[i] << " \n"[i == n];
            return;
        }
        cout << "-1\n";
    } else
        for (int i = 1; i <= n; i += 2) cout << i << " " << i << " \n"[i == n - 1];
    return;
}
signed main() {
    cin.tie(0) -> sync_with_stdio(0);
    int _ = 1; cin >> _;
    while(_ --) solve();
    return 0;
}