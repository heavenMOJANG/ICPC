#pragma GCC optimize(1)
#pragma GCC optimize(2)
#pragma GCC optimize(3,"Ofast","inline")
#include<bits/stdc++.h>
#define int long long
using namespace std;
constexpr int INF = 0x7fffffff;
void solve() {
    int n, m; cin >> n >> m;
    vector<int> a(n);
    int maxn = 0;
    for (auto && x : a) cin >> x, maxn = max(x, maxn);
    while (m --) {
        char op; cin >> op;
        int l, r; cin >> l >> r;
        if (l <= maxn && maxn <= r) {
            if (op == '+') maxn ++;
            else maxn --;
        }
        cout << maxn << "\n";
    }
    return;
}
signed main() {
    cin.tie(0) -> sync_with_stdio(0);
    int _ = 1; cin >> _;
    while(_ --) solve();
    return 0;
}