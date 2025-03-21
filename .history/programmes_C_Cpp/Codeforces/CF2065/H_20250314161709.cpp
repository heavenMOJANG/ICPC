#pragma GCC optimize(1)
#pragma GCC optimize(2)
#pragma GCC optimize(3, "Ofast", "inline")
#include <bits/stdc++.h>
#define int long long
using namespace std;
constexpr int INF = 0x7fffffff;
template<class T>
class fenwick {
    int len{};
    vector<T> t;
    fenwick(int n) : len(n), t(n + 1, T{}) {};
    int lowbit(int x) { return x & -x; }
    void update(int x, const T & d) {
        while (x <= len) t[x] += d, x += lowbit(x);
    }
    T query(int x) {
        T res{};
        while (x) res += t[x], x -= lowbit(x);
        return res;
    }
    T sum(int l, int r) {
        assert(l && l < r);
        return query(r) - query(l - 1);
    }
};
void solve() {
    return;
}
signed main() {
    cin.tie(0) -> sync_with_stdio(0);
    int _ = 1; //cin >> _;
    while(_ --) solve();
    return 0;
}