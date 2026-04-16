#pragma GCC optimize(3, "Ofast", "inline")
#include <bits/stdc++.h>
#define int long long
using namespace std;
constexpr int INF = 0x7fffffff;
void solve() {
    int n, m; cin >> n >> m;
    vector<int> a(n);
    for (auto && x : a) cin >> x;
    int need = (n + m + 1) / 2;
    auto check = [&](int x){
        unordered_map<int, int> um;
        int cur{}, add{}, tot{};
        function<int(int, int)> f = [&](int x, int z) {
            if (x < z) return 0;
            if (x < 2 * z) return 1;
            auto it = um.find(x);
            if (it != um.end()) return it->second;
            int left = x / 2;
            int right = x - left;
            return um[x] = f(left, z) + f(right, z);
        };
        for (int aa : a) {
            if (aa >= x) cur++;
            int fa = f(aa, x);
            if (fa > 0) add += fa - 1;
            if (aa < x) tot += aa - 1;
        }
        int less = min(add, m), R = m - less;
        int res{};
        if (R <= tot) res = cur + less;
        else res = cur + less - (R - tot);
        return res >= need;
    };

    int l = 1, r = *max_element(a.begin(), a.end()), ans = 1;
    while (l <= r) {
        int mid = (l + r) >> 1;
        if (check(mid)) ans = mid, l = mid + 1;
        else r = mid - 1;
    }

    cout << ans << '\n';
}
signed main() {
    cin.tie(nullptr) -> sync_with_stdio(false);
    int _ = 1; cin >> _;
    while(_ --) solve();
    return 0;
}