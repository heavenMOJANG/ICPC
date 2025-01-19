#pragma GCC optimize(1)
#pragma GCC optimize(2)
#pragma GCC optimize(3,"Ofast","inline")
#include<bits/stdc++.h>
#define int long long
using namespace std;
constexpr int INF = 0x7fffffff;
vector<int> v;
void solve() {
    int l, r; cin >> l >> r;
    int ans = 0;
    int tmp = l;
    while (tmp) {
        tmp /= 3;
        ans ++;
    }
    ans *= 2;
    l ++;
    for (int i = 2; i < v.size(); ++ i)
        if (l <= v[i] && v[i] <= r) {
            ans += (v[i] - l) * (i - 1);
            l = v[i];
        }
        else if (v[i] >= r) {
            ans += (r - l + 1) * (i - 1);
            cout << ans << "\n";
            break;
        }
    cout << ans << "\n";
    return;
}
signed main() {
    cin.tie(0) -> sync_with_stdio(0);
    v.emplace_back(0);
    v.emplace_back(0);
    for (int i = 3; i <= 2e5; i *= 3) v.emplace_back(i);
    int _ = 1; cin >> _;
    while(_ --) solve();
    return 0;
}