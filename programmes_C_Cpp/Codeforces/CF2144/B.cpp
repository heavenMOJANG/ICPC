#pragma GCC optimize(3, "Ofast", "inline")
#include <bits/stdc++.h>
#define int long long
using namespace std;
constexpr int INF = 0x7fffffff;
void solve() {
    int n; cin >> n;
    vector<int> p(n + 1), r(n + 1);
    int cnt{}, pos{};
    for (int i = 1; i <= n; i ++) {
        cin >> p[i];
        if (!p[i]) cnt ++, pos = i;
        else r[p[i]] = i;
    }
    vector<int> a;
    for (int i = 1; i <= n; ++ i) if (!r[i]) a.emplace_back(i);
    vector<int> f(n + 1, 0);
    for (int i = 1; i <= n; ++ i) if (p[i] && p[i] == i) f[i] = 1;
    if (cnt == 1 && a[0] == pos) f[pos] = 1;
    int L = -1, R = -1;
    for (int i = 1; i <= n; ++ i) if (!f[i]) { L = i; break; }
    for (int i = n; i; -- i) if (!f[i]) { R = i; break; }
    if (L == -1) cout << "0\n";
    else cout << (R - L + 1)  << "\n";
    return;
}
signed main() {
    cin.tie(nullptr) -> sync_with_stdio(false);
    int _ = 1; cin >> _;
    while(_ --) solve();
    return 0;
}