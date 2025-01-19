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
    auto calc = [&](vector<int> & v) {
        sort(v.begin(), v.end());
        vector<int> pre;
        int cnt = 0;
        int pres = 0, sufs = accumulate(v.begin(), v.end(), 0ll);
        int tmp = 0;
        for (int i = -m; i <= m; ++ i) {
            while (cnt < n && v[cnt] < i) {
                pres += v[i];
                sufs -= v[i];
                cnt ++;
            }
            tmp = cnt * i - pres + sufs - (n - cnt) * i;
            pre.emplace_back(tmp);
        }
        return pre;
    };
    int ans = 0, cnt = 0;
    for (int i = 2 * m; i >= 0; -- i) {
        while (cnt <= 2 * m && prex[cnt] + prey[cnt] <= d) cnt ++;
        ans += cnt;
    }
    cout << ans << "\n";
}
signed main() {
    cin.tie(0) -> sync_with_stdio(0);
    int _ = 1; //cin >> _;
    while(_ --) solve();
    return 0;
}