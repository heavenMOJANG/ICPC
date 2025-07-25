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
    void apply(int p, int val) {
        Node[p].first += val;
        tag[p] = val;
    }
    void pushDown(int p) {
        if (tag[p]) {
            apply(p << 1, tag[p]);
            apply(p << 1 | 1, tag[p]);
            tag[p] = 0;
        }
    }
public:
    void build(int p, int pl, int pr) {
        Node[p] = {0, pr - pl + 1};
        tag[p] = 0;
        if (pl == pr) return;
        int mid = pl + pr  >> 1;
        build(p << 1, pl, mid);
        build(p << 1 | 1, mid + 1, pr);
    }
    void modify(int L, int R, int p, int pl, int pr, int val) {
        if (L <= pl && pr <= R) return apply(p, val);
        pushDown(p);
        int mid = pl + pr >> 1;
        if (L <= mid) modify(L, R, p << 1, pl, mid, val);
        if (R > mid) modify(L, R, p << 1 | 1, mid + 1, pr, val);
        Node[p] = Node[p << 1] + Node[p << 1 | 1];
    }
    pair<int, int> query(int L, int R, int p, int pl, int pr) {
        if (L <= pl && pr <= R) return Node[p];
        pushDown(p);
        int mid = pl + pr >> 1;
        if (L <= mid) return query(L, R, p << 1, pl, mid);
        if (R > mid) return query(L, R, p << 1 | 1, mid + 1, pr);
        return query(L, R, p << 1, pl, mid) + query(L, R, p << 1 | 1, mid + 1, pr);
    }
}SEG;
void solve() {

}
signed main() {
    cin.tie(0) -> sync_with_stdio(0);
    int _ = 1; //cin >> _;
    while(_ --) solve();
    return 0;
}