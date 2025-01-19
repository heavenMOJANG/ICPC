#pragma GCC optimize(1)
#pragma GCC optimize(2)
#pragma GCC optimize(3,"Ofast","inline")
#include<bits/stdc++.h>
#define int long long
using namespace std;
constexpr int INF = 0x7fffffff;
void solve() {
    int l, r; cin >> l >> r;
    vector<int> v;
    v.emplace_back(0);
    v.emplace_back(0);
    for (int i = 3; i <= 2e5; i *= 3) v.emplace_back(i);
    int ans = 0;
    while (l) {
        l /= 3;
        ans ++;
    }
    ans *= 2;
    l ++;
    for (int i = 2; i < v.size(); ++ i) {
        if (l <= v[i] && v[i] <= r) {
            ans += (v[i] - l) * (i - 1);
        else if (v[i] >= r) {
            ans += (r - l + 1) * (i - 1);
            break;
        }
    }
    cout << ans << "\n";
    return;
}
signed main() {
    cin.tie(0) -> sync_with_stdio(0);
    int _ = 1; //cin >> _;
    while(_ --) solve();
    return 0;
}