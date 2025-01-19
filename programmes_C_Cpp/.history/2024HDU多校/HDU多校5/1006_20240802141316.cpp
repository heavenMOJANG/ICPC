#pragma GCC optimize(1)
#pragma GCC optimize(2)
#pragma GCC optimize(3,"Ofast","inline")
#include<bits/stdc++.h>
#define int long long
using namespace std;
constexpr int INF = 0x7fffffff;
void solve() {
    int a, b, c; cin >> a >> b >> c;
    int cntOdd = 0, cntEven = 0;
    if (a & 1) cntOdd ++; else cntEven ++;
    if (b & 1) cntOdd ++; else cntEven ++;
    if (c & 1) cntOdd ++; else cntEven ++;
    if (a == b && b == c || cntOdd == 3) {cout << "NO\n"; return;}
    if (cntOdd == 1 || cntOdd == 2) {cout << "YES\n"; return;}
    a /= 2, b /= 2, c /= 2;
    if ((a + b) & 1 || (a + c) & 1 || (b + c) & 1) {cout << "YES\n"; return;}
    return;
}
signed main() {
    cin.tie(0) -> sync_with_stdio(0);
    int _ = 1; cin >> _;
    while(_ --) solve();
    return 0;
}