#pragma GCC optimize(1)
#pragma GCC optimize(2)
#pragma GCC optimize(3,"Ofast","inline")
#include<bits/stdc++.h>
#define int long long
using namespace std;
constexpr int INF = 0x7fffffff;
void solve() {
    int n; cin >> n;
    vector<int> a(n);
    int sum{};
    for (auto && x : a) cin >> x, sum += x;
    if (n <= 2) {cout << "-1\n"; return;}
    sort(a.begin(), a.end());
    int avg = a[n / 2];
    int l = 0ll, r = 1e18;
    while (l < r) {
        int mid = l + r >> 1, cur = sum + mid;
        if (cur > avg * 2 * n) r = mid;
        else l = mid + 1;
    }
    cout << l << "\n";
    return;
}
signed main() {
    cin.tie(0) -> sync_with_stdio(0);
    int _ = 1; cin >> _;
    while(_ --) solve();
    return 0;
}