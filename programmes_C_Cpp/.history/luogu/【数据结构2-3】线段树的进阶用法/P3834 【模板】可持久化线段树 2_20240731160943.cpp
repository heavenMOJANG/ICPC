#pragma GCC optimize(1)
#pragma GCC optimize(2)
#pragma GCC optimize(3,"Ofast","inline")
#include<bits/stdc++.h>
#define int long long
using namespace std;
constexpr int inf = 0x7fffffff;
constexpr int N = 2e5 + 10;
struct Node {int l, r, sum;}t[N << 5];
int n, m, a[N], b[N], rt[N], idx;
int modify(int & u, int pre, int l, int r, int x) {
    u = ++ idx;
    t[u].l = t[pre].l;
    t[u].r = t[pre].r;
    t[u].sum = t[pre].sum + 1;
    int mid = l + r >> 1;
    if (l < r) {
        if (x <= mid) modify(t[u].l, t[u].l, l, mid, x);
        else modify(t[u].r, t[u].r, mid + 1, r, x);
    }
}
int query(int L, int R, int l, int r, int k) {
    if (l == r) return l;
    int x = t[t[R].l].sum - t[t[L].l].sum;
    int mid = l + r >> 1;
    if (x >= k) return query(t[L].l, t[R].l, l, mid, k);
    else return query(t[l].r, t[R].r, mid + 1, r, k - x);
}
signed main() {
    cin.tie(0) -> sync_with_stdio(0);
    cin >> n >> m;
    for (int i = 1; i <= n; ++ i) cin >> a[i], b[i] = a[i];
    sort(b + 1, b + 1 + n);
    int siz = unique(b + 1, b + 1 + n) - b - 1;
    for (int i = 1; i <= n; ++ i) {
        int p = lower_bound(b + 1, b + 1 + siz, a[i]) - b;
        modify(rt[i], rt[i - 1], 1, siz, p);
    }
    return 0;
}