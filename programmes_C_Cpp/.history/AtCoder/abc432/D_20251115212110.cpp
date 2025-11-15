#pragma GCC optimize(3, "Ofast", "inline")
#include <bits/stdc++.h>
#define int long long
using namespace std;
constexpr int INF = 0x7fffffff;
struct S { int lx, rx, ly, ry; };
struct DSU {
    vector<int> fa;
    DSU(int n) : fa(n + 1) { iota(fa.begin(), fa.end(), 0ll); }
    int find(int x) { return fa[x] == x ? x : fa[x] = find(fa[x]); }
    void merge(int x, int y) {
        x = find(x); y = find(y);
        if (x != y) fa[y] = x;
    }
};
void solve() {
    int N, X, Y; cin >> N >> X >> Y;
    vector<tuple<char, int, int>> s(N);
    for (auto& [ch, a, b] : s) cin >> ch >> a >> b;
    vector<S> R = { {0ll, X - 1, 0ll, Y - 1} };
    for (auto [ch, A, B] : s) {
        vector<S> nxt;
        int d1 = -B, d2 = B;
        for (auto r : R) {
            auto [xl, xr, yl, yr] = r;
            if (ch == 'X') {
                int al = min(xr, A - 1);
                if (xl <= al) nxt.emplace_back(xl, al, yl + d1, yr + d1);
                int ar = max(xl, A);
                if (ar <= xr) nxt.emplace_back(ar, xr, yl + d2, yr + d2);
            } else {
                int al = min(yr, A - 1);
                if (yl <= al) nxt.emplace_back(xl + d1, xr + d1, yl, al);
                int ar = max(yl, A);
                if (ar <= yr) nxt.emplace_back(xl + d2, xr + d2, ar, yr);
            }
        }
        R = move(nxt);
    }
    int n = R.size();
    DSU dsu(n);
    vector<int> a(n, 0);
    for (int i{}; i < n; ++ i){
        int w = R[i].rx - R[i].lx + 1;
        int h = R[i].ry - R[i].ly + 1;
        if (w && h) a[i] = w * h;
    }
    for (int i{}; i < n; ++ i) if (a[i]){
        for (int j = i + 1; j < n; ++ j) if (a[j]) {
            auto &ra = R[i], &rb = R[j];
            int x1a = ra.lx, x1b = ra.rx, y1a = ra.ly, y1b = ra.ry;
            int x2a = rb.lx, x2b = rb.rx, y2a = rb.ly, y2b = rb.ry;
            int f1 = (x1b + 1 == x2a || x2b + 1 == x1a) && max(y1a, y2a) <= min(y1b, y2b);
            int f2 = (y1b + 1 == y2a || y2b + 1 == y1a) && max(x1a, x2a) <= min(x1b, x2b);
            if (f1 || f2) dsu.merge(i, j);
        }
    }
    map<int, int> mp;
    for (int i{}; i < n; ++ i) if (a[i]) mp[dsu.find(i)] += a[i];
    cout << mp.size() << "\n";
    vector<int> ans;
    for (auto &[k, v]:mp) ans.emplace_back(v);
    sort(ans.begin(), ans.end());
    for (int i{}; i < ans.size(); ++ i) cout << ans[i] << " \n"[i + 1 == ans.size()];
}
signed main() {
    cin.tie(nullptr) -> sync_with_stdio(false);
    int _ = 1; //cin >> _;
    while(_ --) solve();
    return 0;
}