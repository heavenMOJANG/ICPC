#pragma GCC optimize(3, "Ofast", "inline")
#include <bits/stdc++.h>
#define int long long
using namespace std;
constexpr int INF = 0x7fffffff;
void solve() {
    int n, k; cin >> n >> k;
    vector<int> a(n);
    for (auto && x : a) cin >> x;
    int l = 1, r = n + 1;
    auto check = [&](int x, int& ql, int& qr) {
        vector<int> pre(n + 1, 0);
        for (int i = 1; i <= n; ++ i) pre[i] = pre[i - 1] + (a[i - 1] >= x ? 1 : -1);
        int minn{}, pos{};
        for (int i = k; i <= n; ++ i) {
            if (pre[i - k] < minn) {
                minn = pre[i - k];
                pos = i - k;
            }
            if (pre[i] - minn >= 0) {
                ql = pos + 1, qr = i;
                return true;
            }
        }
        return false;
    };
    while (l < r) {
        int mid = l + r >> 1, rl, rr;
        if (check(mid, rl, rr)) l = mid + 1;
        else r = mid;
    }
    int al{}, ar{};

    return;
}
signed main() {
    cin.tie(nullptr) -> sync_with_stdio(false);
    int _ = 1; //cin >> _;
    while(_ --) solve();
    return 0;
}