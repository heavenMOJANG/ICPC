#pragma GCC optimize(1)
#pragma GCC optimize(2)
#pragma GCC optimize(3,"Ofast","inline")
#include<bits/stdc++.h>
#define int long long
using namespace std;
constexpr int INF = 0x7fffffff;
constexpr int N = 1e5;
void solve() {
    int n; cin >> n;
    vector<int> a(n), c(N + 1, 0), f(N + 1);
    for (int i = 0; i < n; ++ i) cin >> a[i], c[a[i]] = 1;
    int ans = 0;
    for (int i = N; i >= 1; -- i) {
        f[i] = 0;
        for (int j = i; j <= N; j += i) f[i] += c[j];
        f[i] = f[i] * (f[i] - 1) / 2;
        for (int j = i * 2; j <= N; j += i) f[i] -= f[j];
        if (!c[i] && f[i]) {
            c[i] = 1;
            ans ++;
            f[i] = 0;
            for (int j = i; j <= N; j += i) f[i] += c[j];
            f[i] = f[i] * (f[i] - 1) / 2;
            for (int j = i * 2; j <= N; j += i) f[i] -= f[j];
        }
    }
    cout << (ans & 1 ? "dXqwq\n" : "Haitang\n");
    return;
}
signed main() {
    cin.tie(0) -> sync_with_stdio(0);
    int _ = 1; cin >> _;
    while(_ --) solve();
    return 0;
}