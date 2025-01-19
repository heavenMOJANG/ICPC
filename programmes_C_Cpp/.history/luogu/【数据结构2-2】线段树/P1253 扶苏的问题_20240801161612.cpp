#pragma GCC optimize(1)
#pragma GCC optimize(2)
#pragma GCC optimize(3,"Ofast","inline")
#include<bits/stdc++.h>
#define int long long
using namespace std;
constexpr int INF = LLONG_MIN;
constexpr int N = 1e6 + 10;
struct Node {
    int tagChange = INF, tagAdd, maxn;
}t[N << 2];
int n, m, a[N];
void build(int p, int pl, int pr) {
    t[p].tagChange = INF, t[p].tagAdd = 0;
    if (pl == pr) {
        t[p].maxn = a[pl];
        return;
    }
    int mid = pl + pr >> 1;
    build(p << 1, pl, mid);
    build(p << 1 | 1, mid + 1, pr);
    t[p].maxn = max(t[p << 1].maxn, t[p << 1 | 1].maxn);
}
void pushDown(int p) {
    if (t[p].tagChange != INF) {
        t[p << 1].maxn = t[p << 1 | 1].maxn = t[p << 1].tagChange = t[p << 1 | 1].tagChange = t[p].tagChange;
        t[p << 1].tagAdd = t[p << 1 | 1].tagAdd = 0;
        t[p].tagChange = INF;
    }
    if (t[p].tagAdd) {
        t[p << 1].maxn += t[p].tagAdd, t[p << 1 | 1].maxn += t[p].tagAdd;
        t[p << 1].tagAdd += t[p].tagAdd, t[p << 1 | 1].tagAdd += t[p].tagAdd;
        t[p].tagAdd = 0;
    }
}
void modifyChange(int L, int R, int p, int pl, int pr, int x) {
    if (L <= pl && pr <= R) {
        t[p].tagChange = x;
        t[p].tagAdd = 0;
        t[p].maxn = x;
        return;
    }
    pushDown(p);
    int mid = pl + pr >> 1;
    if (L <= mid) modifyChange(L, R, p << 1, pl, mid, x);
    if (R > mid) modifyChange(L, R, p << 1 | 1, mid + 1, pr, x); 
    t[p].maxn = max(t[p << 1].maxn, t[p << 1 | 1].maxn);
}
void modifyAdd(int L, int R, int p, int pl, int pr, int x) {
    if (L <= pl && pr <= R) {
        t[p].tagAdd += x;
        t[p].maxn += x;
        return;
    }
    pushDown(p);
    int mid = pl + pr >> 1;
    if (L <= mid) modifyAdd(L, R, p << 1, pl, mid, x);
    if (R > mid) modifyAdd(L, R, p << 1 | 1, mid + 1, pr, x); 
    t[p].maxn = max(t[p << 1].maxn, t[p << 1 | 1].maxn);
}
int query(int L, int R, int p, int pl, int pr) {
    if (L <= pl && pr <= R) return t[p].maxn;
    pushDown(p);
    int mid = pl + pr >> 1, res = INF;
    if (L <= mid) res = max(res, query(L, R, p << 1, pl, mid));
    if (R > mid) res = max(res, query(L, R, p << 1 | 1, mid + 1, pr));
    return res;
}
signed main() {
    cin.tie(0) -> sync_with_stdio(0);
    cin >> n >> m;
    for (int i = 1; i <= n; ++ i) cin >> a[i];
    build(1, 1, n);
    while (m --) {
        int op, l, r, x; cin >> op >> l >> r;
        switch (op) {
            case 1 :
                cin >> x; 
                modifyChange(l, r, 1, 1, n, x);
                break;
            case 2 :
                cin >> x;
                modifyAdd(l, r, 1, 1, n, x);
                break;
            case 3 :
                cout << query(l, r, 1, 1, n) << "\n";
                break;
        }
    }
    return 0;
}