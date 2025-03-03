#pragma GCC optimize(1)
#pragma GCC optimize(2)
#pragma GCC optimize(3, "Ofast", "inline")
#include <bits/stdc++.h>
#define int long long
using namespace std;
constexpr int INF = 0x7fffffff;
void solve() {
    int n; cin >> n;
    vector<int> a(n);
    set<int> s;
    for (int i = 0; i < n; ++ i) cin >> a[i];
    for (int k = 0; k < (1ll << n); ++ k) {
        int xsum = 0, sum;
        for (int i = 0; i < n; ++ i)
            if (k & (1ll << i)) xsum ^= a[i];
            else sum += a[i];
        xsum ^= sum;
        s.insert(xsum);
    }
    cout << s.size() << "\n";
    return;
}
signed main() {
    cin.tie(0) -> sync_with_stdio(0);
    int _ = 1; //cin >> _;
    while(_ --) solve();
    return 0;
}