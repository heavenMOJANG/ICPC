#pragma GCC optimize(1)
#pragma GCC optimize(2)
#pragma GCC optimize(3,"Ofast","inline")
#include<bits/stdc++.h>
#define int long long
using namespace std;
constexpr int inf = 0x7fffffff;
struct Node {
    int a, b;
};
void solve() {
    int n, x, y; cin >> n >> x >> y;
    vector<Node> a(n);
    for (int i = 0; i < n; ++ i) cin >> a[i].a;
    for (int i = 0; i < n; ++ i) cin >> a[i].b;
    sort(a.begin(), a.end(), [](const Node & x, const Node & y) {return x.a > y.a;});
    int cnt0 = 0, cnt1 = 0;
    for (int i = 0; i < n; ++ i)

}
signed main() {
    cin.tie(0) -> sync_with_stdio(0);
    int _ = 1; //cin >> _;
    while(_ --) solve();
    return 0;
}