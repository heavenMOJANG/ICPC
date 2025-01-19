#pragma GCC optimize(1)
#pragma GCC optimize(2)
#pragma GCC optimize(3, "Ofast", "inline")
#include <bits/stdc++.h>
#define int long long
using namespace std;
constexpr int INF = 0x7fffffff;
struct Tree;
Tree* NewNode();

void solve() {
    int n; cin >> n;
    vector<Point> p;
    for (int i = 0; i < n; ++ i) cin >> p[i].x >> p[i].y;
    auto calc = [&](int x0, int y0) {
        int t0{}, t1{}, t2{}, t3{};
        for (int i = 0; i < n; ++ i) {
            t0 += x0 <= p[i].x && y0 <= p[i].y;
            t1 += x0 > p[i].x && y0 <= p[i].y;
            t2 += x0 <= p[i].x && y0 > p[i].y;
            t3 += x0 > p[i].x && y0 > p[i].y;
        }
        return min({t0, t1, t2, t3});
    };
    
    return;
}
signed main() {
    cin.tie(0) -> sync_with_stdio(0);
    int _ = 1; cin >> _;
    while(_ --) solve();
    return 0;
}