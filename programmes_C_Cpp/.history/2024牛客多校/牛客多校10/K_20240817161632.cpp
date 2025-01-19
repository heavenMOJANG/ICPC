#pragma GCC optimize(1)
#pragma GCC optimize(2)
#pragma GCC optimize(3,"Ofast","inline")
#include<bits/stdc++.h>
#define int long long
using namespace std;
constexpr int INF = 0x7fffffff;
void solve() {
    int n; cin >> n;
    vector<int> pos, neg;
    int cnt = 0;
    for (int i = 1, x; i <= n; ++ i) {
        cin >> x;
        if (x == 0) cnt ++;
        if (x > 0) pos.emplace_back(x);
        if (x < 0) neg.emplace_back(-x);
    }
    sort(pos.begin(), pos.end());
    sort(neg.begin(), neg.end());
    int ans = 0;
    auto exec = [&](void) {
        for (int i = 0; i < pos.size(); ++ i) {
            if (pos.size() - 1- i >= pos[i]) {
                int l = 0, r = neg.size() - 1, res = -1;
                while (l <= r) {
                    int mid = l + r >> 1;
                    if (-pos[i] + neg.size() - 1 - mid >= neg[mid]) res = mid, l = mid + 1;
                    else r = mid - 1;
                }
                ans = max(ans, res + i + 2);
            }
        }
    };
    exec(); swap(pos, neg);
    exec(); ans += cnt;
    cout << ans << "\n";''
}
signed main() {
    cin.tie(0) -> sync_with_stdio(0);
    int _ = 1; //cin >> _;
    while(_ --) solve();
    return 0;
}