#pragma GCC optimize(3, "Ofast", "inline")
#include <bits/stdc++.h>
#define int long long
using namespace std;
constexpr int INF = 0x7fffffff;
void solve() {
    int n, d; cin >> n >> d;
    vector<int> a(n);
    for (auto && x : a) cin >> x;
    multiset<int> ms, diff;
    auto add = [&](int x) {
        auto it = ms.lower_bound(x);
        if (it != ms.begin() && it != ms.end()) {
            auto prev = it; prev --;
            diff.erase(diff.find(*it - *prev));
        }
        if (it != ms.begin()) {
            auto prev = it; prev --;
            diff.insert(x - *prev);
        }
        if (it != ms.end()) diff.insert(*it - x);
        ms.insert(x);
    };
    auto del = [&](int x) {
        auto it = ms.find(x);
        if (it != ms.begin() && next(it) != ms.end()) {
            auto prev = it, nxt = next(it); prev --;
            diff.insert(*nxt - *prev);
        }
        if (it != ms.begin()) {
            auto prev = it; prev --;
            diff.erase(diff.find(x - *prev));
        }
        if (next(it) != ms.end()) {
            auto nxt = next(it);
            diff.erase(diff.find(*nxt - x));
        }
        ms.erase(it);
    };
    int ans{}, l{};
    for (int r{}; r < n; ++ r) {
        add(a[r]);
        while (!diff.empty() && *diff.begin() < d) del(a[l ++]);
        ans += r - l + 1;
    }
    cout << ans << "\n";
    return;
}
signed main() {
    cin.tie(nullptr) -> sync_with_stdio(false);
    int _ = 1; //cin >> _;
    while(_ --) solve();
    return 0;
}