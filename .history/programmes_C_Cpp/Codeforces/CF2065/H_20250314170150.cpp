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
    void update(int x, const T & d) { while (x <= len) (t[x] += d + MOD) %= MOD, x += lowbit(x); }
    T query(int x) {
        T res{};
        while (x) (res += t[x]) % MOD, x -= lowbit(x);
        return res;
    }
    T sum(int l, int r) { return (query(r) - query(l - 1) + MOD) % MOD; }
};
void solve() {
    string s; cin >> s;
    int n = s.size(); s = " " + s;
    fenwick<int> t10(n), t11(n), t20(n), t21(n);
    int ans{};
    for (int i = 1; i <= n; ++ i)
        if (s[i] == '1') {
            (ans += (t10.query(i) + 1) * fac[n - i]) %= MOD;
            t11.update(i, fac[i - 1]);
            t21.update(i, fac[n - i]);
        } else {
            (ans += (t11.query(i) + 1) * fac[n - i]) %= MOD;
            t10.update(i, fac[i - 1]);
            t20.update(i, fac[n - i]);
        }
    auto get0 = [&](int x) {
        if (s[x] == '1') return (t10.query(x) + 1) * fac[n - x] % MOD;
        else return (t11.query(x) + 1) * fac[n - x] % MOD;
    };
    auto get1 = [&](int x) {
        if (s[x] == '1') return t20.sum(x, n) * fac[x - 1] % MOD;
        else return t21.sum(x, n) * fac[x - 1] % MOD;
    };
    int q; cin >> q;
    while (q --) {
        int p; cin >> p;
        ans = (ans - get0(p) + MOD) % MOD;
        ans = (ans - get1(p) + MOD) % MOD;
        if (s[p] == '1') {
            t11.update(p, -fac[p - 1]);
            t21.update(p, -fac[n - p]);
        } else {
            t10.update(p, -fac[p - 1]);
            t20.update(p, -fac[n - p]);
        }
        s[p] ^= 1;
        if (s[p] == '1') {
            t11.update(p, fac[p - 1]);
            t21.update(p, fac[n - p]);
        } else {
            t10.update(p, fac[p - 1]);
            t20.update(p, fac[n - p]);
        }
        (ans += get0(p) + get1(p)) %= MOD;
        cout << ans << " ";
    }
    cout << "\n";
    return;
}
signed main() {
    cin.tie(0) -> sync_with_stdio(0);
    fac[0] = 1;
    for (int i = 1; i < N; ++ i) fac[i] = fac[i - 1] * 2 % MOD;
    int _ = 1; cin >> _;
    while(_ --) solve();
    return 0;
}