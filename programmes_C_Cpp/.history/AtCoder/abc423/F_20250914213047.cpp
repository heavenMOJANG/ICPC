#pragma GCC optimize(3, "Ofast", "inline")
#include <bits/stdc++.h>
#define int __int128
using namespace std;
constexpr int INF = 0x7fffffff;
void read(__int128 & n) {
    __int128 x = 0,f = 1;
    char ch =  getchar();
    while (ch <'0' || ch > '9') {if (ch == '-') f = -1; ch = getchar();}
    while (ch >= '0' && ch <= '9') { x = x * 10 + (ch ^ 48); ch = getchar();}
    n = x * f;
}
void write(__int128 n) {
    if (n < 0) {putchar('-'); n *= -1;}
    static __int128 sta[256];
    __int128 top=0;
    do {
        sta[top ++] = n % 10, n /= 10;
    } while(n);
    while(top) putchar(sta[-- top] + 48);
}
int __lcm(int a, int b) { return a / __gcd(a, b) * b; }
void solve() {
    int n, m, y;
    read(n); read(m); read(y);
    vector<int> a(n);
    for (auto && x : a) read(x);
    vector<int> f(n + 1, 0);
    for (int i = 1; i < (1ll << n); ++ i) {
        vector<int> v;
        for (int j = 0; j < n; ++ j) if (i >> j & 1) v.emplace_back(a[j]);
        int lcm = 1;
        int ok = 1;
        for (int x : v) {
            int g = __gcd(lcm, a[x]);
            int t = lcm / g * a[x];
            if (t > y) { ok = 0; break; }
            lcm = t;
            if (!lcm|| lcm > y) { ok = 0; break; }
        }
        if (!ok) continue;
        f[(int)v.size()] += y / lcm;
    }
    vector c(n + 1, vector<int>(n + 1, 0));
    for (int i = 0; i <= n; ++ i) {
        c[i][0] = c[i][i] = 1;
        for (int j = 1; j < i; ++ j) c[i][j] = c[i - 1][j - 1] + c[i - 1][j];
    }
    int ans{};
    for (int k = m; k <= n; ++ k) {
        int s = ((k - m) % 2 == 0) ? 1 : -1, term = c[k][m] * f[k];
        ans += s * term;
    }
    write(ans); puts("");
    return;
}
signed main() {
    cin.tie(nullptr) -> sync_with_stdio(false);
    int _ = 1; //cin >> _;
    while(_ --) solve();
    return 0;
}