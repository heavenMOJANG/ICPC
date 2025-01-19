#pragma GCC optimize(1)
#pragma GCC optimize(2)
#pragma GCC optimize(3, "Ofast", "inline")
#include <bits/stdc++.h>
#define int long long
using namespace std;
constexpr int INF = 0x7fffffff;
struct Node {
    int x, a;
    bool operator < (const Node & b) const { return x < b.x; }
};
void solve() {
    int n, m; cin >> n >> m;
    vector<Node> a(m);
    for (int i = 0; i < m; ++ i) cin >> a[i].x;
    for (int i = 0; i < m; ++ i) cin >> a[i].a;
    sort(a.begin(), a.end());
    int lst = n, ans{};
    for (int i = m - 1; i >= 0 ; -- i) {
        if (a[i].x == lst) { lst --; continue;}
        int len = lst - a[i].x;
        if (a[i].a <= len) {
            ans += (lst * 2 - 1 - a[i].a) * a[i].a / 2;
            lst -= a[i].a;
        } else {
            lst = a[i].x - 1;
            ans += len * (len + 1) / 2;
        }
    }
    if (lst) { cout << "-1\n"; return; }
    cout << ans << "\n";
    return;
}
signed main() {
    cin.tie(0) -> sync_with_stdio(0);
    int _ = 1; //cin >> _;
    while(_ --) solve();
    return 0;
}