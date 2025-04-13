#pragma GCC optimize(1)
#pragma GCC optimize(2)
#pragma GCC optimize(3, "Ofast", "inline")
#include <bits/stdc++.h>
#define int long long
using namespace std;
constexpr int INF = 0x7fffffff;
void solve() {
    int n; cin >> n;
    vector<int> p(n + 1), d(n + 1);
    for (int i = 1; i <= n; ++ i) cin >> p[i];
    set<int> s;
    for (int i = 1; i <= n; ++ i) {
        cin >> d[i];
        while (!s.count(d[i])) {
            s.insert(d[i]);
            d[i] = p[d[i]];
        }
        cout << s.size() << " \n"[i == n];
    }
    return;
}
signed main() {
    cin.tie(0) -> sync_with_stdio(0);
    int _ = 1; //cin >> _;
    while(_ --) solve();
    return 0;
}