#pragma GCC optimize(1)
#pragma GCC optimize(2)
#pragma GCC optimize(3,"Ofast","inline")
#include <bits/stdc++.h>
#define int long long
using namespace std;
constexpr int INF = 0x7fffffff;
void solve() {
    int k; cin >> k;
    int l = k, r = 2e18;
    auto check = [&](int x) {
        int r = sqrt(x);
        while (r * r > x) r --;
        while ((r + 1) * (r + 1) <= x) r ++;
        return x - sqrt(x) >= k;
    };
    while (l < r) {
        int mid = l + r >> 1;
        if (check(mid)) r = mid;
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