#pragma GCC optimize(1)
#pragma GCC optimize(2)
#pragma GCC optimize(3,"Ofast","inline")
#include<bits/stdc++.h>
#define int long long
using namespace std;
constexpr int inf = 0x7fffffff;
constexpr int N = 2e5 + 10;
struct Node {int l, r, c;};
void solve() {
    int n, q; cin >> n >> q;
    vector<int> f(n + 1);
    for (int i = 1; i <= n; ++ i) f[i] = i;
    vector<Node> a(q);
    for (int i = 0; i < q; ++ i) cin >> a[i].l >> a[i].r >> a[i].c;
    sort(a.begin(), a.end(), [](const Node & x, const Node & y) {
        return x.c < y.c;
    });
    function<int(int)> find = [&](int x) {
        return f[x] == x ? f[x] : f[x] = find(f[x]);
    };
    int cnt = n, ans = 0;
    for (int i = 0; i < q; ++ i) {
        ans += a[i].c;
        for (int j = find(a[i].l) + 1; j <= a[i].r; j = find(j) + 1) {
            f[j - 1] = j;
            cnt --;
            ans += a[i].c;
        }
    }
    cout << (cnt == 1 ? ans : -1ll) << "\n";
    return;
}
signed main() {
    cin.tie(0) -> sync_with_stdio(0);
    int _ = 1; //cin >> _;
    while(_ --) solve();
    return 0;
}