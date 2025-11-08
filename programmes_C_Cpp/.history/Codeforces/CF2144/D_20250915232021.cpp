#pragma GCC optimize(3, "Ofast", "inline")
#include <bits/stdc++.h>
#define int long long
using namespace std;
constexpr int INF = 0x7fffffff;
void solve() {
    int n, y; cin >> n >> y;
    vector<int> c(n); 
    int maxc{};
    for (auto && x : c) cin >> x, maxc = max(maxc, x);
    vector<int> f(maxc + 10, 0);
    for (int x : c) f[x] ++;
    vector<int> pre(maxc + 10, 0);
    for (int i = 1; i <= maxc; i ++) pre[i] = pre[i - 1] + f[i];
    int maxn = LLONG_MIN;
    for (int x = 2; x <= maxc; ++ x) {
        int s{}, need{}, k = 1;
        while ((k - 1) * x < maxc) {
            int L = (k - 1) * x + 1, R = min(k * x, maxc);
            if (L > R) { k ++; continue; }
            int d = pre[R] - pre[L - 1];
            if (d) {
                s += k * d;
                if (d > f[k]) need += d - f[k];
            }
            k ++;
        }
        maxn = max(maxn, s - need * y);
    }
    cout << maxn << "\n";
    return;
}
signed main() {
    cin.tie(nullptr) -> sync_with_stdio(false);
    int _ = 1; cin >> _;
    while(_ --) solve();
    return 0;
}