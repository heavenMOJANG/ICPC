#pragma GCC optimize(3, "Ofast", "inline")
#include <bits/stdc++.h>
#define int long long
using namespace std;
constexpr int INF = 0x7fffffff;
constexpr int MOD = 998244353;
void solve() {
    int n, c; cin >> n >> c;
    vector<int> a(n);
    for (auto && x : a) cin >> x;
    int C = a[c - 1];
    int maxn = *max_element(a.begin(), a.end());
    vector<int> f(maxn + 1, 0);
    for (auto x : a) f[x] ++;
    vector<int> b;
    for (int i = 1; i <= maxn; ++ i) if (f[i]) b.emplace_back(i);
    sort(b.begin(), b.end());
    int tot{};
    for (auto x : b) (tot += f[x] * x % MOD ) %= MOD;
    vector<int> suf(b.size() + 1, 0);
    for (int i = b.size() - 1; ~i; -- i) (suf[i] += b[i] * f[b[i]] % MOD) %= MOD;

    return;
}
signed main() {
    cin.tie(0) -> sync_with_stdio(0);
    int _ = 1; //cin >> _;
    while(_ --) solve();
    return 0;
}