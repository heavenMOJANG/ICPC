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
        if (leftOverlapped[p << 1 | 1] && rightOverlapped[p << 1]) num[p] --;
    }
}
void update(int L, int R, int val, int p, int pl, int pr) {
    if (L <= pl && pr <= R) {
        tag[p] += val;
        pushUp(p, pl, pr);
        return;
    }
    int mid = pl + pr >> 1;
    if (L <= mid) update(L, R, val, p << 1, pl, mid);
    if (R > mid) update(L, R, val, p << 1 | 1, mid + 1, pr);
    pushUp(p, pl, pr);
}
signed main() {
    cin.tie(0) -> sync_with_stdio(0);
    int n; cin >> n;
    int cnt = 0;
    int lbd = 1e4, rbd = -1e4;
    for (int i = 0; i < n; ++ i) {
        int x1, y1, x2, y2; cin >> x1 >> y1 >> x2 >> y2;
        lbd = min(lbd, x1);
        rbd = max(rbd, x2);
        t[++ cnt] = Node(x1, x2, y1, 1);
        t[++ cnt] = Node(x1, x2, y2, -1);
    }
    sort(t + 1, t + 1 + cnt, cmp);
    int ans = 0, lst = 0;
    for (int i = 1; i <= cnt; ++ i) {
        if (t[i].l < t[i].r) update(t[i].l, t[i].r - 1, t[i].syb, 1, lbd, rbd - 1);
        ans += num[1] * 2 * (t[i + 1].h - t[i].h);
        ans += abs(len[1] - lst);
        lst = len[1];
    }
    cout << ans << "\n";
    return 0;
}