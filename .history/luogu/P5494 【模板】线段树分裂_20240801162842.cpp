#pragma GCC optimize(1)
#pragma GCC optimize(2)
#pragma GCC optimize(3,"Ofast","inline")
#include<bits/stdc++.h>
#define int long long
using namespace std;
constexpr int INF = 0x7fffffff;
constexpr int N = 2e5 + 10;
struct Node {
    int sum, l, r;
}t[N << 5];
int n, m, idx = 1,rt[N << 2], rub[N << 5], cnt, tot;
int _new() {
    return cnt ? rub[cnt --] : ++ tot;
}
void del(int & p) {
    t[p].l = t[p].r = t[p].sum = 0;
    rub[++ cnt] = p;
    p = 0;
}
void pushUp(int p) {
    t[p].sum = t[t[p].l].sum + t[t[p].r].sum;
}
void build(int & p, int pl, int pr) {
    if (!p) p = _new();
    if (pl == pr) {
        cin >> t[p].sum;
        return;
    }
    int mid = pl + pr >> 1;
    build(t[p].l, pl, mid);
    build(t[p].r, mid + 1, pr);
    pushUp(p);
}
void update(int & p, int pl, int pr, int x, int c) {
    if (!p) p = _new();
    if (pl == pr) {
        t[p].sum += c;
        return;
    }
    int mid = pl + pr >> 1;
    if (x <= mid) update(t[p].l, pl, mid, x, c);
    else update(t[p].r, mid + 1, pr, x, c);
    pushUp(p);
}
int merge(int u, int v, int pl, int pr) {
    if (!u || !v) return u + v;
    if (pl == pr) {
        t[u].sum += t[v].sum;
        del(v);
        return u;
    }
    int mid = pl + pr >> 1;
    t[u].l = merge(t[u].l, t[v].l, pl, mid);
    t[u].r = merge(t[u].r, t[v].r, mid + 1, pr);
    pushUp(u);
    del(v);
    return u;
}
signed main() {
    cin.tie(0) -> sync_with_stdio(0);

    return 0;
}