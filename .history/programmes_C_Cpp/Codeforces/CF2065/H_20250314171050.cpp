#pragma GCC optimize(1)
#pragma GCC optimize(2)
#pragma GCC optimize(3, "Ofast", "inline")
#include <bits/stdc++.h>
//#define int long long
using namespace std;
constexpr int INF = 0x7fffffff;
constexpr int MOD = 998244353;
constexpr int N = 2e5 + 10;
template<const int T>
struct modInt {
    const static int mod = T;
    int x;
    modInt(int x = 0) : x(x % mod) {}
    modInt(long long x) : x(int(x % mod)) {} 
    int val() { return x; }
    modInt operator + (const modInt &a) const { int x0 = x + a.x; return modInt(x0 < mod ? x0 : x0 - mod); }
    modInt operator - (const modInt &a) const { int x0 = x - a.x; return modInt(x0 < 0 ? x0 + mod : x0); }
    modInt operator * (const modInt &a) const { return modInt(1LL * x * a.x % mod); }
    modInt operator / (const modInt &a) const { return *this * a.inv(); }
    bool operator == (const modInt &a) const { return x == a.x; };
    bool operator != (const modInt &a) const { return x != a.x; };
    void operator += (const modInt &a) { x += a.x; if (x >= mod) x -= mod; }
    void operator -= (const modInt &a) { x -= a.x; if (x < 0) x += mod; }
    void operator *= (const modInt &a) { x = 1LL * x * a.x % mod; }
    void operator /= (const modInt &a) { *this = *this / a; }
    friend modInt operator + (int y, const modInt &a){ int x0 = y + a.x; return modInt(x0 < mod ? x0 : x0 - mod); }
    friend modInt operator - (int y, const modInt &a){ int x0 = y - a.x; return modInt(x0 < 0 ? x0 + mod : x0); }
    friend modInt operator * (int y, const modInt &a){ return modInt(1LL * y * a.x % mod);}
    friend modInt operator / (int y, const modInt &a){ return modInt(y) / a;}
    friend ostream &operator<<(ostream &os, const modInt &a) { return os << a.x;}
    friend istream &operator>>(istream &is, modInt &t){return is >> t.x;}
};
using mint = modInt<MOD>;
mint fac[N];
template<class T>
class fenwick {
private:
    int len{};
    vector<T> t;
    int lowbit(int x) { return x & -x; }
public:
    fenwick(int n) : len(n), t(n + 1, T{}) {};
    void update(int x, const T & d) { while (x <= len) t[x] += d, x += lowbit(x); }
    T query(int x) {
        T res{};
        while (x) res += t[x], x -= lowbit(x);
        return res;
    }
    T sum(int l, int r) { return query(r) - query(l - 1); }
};
void solve() {
    string s; cin >> s;
    int n = s.size(); s = " " + s;
    fenwick<mint> t10(n), t11(n), t20(n), t21(n);
    mint ans{};
    for (int i = 1; i <= n; ++ i)
        if (s[i] == '1') {
            ans += (t10.query(i) + 1) * fac[n - i];
            t11.update(i, fac[i - 1]);
            t21.update(i, fac[n - i]);
        } else {
            ans += (t11.query(i) + 1) * fac[n - i];
            t10.update(i, fac[i - 1]);
            t20.update(i, fac[n - i]);
        }
    auto get0 = [&](int x) -> mint {
        if (s[x] == '1') return (t10.query(x) + 1) * fac[n - x];
        else return (t11.query(x) + 1) * fac[n - x];
    };
    function<mint(int)> get1 = [&](int x) -> mint {
        if (s[x] == '1') return t20.sum(x, n) * fac[x - 1];
        else return t21.sum(x, n) * fac[x - 1];
    };
    int q; cin >> q;
    while (q --) {
        int p; cin >> p;
        ans -= get0(p);
        ans -= get1(p);
        if (s[p] == '1') {
            t11.update(p, -1 * fac[p - 1]);
            t21.update(p, -1 * fac[n - p]);
        } else {
            t10.update(p, -1 * fac[p - 1]);
            t20.update(p, -1 * fac[n - p]);
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
    for (int i = 1; i < N; ++ i) fac[i] = fac[i - 1] * 2;
    int _ = 1; cin >> _;
    while(_ --) solve();
    return 0;
}