#pragma GCC optimize(1)
#pragma GCC optimize(2)
#pragma GCC optimize(3,"Ofast","inline")
#include<bits/stdc++.h>
#define int __int128
using namespace std;
constexpr int INF = 0x7fffffff;
constexpr int N = 1e6;
int idx, primes[N], isPrime[N + 1];
void read(__int128 & n){
    __int128 x = 0,f = 1;
    char ch = getchar();
    while (ch < '0' || ch > '9') { if(ch=='-') f = -1; ch = getchar();}
    while (ch >= '0' && ch <= '9') { x = x * 10 + (ch ^ 48); ch = getchar();}
    n = x * f;
}
void write(__int128 n){
    if ( n < 0) { putchar('-'); n *= -1;}
    static __int128 sta[256];
    __int128 top = 0;
    do{
        sta[top ++] = n % 10, n /= 10;
    } while (n);
    while (top) putchar(sta[-- top] + 48);
}
void getPrimes() {
    fill(isPrime, isPrime + 1 + N, 1);
    isPrime[1] = 0;
    for (int i = 2; i <= N; ++ i) {
        if (isPrime[i]) primes[idx ++] = i;
        for (int j = 0; j < idx && i * primes[j] <= N; ++ j) {
            isPrime[i * primes[j]] = 0;
            if (i % primes[j] == 0) break;
        }
    }
}
int fastPow(int a, int x) {
    int res = 1;
    while (x) {
        if (x & 1) res = res * a;
        a = a * a;
        x >>= 1;
    }
    return res;
}
void solve() {
    int x, y; read(x); read(y);
    if (x % y == 0) {write(y); putchar(' '); write(x / y); puts(""); return;}
    int tx = x, ty = y;
    map<int, int> mpx, mpy;
    int p = 0;
    while (tx != 1) {
        int k = 0;
        while (tx % primes[p] == 0) tx /= primes[p], k++;
        if (k) mpx[primes[p]] = k;
        p ++;
    }
    p = 0;
    while (ty != 1) {
        int k = 0;
        while (ty % primes[p] == 0) ty /= primes[p], k++;
        if (k) mpy[primes[p]] = k;
        p ++;
    }
    int n = 1;
    for (auto [a, b] : mpy)
        if (b > mpx[a]) n *= fastPow(a, b - mpx[a]);
    if (n % 2 == 0) n >>= 1;
    write(y); putchar(' '); write(n * 2 * x / y); puts("");
}
signed main() {
    cin.tie(0) -> sync_with_stdio(0);
    getPrimes();
    int _ = 1; read(_);
    while(_ --) solve();
    return 0;
}