#pragma GCC optimize(1)
#pragma GCC optimize(2)
#pragma GCC optimize(3,"Ofast","inline")
#include<bits/stdc++.h>
#define int long long
using namespace std;
constexpr int INF = 0x7fffffff;
void solve() {
    int n; cin >> n;
    vector<int> a(n + 1);
    for (int i = 1; i <= n; ++ i) cin >> a[i];
    if (n == 1) {cout << a[1] << "\n"; return;}
    sort(a.begin() + 1, a.begin() + 1 + n);
    int g = __gcd(a[1], a[2]);
    for (int i = 3; i <= n; ++ i) g = __gcd(g, a[i]);
    int d = a[1] / g, j = 1, ans = d;
    while (d > 1 && j < n) {
        int minn = INF, k = j + 1;
        for (int i = j + 1; i <= n; ++ i) {
            if (minn > __gcd(a[i] / g, d)) {
                minn = __gcd(a[i] / g, d);
                k = i;
            }
        }
        ans += minn;
        swap(a[j + 1], a[k]);
        d = minn;
        j ++;
    }
    ans += n - j;
    cout << ans * g << "\n";
    return;
}
signed main() {
    cin.tie(0) -> sync_with_stdio(0);
    int _ = 1; cin >> _;
    while(_ --) solve();
    return 0;
}