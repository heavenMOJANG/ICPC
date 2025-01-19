#pragma GCC optimize(1)
#pragma GCC optimize(2)
#pragma GCC optimize(3,"Ofast","inline")
#include <bits/stdc++.h>
#define int long long
using namespace std;
constexpr int INF = 0x7fffffff;
void solve() {
    int n; cin >> n;
    vector<int> a(n);
    int maxn{}, minn = INF, secMin = INF;
    for (int i = 0; i < n; ++ i){
        cin >> a[i];
        maxn = max(maxn, a[i]);
        minn = min(minn, a[i]);
    }
    if (n == 1) {cout << "0\n"; return;}
    sort(a.begin(), a.end());
    for (int i = 0; i < n; ++ i) if (a[i] > minn) {secMin = a[i]; break;}
    int ans{};
    if (secMin) {
        ans += maxn - secMin;
        for (int i = 0; i < n - 1; ++ i) ans += maxn - minn;
    } else {
        for (int i = 0; i < n; ++ i) ans += maxn - minn;
    }
    cout << ans << "\n";
    return;
}
signed main() {
    cin.tie(0) -> sync_with_stdio(0);
    int _ = 1; cin >> _;
    while(_ --) solve();
    return 0;
}