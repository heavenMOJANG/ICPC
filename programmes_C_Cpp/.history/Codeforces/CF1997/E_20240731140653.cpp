#pragma GCC optimize(1)
#pragma GCC optimize(2)
#pragma GCC optimize(3,"Ofast","inline")
#include<bits/stdc++.h>
#define int long long
using namespace std;
constexpr int inf = 0x7fffffff;
constexpr int N = 2e5 + 10;
struct Node {
    int info, l, r;
}t[N * 64];
int n, q, rt[N], idx;
void build(int & u, int l, int r, const vector<int> & init) {
    if (!u) u = ++ idx;
    if (l == r) {
        t[u].info = init[r -  1];
        return;
    }
    int mid = l + r >> 1;
    build(t[u].l, l, mid, init);
    build(t[u].r, mid + 1, r, init);
    t[u].info = t[t[u].l].info + t[t[u].r].info;
}
void modify(int & cur, int pre, int l, int r, int x, const int & v) {
    t[cur = ++ idx] = t[pre];
    if (l == r) {
        t[cur].info = v;
        return;
    }
    int mid = l + r >> 1;
    if (x <= mid) modify(t[cur].l, t[pre].l, l, mid, x, v);
    else modify(t[cur].r, t[pre].r, mid + 1, r, x, v);
    t[cur].info = t[t[cur].l].info + t[t[cur].r].info;
}
int queryFirst(int p, int l, int r, int L, int R, const function<int(const int &)> & f, int & pre) {
    if (l > R || r < L) 
        return r + 1;
    if (L <= l && r <= R) {
        if (!f(pre + t[p].info))
    }
}
signed main() {
    cin.tie(0) -> sync_with_stdio(0);
    cin >> n >> q;

    return 0;
}