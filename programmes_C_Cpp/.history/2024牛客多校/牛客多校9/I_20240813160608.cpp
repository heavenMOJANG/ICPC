#pragma GCC optimize(1)
#pragma GCC optimize(2)
#pragma GCC optimize(3,"Ofast","inline")
#include<bits/stdc++.h>
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
int check(int x) {
    int f = sqrt((long double)x);
    return f * f == x;
}
int getLength(int L, int R) {
    long double LL = L, RR = R;
    return (int)(floor(sqrt(RR)) - ceil(sqrt(LL)) + 1);
}
void solve() {
    int n; read(n);
    string L, R; cin >> L >> R;
    int LL{}, LR{}, RL{}, RR{};
    int k = n / 2;
    for (int i = 0; i < k; ++ i) LL = LL * 10 + (L[i] - 48);
    for (int i = k; i < n; ++ i) LR = LR * 10 + (L[i] - 48);
    for (int i = 0; i < k; ++ i) RL = RL * 10 + (R[i] - 48);
    for (int i = k; i < n; ++ i) RR = RR * 10 + (R[i] - 48);
    if (LL == RL) {
        if (check(LL)) {write(getLength(LR, RR)); puts(""); return;}
        else {cout << "0\n"; return;}
    }
    int cntLR = getLength(LR, pow(10, k) - 1);
    int cntRR = getLength(0ll, RR);
    int cntL = getLength(LL, RL);
    int cntR = getLength(0ll, pow(10, k) - 1);
    int ans = 0;
    if (check(LL)) cntL --, ans += cntLR;
    if (check(RL)) cntL --, ans += cntRR;
    cntL = max((int)0, cntL);
    ans += cntL * cntR;
    write(ans);
}
signed main() {
    //cin.tie(0) -> sync_with_stdio(0);
    int _ = 1; //cin >> _;
    while(_ --) solve();
    return 0;
}