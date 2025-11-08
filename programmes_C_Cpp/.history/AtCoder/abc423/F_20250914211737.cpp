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
    int ans{};
    for (int i{}; i < (1ll << n); ++ i) {
        vector<int> v;
        for (int j{}; j < n; ++ j) if (i & (1ll << j)) v.emplace_back(j);
        if (v.size() != m) continue;
        int lcm = 1ll;
        for (int x : v) {
            lcm = __lcm(lcm, a[x]);
            if (lcm > y) break;
        }
        if (lcm <= y) ans += y / lcm;
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