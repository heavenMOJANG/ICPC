#pragma GCC optimize(3, "Ofast", "inline")
#include <bits/stdc++.h>
#define int long long
using namespace std;
constexpr int INF = 0x7fffffff;
constexpr int N = 1e6 + 10;
array<int, N> mu, comp;
vector<int> primes;
void solve() {
    int n, m{}; cin >> n;
    vector<int> a(n);
    for (auto && x : a) cin >> x, m = max(m, x);
    vector<int> mul(m + 1), deg(n), mp(m + 1);
    for (int i{}; i < n; ++ i) mp[a[i]] ++;
    for (int j = 1; j <= m; ++ j)
        for (int x = j; x <= m; x += j) mul[j] += mp[x];
    for (int i{}; i < n; ++ i) {
        for (int j = 1; j * j <= a[i]; ++ j)
            if (a[i] % j == 0) {
                deg[i] += mu[j] * mul[j];
                if (j * j < a[i]) deg[i] += mu[a[i] / j] * mul[a[i] / j];
            }
        if (a[i] == 1) deg[i] --;
    }
    array<int, 4> ans = {-1, -1, -1, -1};
    int u{}, v{}, mind = INF;
    for (int i = 1; i < n; ++ i) if (deg[i] > deg[u]) u = i;
    if (!deg[u]) { cout << "0\n"; return; }
    deg[u] = 0;
    for (int i{}; i < n; ++ i) {
        if (i == u) continue;
        if (__gcd(a[i], a[u]) == 1) {
            deg[i] --;
            if (mind > deg[i]) mind = deg[i], v = i;
        }
    }
    if (mind == INF) { cout << "0\n"; return; }
    ans[0] = u, ans[1] = v;
    deg[v] = 0;
    for (int i{}; i < n; ++ i) {
        if (i == u || i == v) continue;
        if (__gcd(a[i], a[v]) == 1) deg[i] --;
    }
    u = 0;
    for (int i = 1; i < n; ++ i) if (deg[i] > deg[u]) u = i;
    if (!deg[u]) { cout << "0\n"; return; }
    v = -1;
    for (int i{}; i < n; ++ i) {
        if (i == u || !deg[i]) continue;
        if (__gcd(a[i], a[u]) == 1) { v = i; break; }
    }
    if (v == -1) { cout << "0\n"; return; }
    ans[2] = u; ans[3] = v;
    for (int i{}; i < 4; ++ i) cout << ans[i] + 1 << " \n"[i == 3];
}
signed main() {
    cin.tie(nullptr) -> sync_with_stdio(false);
    mu[1] = 1;
    for (int i = 2; i < N; ++ i) {
        if (!comp[i]) {
            primes.emplace_back(i);
            mu[i] = -1;
        }
        for (int p : primes) {
            int q = i * p;
            if (q >= N) break;
            comp[q] = 1;
            if (i % p == 0) { mu[q] = 0; break; }
            else mu[q] = -mu[i];
        }
    }
    int _ = 1; cin >> _;
    while(_ --) solve();
    return 0;
}