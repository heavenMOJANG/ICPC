#pragma GCC optimize(1)
#pragma GCC optimize(2)
#pragma GCC optimize(3, "Ofast", "inline")
#include <bits/stdc++.h>
#define int long long
using namespace std;
constexpr int INF = 0x7fffffff;
constexpr int N = 5e5 + 10;
template <class T>
struct fenwickTree {
    int n;
    vector<T> a;
    fenwickTree (int m) : n(m), a(m + 1, 0) {}
    int lowbit(int x) { return x & -x; }
    void update(int x, T y) {x ++; while (x <= n) a[x] += y, x += lowbit(x); }
    T query(int x) { T res{}; while (x) res += a[x], x -= lowbit(x); return res; }
    T query(int x, int y) { return query(y) - query(x); }
    int lower_bound(T x) {
        int l{}, r = N;
        while (l + 1 < r) {
            int mid = l + r >> 1;
            if (query(0, mid) >= x) r = mid;
            else l = mid;
        }
        return l;
    }
};
void solve() {
    int n; cin >> n;
    fenwickTree<int> ft(N);
    for (int i = 1; i < N; ++ i) ft.update(i, 1);
    for (int i = 0; i < n; ++ i) {
        int l, r; cin >> l >> r;
        int idl = ft.lower_bound(l);
        if (ft.query(0, N) > r + 1) {
            int idr = ft.lower_bound(r + 1);
            ft.update(idl, 1);
            ft.update(idr, -1);
        } else ft.update(idl, 1);
    }
    int q; cin >> q;
    while (q --) {
        int x; cin >> x;
        cout << ft.query(0, x + 1) << "\n";
    }
    return;
}
signed main() {
    cin.tie(0) -> sync_with_stdio(0);
    int _ = 1; //cin >> _;
    while(_ --) solve();
    return 0;
}