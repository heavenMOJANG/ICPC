#pragma GCC optimize(3, "Ofast", "inline")
#include <bits/stdc++.h>
#define int long long
using namespace std;
constexpr int INF = 0x7fffffff;
constexpr int MOD = 998244353;
int qpow(int a, int x) {
    int f = 1;
    while (x) {
        if (x & 1) f = f * a % MOD;
        a = a * a % MOD;
        x >>= 1;
    }
    return f;
}
void solve() {
    int n; cin >> n;
    string s; cin >> s;
    vector<int> cnt(26, 0);
    for (char c : s) cnt[c - 'a'] ++;
    int ans = 1;
    for (int x : cnt) ans = ans * qpow(x + 1, MOD - 2) % MOD;
    ans = qpow(2, n) * ans % MOD;
    cout << ans << "\n";
    return;
}
signed main() {
    cin.tie(nullptr) -> sync_with_stdio(false);
    int _ = 1; //cin >> _;
    while(_ --) solve();
    return 0;
}