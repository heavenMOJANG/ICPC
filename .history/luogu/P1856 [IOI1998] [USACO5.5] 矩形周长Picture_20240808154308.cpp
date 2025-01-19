#pragma GCC optimize(1)
#pragma GCC optimize(2)
#pragma GCC optimize(3,"Ofast","inline")
#include<bits/stdc++.h>
#define int long long
using namespace std;
constexpr int INF = 0x7fffffff;
constexpr int N = 2e5 + 10;
struct Node {
    int l, r, h, syb;
    Node () {}
    Node (int a, int b, int c, int d) : l(a), r(b), h(c), syb(d) {}
}t[N];
int cmp (Node & x, Node & y) {return x.h < y.h;}
int leftOverlapped[N << 2], rightOverlapped[N << 2];
int num[N << 2], tag[N << 2], len[N << 2];
void pushUp(int p, int pl, int pr) {
    if (tag[p]) {
        leftOverlapped[p] = rightOverlapped[p] = 1;
        len[p] = pr - pl + 1;
        num[p] = 1;
    } else if (pl == pr) leftOverlapped[p] = rightOverlapped[0] = len[p] = num[p] = 0;
    else {
        leftOverlapped[p] = leftOverlapped[p << 1];
        rightOverlapped[p] = rightOverlapped[p << 1 | 1];
        len[p] = len[p << 1] + len[p << 1 | 1];
        num[p] = num[p << 1] + num[p << 1 | 1];
        if (leftOverlapped[p] && rightOverlapped[p]) num[p] --;
    }
}
void udpate(int L, int R, int val, int p, int pl, int pr) {
    if (L <= pl && pr <= R) {
        tag[p] += val;
        pushUp(p, pl, pr);
        return;
    }
    int mid = pl + pr >> 1;
    if (L <= mid) udpate(L, R, val, p << 1, pl, mid);
    if (R > mid) update(L, R, val, p << 1 | 1, mid + 1, pr);
    pushUp(p, pl, pr);
}
signed main() {
    cin.tie(0) -> sync_with_stdio(0);
    return 0;
}