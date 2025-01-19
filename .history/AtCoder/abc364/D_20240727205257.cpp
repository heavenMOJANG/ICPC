#pragma GCC optimize(1)
#pragma GCC optimize(2)
#pragma GCC optimize(3,"Ofast","inline")
#include<bits/stdc++.h>
#define int long long
using namespace std;
constexpr int inf = 0x7fffffff;
void solve() {
    int n, q; cin >> n >> q;
    vector<int> a(n);
    map<int, int> mp;
    for (int i = 0; i < n; ++ i) cin >> a[i];
    sort (a.begin(), a.end());
    while (q --) {
        int b, k; cin >> b >> k;
        int l = 0, r = n - k;
        while (l < r) {
            int mid = l + r >> 1;
            if (b - a[mid] > a[mid + k - 1] - b) l = mid + 1;
            else r = mid;
        }
        if (l > 0 && abs(a[l - 1] - b) <= abs(a[l + k - 1] - b)) l --;
        cout << max (abs(b - a[l]), abs(b - a[l + k - 1])) << "\n";
    }
    return;
}
signed main() {
    cin.tie(0) -> sync_with_stdio(0);
    int _ = 1; //cin >> _;
    while(_ --) solve();
    return 0;
}