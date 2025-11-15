#pragma GCC optimize(3, "Ofast", "inline")
#include <bits/stdc++.h>
#define int long long
using namespace std;
constexpr int INF = 0x7fffffff;
void solve() {
    int N, X, Y; cin >> N >> X >> Y;
    vector<int> a(N);
    for (int i{}; i < N; ++ i) cin >> a[i];
    int d = Y - X, r = X * a[0] % d;
    for (int i = 1; i < N; ++ i) {
        int rr = X * a[i] % d;
        if (rr != r) { cout << "-1\n"; return; }
    }
    return;
}
signed main() {
    cin.tie(nullptr) -> sync_with_stdio(false);
    int _ = 1; //cin >> _;
    while(_ --) solve();
    return 0;
}