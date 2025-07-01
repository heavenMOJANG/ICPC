#pragma GCC optimize(1)
#pragma GCC optimize(2)
#pragma GCC optimize(3, "Ofast", "inline")
#include <bits/stdc++.h>
#define int long long
using namespace std;
constexpr int INF = 0x7fffffff;
constexpr int N = 2e5 + 10;
int calc(vector<int>& v) {
    function<int(int, int)> merge = [&](int l, int r) ->int {
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
    return merge(0, v.size());
}
void solve() {
    int n; cin >> n;
    vector<int> o, e;
    for (int i{}, x; i < n; ++ i) {
        cin >> x;
        if (i & 1) e.emplace_back(x);
        else o.emplace_back(x);
    }
    int so = calc(o), se = calc(e);
    if (so % 2 == se % 2) {
        for (int i{}; i < n / 2; ++ i) cout << o[i] << " " << e[i] << " ";
        if (n & 1) cout << o[n / 2] << "\n";
        else cout << "\n";
    } else {
        vector oo = o, ee = e;
        vector<int> ans0, ans1;
        int minn = INF, p = -1;
        for (int i{}; i + 1 < oo.size(); ++ i) if (oo[i + 1] - oo[i] < minn) minn = oo[i + 1] - oo[i], p = i;
        swap(oo[p], oo[p + 1]);
        minn = INF, p = -1;
        for (int i{}; i + 1 < ee.size(); ++ i) if (ee[i + 1] - ee[i] < minn) minn = ee[i + 1] - ee[i], p = i;
        swap(ee[p], ee[p + 1]);
        for (int i{}; i < n / 2; ++ i) {
            ans0.emplace_back(o[i]);
            ans0.emplace_back(ee[i]);
            ans1.emplace_back(oo[i]);
            ans1.emplace_back(e[i]);
        }
        if (n & 1) {
            ans0.emplace_back(o[n / 2]);
            ans1.emplace_back(oo[n / 2]);
        }
        if (ans0 < ans1) for (int i{}; i < n; ++ i) cout << ans0[i] << " \n"[i == n - 1];
        else for (int i{}; i < n; ++ i) cout << ans1[i] << " \n"[i == n - 1];
    }
    return;
}
signed main() {
    cin.tie(0) -> sync_with_stdio(0);
    int _ = 1; cin >> _;
    while(_ --) solve();
    return 0;
}