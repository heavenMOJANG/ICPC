#pragma GCC optimize(3, "Ofast", "inline")
#include <bits/stdc++.h>
#define int long long
using namespace std;
constexpr int INF = 0x7fffffff;
void solve() {
    int X, Y, L, R, A, B; cin >> X >> Y >> L >> R >> A >> B;
    int p1{max(0ll, min(B, R) - max(A, L))};
    int p2{B - A - p1};
    cout << X * p1 + Y * p2 << "\n";
    return;
}
signed main() {
    cin.tie(nullptr) -> sync_with_stdio(false);
    int _ = 1; //cin >> _;
    while(_ --) solve();
    return 0;
}