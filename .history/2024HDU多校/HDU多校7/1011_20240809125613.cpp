#pragma GCC optimize(1)
#pragma GCC optimize(2)
#pragma GCC optimize(3,"Ofast","inline")
#include<bits/stdc++.h>
#define int __int128
using namespace std;
constexpr int INF = 0x7fffffff;
constexpr int N = 1e6;
int idx, primes[N + 1], isPrime[N + 1];
void read(__int128 & n){
    __int128 x = 0,f = 1;
    char ch = getchar();
    while (ch < '0' || ch > '9') { if(ch=='-') f = -1; ch = getchar();}
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
bool millerRabin(int n) {
  if (n < 3 || n % 2 == 0) return n == 2;
  if (n % 3 == 0) return n == 3;
  int u = n - 1, t = 0;
  while (u % 2 == 0) u /= 2, ++t;
  // test_time 为测试次数，建议设为不小于 8
  // 的整数以保证正确率，但也不宜过大，否则会影响效率
  for (int i = 0; i < 8; ++i) {
    // 0, 1, n-1 可以直接通过测试, a 取值范围 [2, n-2]
    int a = rand() % (n - 3) + 2, v = fastPow(a, u, n);
    if (v == 1) continue;
    int s;
    for (s = 0; s < t; ++s) {
      if (v == n - 1) break;  // 得到平凡平方根 n-1，通过此轮测试
      v = (long long)v * v % n;
    }
    // 如果找到了非平凡平方根，则会由于无法提前 break; 而运行到 s == t
    // 如果 Fermat 素性测试无法通过，则一直运行到 s == t 前 v 都不会等于 -1
    if (s == t) return 0;
  }
  return 1;
}
void solve() {
    int x, y; read(x); read(y);
    if (x % y == 0) {write(y); putchar(' '); write(x / y); puts(""); return;}
    int tx = x, ty = y;
    map<int, int> mpx, mpy;
    int p = 0;
    while (tx != 1 && p < idx) {
        int k = 0;
        while (tx % primes[p] == 0) tx /= primes[p], k++;
        if (k) mpx[primes[p]] = k;
        p ++;
    }
    p = 0;
    while (ty != 1 && p < idx) {
        int k = 0;
        while (ty % primes[p] == 0) ty /= primes[p], k++;
        if (k) mpy[primes[p]] = k;
        p ++;
    }
    if (ty != 1) mpy[ty] ++;
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