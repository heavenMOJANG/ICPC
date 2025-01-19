#pragma GCC optimize(1)
#pragma GCC optimize(2)
#pragma GCC optimize(3,"Ofast","inline")
#include<bits/stdc++.h>
#define int long long
#define pii pair<int, int>
using namespace std;
constexpr int inf = 0x7fffffff;
struct Node {
    int a, c;
    bool operator < (const Node & x) const {
        return a < x.a;
    }
};
void solve() {
    int n, m; cin >> n >> m;
    vector<Node> f(n);
    for (int i = 0; i < n; ++ i) cin >> f[i].a;
    for (int i = 0; i < n; ++ i) cin >> f[i].c;
    sort(f.begin(), f.end());
    int maxn = 0;
    for (int i = 0; i < n; ++ i) {
        auto [x, y] = f[i];
        int t = min(m / x, y);
        int r = m - t * x;
        int sum = t * x;
        maxn = maxn(maxn, sum);
        if (i + 1 < n && f[i + 1].a == x + 1) {
            int t2 = min(r / f[i + 1].a, f[i + 1].c);
            sum += t2 * (x + 1);
            r -= t2 * (x + 1);
            int k = f[i].c - t2;
            sum += min(t, min(k, r));
        }
        maxn = max(maxn, sum);
    }
    cout << maxn << "\n";
    return;
}
signed main() {
    cin.tie(0) -> sync_with_stdio(0);
    int _ = 1; cin >> _;
    while(_ --) solve();
    return 0;
}