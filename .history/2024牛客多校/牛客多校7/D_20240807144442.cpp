#pragma GCC optimize(1)
#pragma GCC optimize(2)
#pragma GCC optimize(3,"Ofast","inline")
#include<bits/stdc++.h>
#define int long long
using namespace std;
constexpr int INF = 0x7fffffff;
constexpr int N = 2e5 +10;
pair<int, int> operator + (const pair<int, int> & x, const pair<int, int> & y) {
    if (x.first > y.first) return x;
    if (x.first < y.first) return y;
    return {x.first, x.second + y.second};
}
class segmentTree {
private:
    pair<int, int> Node[N << 2];
    int tag[N << 2];
    void apply(int p, int d) {
        Node[p].first += d;
        tag[p] = d;
    }
    void pushDown(int p) {
        if (tag[p]) [
            apply(p << 1, tag[p]);
            apply(p << 1 | 1, tag[p]);
        ]
    }
}
signed main() {
    cin.tie(0) -> sync_with_stdio(0);
    int _ = 1; //cin >> _;
    while(_ --) solve();
    return 0;
}