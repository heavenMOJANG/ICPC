#pragma GCC optimize(1)
#pragma GCC optimize(2)
#pragma GCC optimize(3, "Ofast", "inline")
#include <bits/stdc++.h>
#define int long long
using namespace std;
constexpr int INF = 0x7fffffff;
constexpr int MOD = 998244353;
template<class T>
class fenwick {
private:
    int len{};
    vector<T> t;
    int lowbit(int x) { return x & -x; }
public:
    fenwick(int n) : len(n), t(n + 1, T{}) {};
    void update(int x, const T & d) { while (x <= len) (t[x] += d) %= MOD, x += lowbit(x); }
    T query(int x) {
        T res{};
        while (x) (res += t[x]) % MOD, x -= lowbit(x);
        return res;
    }
    T sum(int l, int r) {
        assert(l && l < r);
        return (query(r) - query(l - 1) + MOD) % MOD;
    }
};
void solve() {
    string s; cin >> s;
    int n = s.size(); s = " " + s;
    
    int q; cin >> q;
    while (q --) {

    }
    cout << "\n";
    return;
}
signed main() {
    cin.tie(0) -> sync_with_stdio(0);
    int _ = 1; //cin >> _;
    while(_ --) solve();
    return 0;
}