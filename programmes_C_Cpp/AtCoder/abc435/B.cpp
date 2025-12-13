#pragma GCC optimize(3, "Ofast", "inline")
#include <bits/stdc++.h>
#define int long long
using namespace std;
constexpr int INF = 0x7fffffff;
void solve() {
    int n; cin >> n;
    vector<int> a(n + 1, 0), p = a;
    for (int i = 1; i <= n; ++ i) {
        cin >> a[i];
        p[i] = p[i - 1] + a[i];
    }
    int cnt{};
    for (int l = 1; l <= n; ++ l)
        for (int r = l; r <= n; ++ r) {
            int ok = 1;
            for (int i = l; i <= r; ++ i) if ((p[r] - p[l - 1]) % a[i] == 0) ok = 0;
            cnt += ok;
        }
    cout << cnt << "\n";
    return;
}
signed main() {
    cin.tie(nullptr) -> sync_with_stdio(false);
    int _ = 1; //cin >> _;
    while(_ --) solve();
    return 0;
}