#pragma GCC optimize(3, "Ofast", "inline")
#include <bits/stdc++.h>
#define int long long
using namespace std;
constexpr int INF = 0x7fffffff;
void solve() {
    int n, m, c; cin >> n >> m >> c;
    vector<int> a(n);
    for (auto && x : a) cin >> x;
    sort(a.begin(), a.end());
    vector<int> b, p;
    int idx{}, nxt;
    while (idx < n) {
        b.emplace_back(a[idx]);
        nxt = idx + 1;
        while (nxt < n) {
            if (a[nxt] != a[idx]) break;
            nxt ++;
        }
        p.emplace_back(nxt - idx);
        idx = nxt;
    }
    int k = b.size(), r{}, cur{}, ans{};
    for (int i{}; i < k; ++ i) {
        while (cur < c) {
            cur += p[r ++];
            if (r >= k) r -= k;
        }
        if (!i) ans += (m + b[0] - b[k - 1]) * cur;
        else ans += (b[i] - b[i - 1]) * cur;
        cur -= p[i];
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