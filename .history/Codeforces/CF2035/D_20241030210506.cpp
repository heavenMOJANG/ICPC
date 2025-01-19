#pragma GCC optimize(1)
#pragma GCC optimize(2)
#pragma GCC optimize(3, "Ofast", "inline")
#include <bits/stdc++.h>
#define int long long
using namespace std;
constexpr int INF = 0x7fffffff;
void solve() {
    int n; cin >> n;
    vector<int> a(n + 1), cnt(n + 1, 0);
    for (int i = 1; i <= n; ++ i) {
        cin >> a[i];
        while (a[i] % 2 == 0) a[i] >>= 1, cnt[i] ++;
    }
    auto fastPow = [&](int a, int x) {
        int res = 1;
        while (x) {
            if (x & 1) res = res * a % MOD;
        }
    };
    stack<int> s;
    return;
}
signed main() {
    cin.tie(0) -> sync_with_stdio(0);
    int _ = 1; //cin >> _;
    while(_ --) solve();
    return 0;
}