#pragma GCC optimize(1)
#pragma GCC optimize(2)
#pragma GCC optimize(3, "Ofast", "inline")
#include <bits/stdc++.h>
#define int long long
#define i128 __int128
using namespace std;
constexpr int INF = 0x7fffffff;
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
    int n; cin >> n;
    i128 A{}, B{}, C{};
    for (int i = 0; i < n; ++ i) {
        unsigned long long x; cin >> x;
        A += x;
    }
    for (int i = 0; i < n; ++ i) {
        unsigned long long x; cin >> x;
        B += x;
    }
    for (int i = 0; i < n; ++ i) {
        unsigned long long x; cin >> x;
        C += x;
    }
    write((C - B) / A);
    cout << "\n";
    return;
}
signed main() {
    cin.tie(0) -> sync_with_stdio(0);
    int _ = 1; cin >> _;
    while(_ --) solve();
    return 0;
}