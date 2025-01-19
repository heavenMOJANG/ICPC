#pragma GCC optimize(1)
#pragma GCC optimize(2)
#pragma GCC optimize(3, "Ofast", "inline")
#include <bits/stdc++.h>
#define int long long
using namespace std;
constexpr int INF = 0x7fffffff;
template<class T>
class FenwickTree {
private:
    int n;
    vector<T> data;
public:
    FenwickTree() : FenwickTree(0) {}
    explicit FenwickTree(int n) : n(n), data(n) {}
    int lowbit(int x) { return x & -x;}
    void add(int p, T x) {
        assert(0 <= p and p < n);
        p += 1;
        while (p <= n) {
            data[p - 1] += x;
            p += lowbit(p);
        }
    }
    T sum(int l, int r) {
        assert(0 <= l and l <= r and r <= n);
        return sum(r) - sum(l);
    }
    T sum(int r) {// return sum of [0, r)
        assert(0 <= r and r <= n);
        T s = 0;
        while (r > 0) {
            s += data[r - 1];
            r -= lowbit(r);
        }
        return s;
    }
};
void solve() {
    int n, q; cin >> n >> q;
    vector<int> a(n);
    vector<pair<int, int>> query[n];
    for (int i = 0; i < n; ++ i) cin >> a[i];
    for (int i = 0; i < n; ++ i) {
        int l, r; cin >> l >> r;
        l --, r --;
        query[l].emplace_back(r, i);
    }
    FenwickTree<int> ft(n);
    vector<int> ans(q, 0), st;
    int top = -1;
    for (int l = n - 1; l >= 0; -- l) {
        for (auto [r, i] : query[l]) ans[i] = ft.sum(r + 1, n);
        while (top >= 0 && a[st[top]] < a[l]) ft.add(st[top --], -1);
        st.
    }
    return;
}
signed main() {
    cin.tie(0) -> sync_with_stdio(0);
    int _ = 1; //cin >> _;
    while(_ --) solve();
    return 0;
}