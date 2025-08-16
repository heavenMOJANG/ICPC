#pragma GCC optimize(3, "Ofast", "inline")
#include <bits/stdc++.h>
#define int long long
using namespace std;
using i128 = __int128;
void read(i128& n) {
    __int128 x{}, f = 1;
    char ch = getchar();
    while (ch < '0' || ch > '9') { if (ch == '-') f = -1; ch = getchar(); }
    while (ch >= '0' && ch <= '9') { x = x * 10 + (ch ^ 48); ch = getchar(); }
    n = x * f;
}
void write(i128 n) {
    if (n < 0) { putchar('-'); n *= -1; }
    static __int128 sta[256];
    __int128 top{};
    do {
        sta[top ++] = n % 10, n /= 10;
    } while(n);
    while(top) putchar(sta[-- top] + 48);
}
i128 n, w, N, cnt, cur, ans, k, s, t;
void solve() {
    read(n); read(w);
    if (w == 1) { write(n * (n + 1) / 2); puts(""); return; }
    
    write(ans); puts("");
}
signed main(){
    i128 _ = 1; read(_);
    while(_ --) solve();
    return 0;
}