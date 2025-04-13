#pragma GCC optimize(1)
#pragma GCC optimize(2)
#pragma GCC optimize(3, "Ofast", "inline")
#include <bits/stdc++.h>
#define int long long
using namespace std;
constexpr int INF = 0x7fffffff;
constexpr int MOD = 998244353;
constexpr int N = 5e5 + 10;
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
int fac[N];
void solve() {
    vector<int> c(26);
    for (auto && x : c) cin >> x;
    int sum = accumulate(c.begin(), c.end(), 0ll);
    int odd = (sum + 1) / 2, even = sum / 2;
    for (int i{}; i < 26; ++ i)
        if (c[i] > odd && c[i] > even) { cout << "0\n"; return; }
    vector<int> dp(odd + 1, 0);
    dp[0] = 1;
    int ans = fac[odd] * fac[even] % MOD;
    for (int i{}; i < 26; ++ i) {
        if (!c[i]) continue;
        ans 
    }
    return;
}
signed main() {
    cin.tie(0) -> sync_with_stdio(0);
    fac[0] = 1;
    for (int i = 1; i < N; ++ i) fac[i] = fac[i - 1] * i % MOD;
    int _ = 1; //cin >> _;
    while(_ --) solve();
    return 0;
}