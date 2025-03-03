#pragma GCC optimize(1)
#pragma GCC optimize(2)
#pragma GCC optimize(3, "Ofast", "inline")
#include <bits/stdc++.h>
//#define int long long
using namespace std;
constexpr int INF = 0x7fffffff;
constexpr int MOD = 1e9 + 7;
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
};
using mint = modInt<MOD>;
void solve() {
    int n, q; cin >> n >> q;
    vector<int> a(n + 1), b(n + 1);
    for (int i = 1; i <= n; ++ i) cin >> a[i];
    for (int i = 1; i <= n; ++ i) cin >> b[i];
    vector prea(30, vector<mint> (n + 1, 0));
    vector preb = prea;
    for (int i = 1; i <= n; ++ i) {
        for (int j = 0; j < 30; ++ j) {
            if ((1ll << j) & a[i]) prea[j][i] = 1;
            if ((1ll << j) & b[i]) preb[j][i] = 1;
            prea[j][i] += prea[j][i - 1];
            preb[j][i] += preb[j][i - 1];
        }
    }
    vector<mint> f(n + 1, 0);
    for (int i = 1; i <= n; ++ i) {
        for (int j = 0; j < 30; ++ j) {
            if ((1ll << j) & a[i]) f[i] += (n - i + 1 - preb[j][n] + preb[j][i - 1]) * (1ll << j);
            else f[i] += (preb[j][n] - preb[j][i - 1]) * (1ll << j);
        }
    }
    for (int i = 1; i <= n; ++ i) f[i] += f[i - 1];
    while (q --) {
        int l, r; cin >> l >> r;
        mint ans = f[r] - f[l - 1];
        for (int i = 0; i < 30; ++ i) {
            mint a1 = prea[i][r] - prea[i][l - 1], a0 = r - l + 1 - a1;
            mint b1 = preb[i][n] - preb[i][r], b0 = n - r - b1;
            ans -= (a1 * b0 + a0 * b1) * (1ll << i);
        }
        cout << ans << "\n";
    }
    return;
}
signed main() {
    cin.tie(0) -> sync_with_stdio(0);
    //freopen("2.in", "r", stdin);
    //freopen("2.out", "w", stdout);
    int _ = 1; cin >> _;
    while(_ --) solve();
    //fclose(stdin);
    //fclose(stdout);
    return 0;
}