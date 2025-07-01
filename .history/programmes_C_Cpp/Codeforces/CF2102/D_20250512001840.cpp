#pragma GCC optimize(1)
#pragma GCC optimize(2)
#pragma GCC optimize(3, "Ofast", "inline")
#include <bits/stdc++.h>
#define int long long
using namespace std;
constexpr int INF = 0x7fffffff;
constexpr int N = 2e5 + 10;
int calc(vector<int>& v) {
    function<int(int, int)> merge = [&](int l, int r) {
        if (r - l <= 1) return 0;
        int m = l + r >> 1;
        int res = merge(l, m) ^ merge(m, r);
        vector<int> tmp;
        int i = l, j = m;
        while (i < m || j < r) {
            if (j == r || (i < m && v[i] <= v[j])) {
                tmp.push_back(v[i++]);
            } else {
                res ^= ((m - i) & 1);
                tmp.push_back(v[j++]);
            }
        }
        for (int k = l; k < r; k++) v[k] = tmp[k - l];
        return res;
    };
    return res;
}
void solve() {
    int n; cin >> n;
    vector<int> o, e;
    o.emplace_back(0); e.emplace_back(0);
    for (int i{}, x; i < n; ++ i) {
        cin >> x;
        if (i & 1) e.emplace_back(x);
        else o.emplace_back(x);
    }
    int so = calc(o), se = calc(e);
    cout << so << "\n" << se << "\n";
    // if (so % 2 == se % 2) {
    //     sort(o.begin() + 1, o.end());
    //     sort(e.begin() + 1, e.end());
    //     for (int i = 1; i <= n / 2; ++ i) cout << o[i] << " " << e[i] << " ";
    //     if (n & 1) cout << o[n / 2 + 1] << "\n";
    //     else cout << "\n";
    // } else {
    //     vector oo = o, ee = e;
    //     sort(oo.begin() + 1, oo.end());
    //     sort(ee.begin() + 1, ee.end());
    //     vector<int> ans0, ans1;
    //     for (int i = 1; i <= n / 2; ++ i) {
    //         ans0.emplace_back(o[i]);
    //         ans0.emplace_back(ee[i]);
    //         ans1.emplace_back(oo[i]);
    //         ans1.emplace_back(e[i]);
    //     }
    //     if (n & 1) {
    //         ans0.emplace_back(o[n / 2 + 1]);
    //         ans1.emplace_back(oo[n / 2 + 1]);
    //     }
    //     int flag{};
    //     for (int i{}; i < n; ++ i) {
    //         if (ans0[i] < ans1[i]) { flag = -1; break; }
    //         if (ans1[i] < ans0[i]) { flag = 1; break;}
    //     }
    //     if (flag == -1) for (int i{}; i < n; ++ i) cout << ans0[i] << " \n"[i == n - 1];
    //     else for (int i{}; i < n; ++ i) cout << ans1[i] << " \n"[i == n - 1];
    // }
    return;
}
signed main() {
    cin.tie(0) -> sync_with_stdio(0);
    int _ = 1; cin >> _;
    while(_ --) solve();
    return 0;
}