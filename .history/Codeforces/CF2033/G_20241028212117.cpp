#pragma GCC optimize(1)
#pragma GCC optimize(2)
#pragma GCC optimize(3,"Ofast","inline")
#include <bits/stdc++.h>
#define int long long
using namespace std;
constexpr int INF = 0x7fffffff;
template <class Info, class Tag>
struct SegmentTree {
    const int n;
    vector<Info> info;
    vector<Tag> tag;
    SegmentTree(int n) : n(n), info(4 << __lg(n)), tag(4 << __lg(n)) {}
    SegmentTree(vector<Info> init) : SegmentTree(init.size()) {
        function<void(int, int, int)> build = [&](int p, int pl, int pr) {
            if (pr - pl == 1) {info[p] = init[pl]; return;}
            int mid = pl + pr >> 1;
            build(p << 1, pl, mid);
            build(p << 1 | 1, mid + 1, pr);
            pushUp(p);
        };
        build(1, 0, n);
    }
    void pushUp(int p) {info[p] = info[p << 1] + info[p << 1 | 1];}
    void apply(int p, const Tag & v) {
        info[p].apply(v);
        tag[p].apply(v);
    }
    void pushDown(int p) {
        apply(p << 1, tag[p]);
        apply(p << 1 | 1, tag[p]);
        tag[p] = Tag();
    }
    void modify(int p, int pl, int pr, int x, const Info & v) {
        if (pr - pl == 1) {info[p] = v; return;}
        int mid = pl + pr >> 1;
        pushDown(p);
        if (x < mid) modify(p << 1, pl, mid, x, v);
        else modify(p << 1 | 1, mid + 1, pr, x, v);
        pushUp(p);
    }
    void modify(int p, const Info & v) {modify(1, 0, n, p, v);}
    Info rangeQuery(int p, int pl, int pr, int L, int R) {
        if (pl >= R || pr <= L) return Info();
        if (L <= pl && pr <= R) return info[p];
        int mid = pl + pr >> 1;
        pushDown(p);
        return rangeQuery(p << 1, pl, mid, L, R) + rangeQuery(p << 1 | 1, mid + 1, pr, L, R);
    }
    Info rangeQuery(int L, int R) {return rangeQuery(1, 0, n, L, R);}

};
struct Tag {
    int change = -INF;
    void apply(Tag t) {change = t.change;}
};
struct Info {
    int maxn = -INF;
    void apply(Tag t) {if (t.change != -INF) maxn = t.change;}
    Info() {};
    Info(int x) : maxn(x) {}
};
Info operator + (Info a, Info b) {
    Info c;
    c.maxn = max(a.maxn, b.maxn);
    return c;
}
struct Query {
    int k, id;
    Query (int _k, int _id) : k(_k), id(_id) {}
};
void solve() {
    int n; cin >> n;
    vector<int> g[n + 1];
    for (int i = 1; i < n; ++ i) {
        int u, v; cin >> u >> v;
        g[u].emplace_back(v);
        g[v].emplace_back(u);
    }
    vector<int> dep(n + 1, 0), maxDep(n + 1, 0);
    function<void(int, int)> dfs1 = [&](int u, int fa) {
        maxDep[u] = 0;
        for (auto v : g[u]) {
            if (v == fa) continue;
            dep[v] = dep[u] + 1;
            dfs1(v, u);
            maxDep[u] = max(maxDep[u], maxDep[v] + 1);
        }
    };
    dfs1(1, 0);
    int m; cin >> m;
    vector<vector<Query>> querys(n + 1);
    vector<int> ans(m);
    for (int i = 0; i < m; ++ i) {
        int v, k; cin >> v >> k;
        querys[i].emplace_back(k, i);
    }
    SegmentTree<Info, Tag> seg(n);
    function<void(int, int)> dfs2 = [&](int u, int fa) {
        for (auto & [k, id] : querys[u]) {
            ans[id] = max(ans[id], maxDep[u]);
            ans[id] = max(ans[id], seg.rangeQuery(0, dep[u] - k).maxn + dep[u]);
        }
        int max1{}, max2{};
        for (auto v : g[u]) {
            if (v == fa) continue;
            if (maxDep[v] + 1 > max1) {
                max2 = max1;
                max1 = maxDep[v] + 1;
            } else if (maxDep[v] + 1 > max2) 
                max2 = maxDep[v] + 1;
        }
        for (auto v : g[u]) {
            if (v == fa) continue;
            int d = maxDep[v] + 1 == max1 ? max2 : max1;
            seg.modify(dep[u], Info(d - dep[u]));
            dfs2(v, u);
            seg.modify(dep[u], -INF);
        }
    };
    dfs2(1, 0);
    for (int i = 0; i < m; ++ i) cout << ans[i] << " \n"[i == m - 1];
    return;
}
signed main() {
    cin.tie(0) -> sync_with_stdio(0);
    int _ = 1; //cin >> _;
    while(_ --) solve();
    return 0;
}