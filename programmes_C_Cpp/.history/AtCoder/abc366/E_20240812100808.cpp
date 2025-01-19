#pragma GCC optimize(1)
#pragma GCC optimize(2)
#pragma GCC optimize(3,"Ofast","inline")
#include<bits/stdc++.h>
#define int long long
using namespace std;
constexpr int INF = 0x7fffffff;
void solve() {
    int n, d; cin >> n >> d;
    vector<int> x(n), y(n);
    for (int i = 0; i < n; ++ i) cin >> x[i] >> y[i];
    int m = 2e6;
    auto calc = [&](vector<int> v) {
        sort(v.begin(), v.end());
        vector<int> pre(m << 1 | 1, 0);
        pre[m + 1] = accumulate(v.begin(), v.end(), 0) + n * m;
        int cnt = 0;
        for (int i = - m + 1; i <= m; ++ i) {
            while (i < n && v[i] < i) cnt ++;
            pre[i] = pre[i - 1] + 2 * i - n;
        }
        return pre;
    };

}
signed main() {
    cin.tie(0) -> sync_with_stdio(0);
    int _ = 1; //cin >> _;
    while(_ --) solve();
    return 0;
}