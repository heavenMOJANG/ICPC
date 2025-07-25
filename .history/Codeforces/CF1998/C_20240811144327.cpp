#pragma GCC optimize(1)
#pragma GCC optimize(2)
#pragma GCC optimize(3,"Ofast","inline")
#include<bits/stdc++.h>
#define int long long
using namespace std;
constexpr int INF = 0x7fffffff;
void solve() {
    int n, k; cin >> n >> k;
    vector<int> a(n + 1), b(n + 1);
    for (int i = 1; i <= n; ++ i) cin >> a[i];
    for (int i = 1; i <= n; ++ i) cin >> b[i];
    auto c = a;
    sort(a.begin() + 1, a.end());
    vector<int> pos[2], pre[2];
    pos[0].emplace_back(0);
    pos[1].emplace_back(1);
    for (int i = 1; i <= n; ++ i) pos[b[i]].emplace_back(a[i]);
    for (int i =0; i < 2; ++ i) {
        sort(pos[i].begin() + 1, pos[i].end());
        pre[i].resize(pos[i].size());
        for (int j = 1; j <= pre[i].size(); ++ i) pre[i][j] = pre[i][j - 1] + pos[i][j]; 
    }
    int ans = 0;
    for (int i = 1; i <= n; ++ i) {
        if (b[i])
            ans = max(ans, a[i] + k + (a[i] > c[n / 2] ? c[n / 2] : c[n / 2 + 1]));
        else {
            function<bool(int)> check = [&](int mid) {
                int cnt1 = pos[0].size() - (lower_bound(pos[0].begin(), pos[0].end(), mid) - pos[0].begin());
                if (a[i] >= mid) cnt1 --;
                if (cnt1 >= (n - 1) / 2 + 1) return 1;
                int tmp = (n - 1)/ 2 + 1 - cnt1;
                if (pos[1].size() - 1 < tmp) return 0;
                int r = upper_bound(pos[1].begin(), pos[1].end(), mid) - pos[1].begin();
                int l = pos[1].size() - tmp;
                if (l >= r) return 1;
                int res = mid * (r - l) - (pre[1][r] - pre[1][l - 1]);
                return res <= k;
            }
        }
    }
}
signed main() {
    cin.tie(0) -> sync_with_stdio(0);
    int _ = 1; //cin >> _;
    while(_ --) solve();
    return 0;
}