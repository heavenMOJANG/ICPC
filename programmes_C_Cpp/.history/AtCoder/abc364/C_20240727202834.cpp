#pragma GCC optimize(1)
#pragma GCC optimize(2)
#pragma GCC optimize(3,"Ofast","inline")
#include<bits/stdc++.h>
#define int long long
using namespace std;
constexpr int inf = 0x7fffffff;
struct Node {
    int a, b;
    bool operator < (const Node & x) const { return a + b < x.a + x.b;}
};
void solve() {
    int n, x, y; cin >> n >> x >> y;
    vector<Node> a(n);
    for (int i = 0; i < n; ++ i) cin >> a[i].a;
    for (int i = 0; i < n; ++ i) cin >> a[i].b;
}
signed main() {
    cin.tie(0) -> sync_with_stdio(0);
    int _ = 1; //cin >> _;
    while(_ --) solve();
    return 0;
}