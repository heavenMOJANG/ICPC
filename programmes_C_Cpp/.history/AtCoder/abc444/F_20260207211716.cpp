#pragma GCC optimize(3, "Ofast", "inline")
#include <bits/stdc++.h>
#define int long long
using namespace std;
constexpr int INF = 0x7fffffff;
void solve() {
    int n, m; cin >> n >> m;
    vector<int> a(n);
    for (auto && x : a) cin >> x;
    int l = 1, r = *max_element(a.begin(), a.end()), ans = 1;
    auto check = [&](int x) {
        if (x == 0) return 0ll;
        int need = (n + m + 1) / 2;
        int cur{}, cnt{}, flag{};
        for (int aa : a) {
            if (aa < x) flag = 1;
            else  cur ++, cnt += (aa / x);
        }
        int d = cnt - cur, res{};
        if (m <= d) res = cur + m;
        else {
            res = cnt;
            if (!flag) res --;
        }
        return res >= need;
    };
    while (l <= r) {
        int mid = l + r >> 1;
        if (check(mid)) ans = mid, l = mid + 1;
        else r = mid - 1;
    }
    cout << ans << "\n";
    return;
}
signed main() {
    cin.tie(nullptr) -> sync_with_stdio(false);
    int _ = 1; cin >> _;
    while(_ --) solve();
    return 0;
}