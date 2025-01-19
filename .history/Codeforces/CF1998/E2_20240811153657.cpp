#pragma GCC optimize(1)
#pragma GCC optimize(2)
#pragma GCC optimize(3,"Ofast","inline")
#include<bits/stdc++.h>
#define int long long
using namespace std;
constexpr int INF = 0x7fffffff;
struct Info {int maxn = 0;};
Info operator + (const Info & x, const Info & y) {return {max(x.maxn, y.maxn)};}
template<class Info>
struct segmentTree {
    int n;
    vector<Info> info;
    segmentTree() {}
    segmentTree(int n, Info _init = Info()) {
        init(vector<Info>(n, _init));
    }
    segmentTree(const vector<Info> & _init) {
        init(_init());
    }
    void init(const vector<Info> & _init) {
        n = (int)_init.size();
        info.assign((n << 2) + 1, Info());
        function<void(int, int, int)> build() = [&](int p, int pl, int pr) {
            if (pl == pr) {
                info[p] = _init[pl - 1];
                return;
            }
            int mid = pl + pr >> 1;
            build(p << 1, pl, mid);
            build(p << 1 | 1, mid + 1, pr);
            pushUp(p);
        }
        build(1, 1, n);
    }
    void pushUp(int p) {
        info[p] = info[p << 1] + info[p << 1 | 1];
    }
    void modify(int p, int pl, int pr, int x, const Info & v) {
        if (pl == pr) {
            info[p] = v;
            return;
        }
        int mid = pl + pr >> 1;
        if (x <= mid) modify(p << 1, pl, mid, x, v);
        else modify(p << 1 | 1, mid + 1, pr, x, v);
        pushUp(p);
    }

};
void solve() {
}
signed main() {
    cin.tie(0) -> sync_with_stdio(0);
    int _ = 1; //cin >> _;
    while(_ --) solve();
    return 0;
}