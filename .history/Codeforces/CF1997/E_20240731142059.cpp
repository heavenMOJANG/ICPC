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
        t[u].info = init[r - 1];
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
        if (!f(pre + t[p].info)) {
            pre += t[p].info;
            return r + 1;
        }
        if (l == r) return r;
        int mid = l + r >> 1, res;
        if (f(pre + t[t[p].l].info)) res = queryFirst(t[p].l, l, mid, L, R, f, pre);
        else {
            pre += t[t[p].l].info;
            res = queryFirst(t[p].r, mid + 1, r, L, R, f, pre);
        }
        return res;
    }
    int mid = l + r >> 1, res = mid + 1;
    if (L <= mid) res = queryFirst(t[p].l, l, mid, L, R, f, pre);
    if (R > mid && res == mid + 1) res = queryFirst(t[p].r, mid + 1, r, L, R, f, pre);
    return res;
}
signed main() {
    cin.tie(0) -> sync_with_stdio(0);
    cin >> n >> q;
    vector<vector<int>> pos(N);
    vector<int> a(n + 1);
    int NN = 2e5;
    for (int i = 1; i <= n; ++ i) cin >> a[i], pos[a[i]].emplace_back(i);
    for (int i = 1; i <= NN; ++ i) {
        rt[i] = rt[i - 1];
        for (auto x : pos[NN - i + 1]) modify(rt[i], rt[i], 1, n, x, 1);
    }
    vector<int> ans(q);
    vector<vector<pair<int, int>>> query(n + 1);
    for (int i = 0, x, y; i < q; ++ i) {
        cin >> x >> y;
        query[y].emplace_back(make_pair(x, i));
    }
    for (int k = 1; k <= n; ++ k) {
        if (query[k].empty()) continue;
        auto f = [&](const int & info) {
            return info >= k;
        };
        sort(query[k].begin(), query[k].end());
        int l = 0, j = - 1, cnt = -1;
        while (l < n) {
            int pre = 0;
            int pos = queryFirst(rt[NN - cnt + 1], l, n, l + 1, n, f, pre);
            while (j + 1 < query[k].size() && query[k][j + 1].first <= pos) {
                auto [x, id] = query[k][++ j];
                ans[id] = (a[x] >= cnt);
            }
            cnt ++;
            l = pos;
        }
    }
    for (auto x : ans) cout << (x ? "YES\n" : "NO\n");
    return 0;
}