#pragma GCC optimize(1)
#pragma GCC optimize(2)
#pragma GCC optimize(3, "Ofast", "inline")
#include <bits/stdc++.h>
#define int long long
using namespace std;
constexpr int INF = 0x7fffffff;
template<class T>
class FenwickTree {
private: // fenwickTree for interval [0, n)
    int n;
    vector<T> data;
public:
    FenwickTree() : FenwickTree(0) {}
    explicit FenwickTree(int n) : n(n), data(n) {}

    void add(int p, T x) {
        assert(0 <= p and p < n);
        p += 1;
        while (p <= n) {
            data[p - 1] += x;
            p += p & -p;
        }
    }

    T sum(int l, int r) {// return sum of [l, r)
        assert(0 <= l and l <= r and r <= n);
        return sum(r) - sum(l);
    }

    T sum(int r) {// return sum of [0, r)
        assert(0 <= r and r <= n);
        T s = 0;
        while (r > 0) {
            s += data[r - 1];
            r -= r & -r;
        }
        return s;
    }
};
void solve() {
    int n, q; cin >> n >> q;
    vector<int> a(n + 1);
    for (int i = 1; i <= n; ++ i) cin >> a[i];
    while (q --) {
        int l, r; cin >> l >> r;

    }
    return;
}
signed main() {
    cin.tie(0) -> sync_with_stdio(0);
    int _ = 1; //cin >> _;
    while(_ --) solve();
    return 0;
}