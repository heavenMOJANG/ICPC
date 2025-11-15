#pragma GCC optimize(3, "Ofast", "inline")
#include <bits/stdc++.h>
#define int long long
using namespace std;
constexpr int INF = 0x7fffffff;
void solve() {
    int N, X, Y; cin >> N >> X >> Y;
    vector<int> a(N);
    for (int i{}; i < N; ++ i) cin >> a[i];
    int d = Y - X, R = X * a[0] % d;
    for (int i = 1; i < N; ++ i) {
        int rr = X * a[i] % d;
        if (rr != R) { cout << "-1\n"; return; }
    }
    int L = X * a[0], R = Y * a[0];
    for (int i = 1; i < N; ++ i) {
        L = max(L, X * a[i]);
        R = min(R, Y * a[i]);
    }
    if (L > R) { cout << "-1\n"; return; }
    int m = X * a[0] % d, rt = R % d;
    int x = R - (rt - m + d) % d;
    if (x < L) { cout << "-1\n"; return; }

    return;
}
signed main() {
    cin.tie(nullptr) -> sync_with_stdio(false);
    int _ = 1; //cin >> _;
    while(_ --) solve();
    return 0;
}