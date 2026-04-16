#pragma GCC optimize(3, "Ofast", "inline")
#include <bits/stdc++.h>
#define int long long
using namespace std;
constexpr int INF = 0x7fffffff;
void solve() {
    int n; cin >> n;
    vector<int> a(n);
    for (auto && x : a) cin >> x;
    int maxn = *max_element(a.begin(), a.end());
    vector<int> cnt(maxn + 10, 0), suf = fq;
    for (int x : a) cnt[x] ++;
    for (int i = maxn; i; -- i) suf[i] = suf[i + 1] + cnt[i];
    string ans;
    int cfg{};
    for (int i = 1; i <= maxn; ++ i) {
        int res = suf[i] + cfg;
        ans += to_string(res % 10);
        cfg = res / 10;
    }
    while (cfg) {
        ans += to_string(cfg % 10);
        cfg /= 10;
    }
    reverse(ans.begin(), ans.end());
    cout << ans << "\n";
    return;
}
signed main() {
    cin.tie(nullptr) -> sync_with_stdio(false);
    int _ = 1; //cin >> _;
    while(_ --) solve();
    return 0;
}