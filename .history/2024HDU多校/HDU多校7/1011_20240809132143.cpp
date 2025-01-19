#pragma GCC optimize(1)
#pragma GCC optimize(2)
#pragma GCC optimize(3,"Ofast","inline")
#include<bits/stdc++.h>
#define int __int128
using namespace std;
constexpr int INF = 0x7fffffff;
void read(__int128 & n){
    __int128 x = 0,f = 1;
    char ch = getchar();
    while (ch < '0' || ch > '9') { if (ch == '-') f = -1; ch = getchar();}
    while (ch >= '0' && ch <= '9') { x = x * 10 + (ch ^ 48); ch = getchar();}
    n = x * f;
}
void write(__int128 n){
    if (n < 0) { putchar('-'); n *= -1;}
    static __int128 sta[256];
    __int128 top = 0;
    do{
        sta[top ++] = n % 10, n /= 10;
    } while (n);
    while (top) putchar(sta[-- top] + 48);
}
void solve() {
    int x, y; read(x); read(y);
    if (x % y == 0) {write(y); putchar(' '); write(x / y); puts(""); return;}
    int d = y / __gcd(x, y);
    if (d & 1) d *= 2;
    write(y); putchar(' '); write(lcm / y); puts("");
}
signed main() {
    cin.tie(0) -> sync_with_stdio(0);
    int _ = 1; read(_);
    while(_ --) solve();
    return 0;
}