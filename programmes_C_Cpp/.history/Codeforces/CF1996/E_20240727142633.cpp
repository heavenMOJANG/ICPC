#pragma GCC optimize(1)
#pragma GCC optimize(2)
#pragma GCC optimize(3,"Ofast","inline")
#include<bits/stdc++.h>
#define int long long
using namespace std;
constexpr int inf = 0x7fffffff;
template <typename T>
concept Can_bit = requires(T x) { x >>= 1; };
template <int MOD>
struct modint {
    int val;
    static int norm(const int& x) { return x < 0 ? x + MOD : x; }
    static constexpr int get_mod() { return MOD; }
    modint inv() const {
        assert(val);
        int a = val, b = MOD, u = 1, v = 0, t;
        while (b > 0) t = a / b, swap(a -= t * b, b), swap(u -= t * v, v);
        assert(b == 1);
        return modint(u);
    }
    modint() : val(0) {}
    modint(const int& m) : val(norm(m)) {}
    modint(const long long& m) : val(norm(m % MOD)) {}
    modint operator-() const { return modint(norm(-val)); }
    bool operator==(const modint& o) { return val == o.val; }
    bool operator<(const modint& o) { return val < o.val; }
    modint& operator+=(const modint& o) { return val = (1ll * val + o.val) % MOD, *this; }
    modint& operator-=(const modint& o) { return val = norm(1ll * val - o.val), *this; }
    modint& operator*=(const modint& o) { return val = static_cast<int>(1ll * val * o.val % MOD), *this; }
    modint& operator/=(const modint& o) { return *this *= o.inv(); }
    modint& operator^=(const modint& o) { return val ^= o.val, *this; }
    modint& operator>>=(const modint& o) { return val >>= o.val, *this; }
    modint& operator<<=(const modint& o) { return val <<= o.val, *this; }
    modint operator-(const modint& o) const { return modint(*this) -= o; }
    modint operator+(const modint& o) const { return modint(*this) += o; }
    modint operator*(const modint& o) const { return modint(*this) *= o; }
    modint operator/(const modint& o) const { return modint(*this) /= o; }
    modint operator^(const modint& o) const { return modint(*this) ^= o; }
    modint operator>>(const modint& o) const { return modint(*this) >>= o; }
    modint operator<<(const modint& o) const { return modint(*this) <<= o; }
    friend std::istream& operator>>(std::istream& is, modint& a) {
        long long v;
        return is >> v, a.val = norm(v % MOD), is;
    }
    friend std::ostream& operator<<(std::ostream& os, const modint& a) { return os << a.val; }
    friend std::string tostring(const modint& a) { return std::to_string(a.val); }
    template <Can_bit T>
    friend modint qpow(const modint& a, const T& b) {
        assert(b >= 0);
        modint x = a, res = 1;
        for (T p = b; p; x *= x, p >>= 1)
            if (p & 1) res *= x;
        return res;
    }
};
using M107 = modint<1000000007>;
void solve() {
    string s; cin >> s;
    int n = s.size();
    vector<int> pre(n + 1, 0);
    vector<>
    s = " " + s;
    map<int, int>mp;
    int ans = 0;
    for (int i = 1; i <= n; ++ i) {
        if (s[i] == '0') pre[i] = -1;
        else pre[i] = 1;
        pre[i] += pre[i - 1];
        ans += mp[pre[i]];
        mp[pre[i]] ++;
    }
    cout << ans << "\n";
    return;
}
signed main() {
    cin.tie(0) -> sync_with_stdio(0);
    int _ = 1; cin >> _;
    while(_ --) solve();
    return 0;
}