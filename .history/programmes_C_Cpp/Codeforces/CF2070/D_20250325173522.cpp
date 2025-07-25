#pragma GCC optimize(1)
#pragma GCC optimize(2)
#pragma GCC optimize(3, "Ofast", "inline")
#include <bits/stdc++.h>
//#define int long long
using namespace std;
constexpr int INF = 0x7fffffff;
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
    friend modInt operator * (int y, const modInt &a){ return modInt(1LL * y * a.x % mod); }
    friend modInt operator / (int y, const modInt &a){ return modInt(y) / a; }
    friend ostream &operator << (ostream &os, const modInt &a) { return os << a.x; }
    friend istream &operator >> (istream &is, modInt &t){ return is >> t.x; }

    modInt pow (int64_t n) const {
        modInt res(1), mul(x);
        while(n){
            if (n & 1) res *= mul;
            mul *= mul;
            n >>= 1;
        }
        return res;
    }
    
    modInt inv() const {
        int a = x, b = mod, u = 1, v = 0;
        while (b) {
            int t = a / b;
            a -= t * b; swap(a, b);
            u -= t * v; swap(u, v);
        }
        if (u < 0) u += mod;
        return u;
    }
};
using Z = modInt<998244353>;
void solve() {
    int n; cin >> n;
    vector<int> p(n);
    for (int i = 1; i < n; ++ i) cin >> p[i], p[i] --;
    vector<int> d(n);
    vector<vector<int>> L(n);
    L[0].emplace_back(0);
    for (int i = 1; i < n; ++ i) {
        d[i] = d[p[i]] + 1;
        L[d[i]].emplace_back(i);
    }
    vector<Z> ans(n);
    ans[0] = 1;
    for (auto V : L[1]) ans[V] = 1;
    Z lst = L[1].size();
    for (int i = 2; i < L.size(); ++ i) {
        Z res = 0;
        for (auto V : L[i]) {
            ans[V] = lst - ans[p[V]];
            res += ans[V];
        }
        lst = res;
    }
    Z f = 0;
    for (int i = 0; i < n; ++ i) f += ans[i];
    cout << f << "\n";
    return;
}
signed main() {
    cin.tie(0) -> sync_with_stdio(0);
    int _ = 1; cin >> _;
    while(_ --) solve();
    return 0;
}