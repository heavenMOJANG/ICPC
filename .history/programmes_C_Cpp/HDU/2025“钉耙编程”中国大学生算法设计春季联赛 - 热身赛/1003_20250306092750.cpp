#pragma GCC optimize(1)
#pragma GCC optimize(2)
#pragma GCC optimize(3, "Ofast", "inline")
#include <bits/stdc++.h>
#define int long long
#define i128 __int128
using namespace std;
constexpr int INF = 0x7fffffff;
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
    cout << (C - B) / A << "\n";
    return;
}
signed main() {
    cin.tie(0) -> sync_with_stdio(0);
    int _ = 1; //cin >> _;
    while(_ --) solve();
    return 0;
}