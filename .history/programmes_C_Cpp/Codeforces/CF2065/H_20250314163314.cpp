#pragma GCC optimize(1)
#pragma GCC optimize(2)
#pragma GCC optimize(3, "Ofast", "inline")
#include <bits/stdc++.h>
#define int long long
using namespace std;
constexpr int INF = 0x7fffffff;
constexpr int MOD = 998244353;
constexpr int N = 2e5 + 10;
int fac[N];
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
    fenwick<int> t10(n), t11(n), t20(n), t21(n);
    int ans{};
    for (int i = 1; i <= n; ++ i) {
        if (s[i] == '1') {
            (ans += (t10.query(i) + 1) * fac[n - i]) %= MOD;
            t11.update(i, fac[i - 1]);
            t21.update(i, fac[n - i]);
        } else {
            (ans += (t11.query(i) + 1) * fac[n - i]) %= MOD;
            t10.update(i, fac[i - 1]);
            t20.update(i, fac[n - i]);
        }
    }
    int q; cin >> q;
    while (q --) {

    }
    cout << "\n";
    return;
}
signed main() {
    cin.tie(0) -> sync_with_stdio(0);
    fac[0] = 1;
    for (int i = 1; i < N; ++ i) fac[i] = fac[i - 1] * 2 % MOD;
    int _ = 1; //cin >> _;
    while(_ --) solve();
    return 0;
}