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
    vector<int> a(n), c(N + 1, 0);
    for (int i = 0; i < n; ++ i) cin >> a[i], c[a[i]] = 1;
    int ans = 0;
    for (int i = n - 1; i >= 0; ++ i) {

    }
    cout << ans << "\n";
    cout << (ans & 1 ? "dXqwq\n" : "Haitang\n");
    return;
}
signed main() {
    cin.tie(0) -> sync_with_stdio(0);
    int _ = 1; cin >> _;
    while(_ --) solve();
    return 0;
}