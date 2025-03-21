#pragma GCC optimize(1)
#pragma GCC optimize(2)
#pragma GCC optimize(3, "Ofast", "inline")
#include <bits/stdc++.h>
#define int long long
using namespace std;
constexpr int INF = 0x7fffffff;
void solve() {
    int n; cin >> n;
    vector<int> a(n + 1), vis(n + 1, 0);
    int p1{}, pn{};
    for (int i = 1; i <= n; ++ i) {
        cin >> a[i], vis[a[i]] = 1;
        if (a[i] == 1) p1 = i;
        if (a[i] == n) pn = i;
    }
    auto ask = [&](int i, int j) {
        int res;
        cout << "? " << i << " " << j << endl;
        cin >> res;
        return res;
    };
    for (int i = 1; i <= n; ++ i)
        if (!vis[i]) {
            int res = ask(i, 1);
            cout << (res ? "! B" : "! A") << endl;
            return;
        }
    cout << (ask(p1, pn) < n - 1 || ask(pn, p1) < n - 1 ? "! A" : "! B") << endl;
    return;
}
signed main() {
    cin.tie(0) -> sync_with_stdio(0);
    int _ = 1; //cin >> _;
    while(_ --) solve();
    return 0;
}