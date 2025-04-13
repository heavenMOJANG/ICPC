#pragma GCC optimize(1)
#pragma GCC optimize(2)
#pragma GCC optimize(3, "Ofast", "inline")
#include <bits/stdc++.h>
#define int long long
using namespace std;
constexpr int INF = 0x7fffffff;
constexpr int MOD = 1e9;
void solve() {
    int n, k; cin >> n >> k;
    if (n < k) { cout << "1\n"; return; }
    vector<int> a(n + 1);
    for (int i{}; i < k; ++ i) a[i] = 1;
    int sum = k;
    a[k] = k;
    for (int i = k + 1; k <= n; ++ i) {
        
    }
    return;
}
signed main() {
    cin.tie(0) -> sync_with_stdio(0);
    int _ = 1; //cin >> _;
    while(_ --) solve();
    return 0;
}