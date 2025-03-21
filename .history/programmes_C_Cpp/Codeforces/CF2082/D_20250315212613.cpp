#pragma GCC optimize(1)
#pragma GCC optimize(2)
#pragma GCC optimize(3, "Ofast", "inline")
#include <bits/stdc++.h>
#define int long long
#define i128 __int128
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
void solve() {
    i128 n; read(n);
    for (int i = 20000000; i >= 2; -- i) {
        i128 i3 = i * i * i;
        if (i3 <= n) break;
        if (i3 - n > 1e18) continue;
        int j = cbrt(i3 - N), j3 = j * j * j;
        if (j3 + N == i3) { cout << i << " " << j << "\n"; return; }
    }
    cout << "-1\n";
    return;
}
signed main() {
    cin.tie(0) -> sync_with_stdio(0);
    int _ = 1; //cin >> _;
    while(_ --) solve();
    return 0;
}