#pragma GCC optimize(1)
#pragma GCC optimize(2)
#pragma GCC optimize(3,"Ofast","inline")
#include<bits/stdc++.h>
#define int long long
using namespace std;
constexpr int INF = 0x7fffffff;
constexpr int N = 1e6 + 10;
mt19937_64 rnd(time(NULL));
vector<int> reff(N);
void solve() {
    int n, q; cin >> n >> q;
    vector<int> a(n + 1, 0);
    for (int i = 1; i <= n; ++ i) cin >> a[i], a[i] = reff[a[i]], a[i] ^= a[i - 1];
    while (q --) {
        int l, r; cin >> l >> r;
        if ((r - l + 1) & 1) {cout << "NO\n"; continue;}
        cout << ((a[l - 1] ^ a[r]) == 0 ? "YES\n" : "NO\n");
    }
    return;
}
signed main() {
    cin.tie(0) -> sync_with_stdio(0);
    for (int i = 1; i < N; ++ i) reff[i] = rnd();
    int _ = 1; cin >> _;
    while(_ --) solve();
    return 0;
}