#pragma GCC optimize(1)
#pragma GCC optimize(2)
#pragma GCC optimize(3,"Ofast","inline")
#include<bits/stdc++.h>
#define int long long
//using namespace std;
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
    int sumax = 0, sumay = 0, cnta = 0;
    for (int i = 0; i < n; ++ i) {
        sumax += a[i].a, sumay += a[i].b;
        cnta ++;
        if (sumax > x || sumay >= y) break;
    }
    sort(a.begin(), a.end(), [](const Node & x, const Node & y) {return x.b > y.b;});
    int sumbx = 0, sumby = 0, cntb = 0;
    for (int i = 0; i < n; ++ i) {
        sumbx += a[i].a, sumby += a[i].b;
        cntb ++;
        if (sumbx > x || sumby > y) break;
    }
    cout << cnta << " " << cntb << "\n";
}
signed main() {
    cin.tie(0) -> sync_with_stdio(0);
    int _ = 1; //cin >> _;
    while(_ --) solve();
    return 0;
}