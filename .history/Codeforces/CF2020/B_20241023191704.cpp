#pragma GCC optimize(1)
#pragma GCC optimize(2)
#pragma GCC optimize(3,"Ofast","inline")
#include <bits/stdc++.h>
#define int long long
using namespace std;
constexpr int INF = 0x7fffffff;
void solve() {
    int k; cin >> k;
    int l = 0, r = 9e18;
    auto check = [&](int x) {
        return x - sqrt(x) < k;
    };
    while (l < r) {
        int mid = l + r + 1 >> 1;
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