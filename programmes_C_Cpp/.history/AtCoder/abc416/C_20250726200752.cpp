#pragma GCC optimize(3, "Ofast", "inline")
#include <bits/stdc++.h>
#define int long long
using namespace std;
constexpr int INF = 0x7fffffff;
void solve() {
    int n, k, x; cin >> n >> k >> x;
    vector<string> a(n);
    for (int i{}; i < n; ++ i) cin >> a[i];
    vector<int> p(k);
    iota(p.begin(), p.end(), 0);
    int cnt{};
    do {
        cnt ++;
        if (cnt == x) break;
    } while (next_permutation(p.begin(), p.end()));
    for (int i{}; i < k; ++ i) cout << a[p[i]];
    return;
}
signed main() {
    cin.tie(nullptr) -> sync_with_stdio(false);
    int _ = 1; //cin >> _;
    while(_ --) solve();
    return 0;
}