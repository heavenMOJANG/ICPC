#pragma GCC optimize(1)
#pragma GCC optimize(2)
#pragma GCC optimize(3,"Ofast","inline")
#include<bits/stdc++.h>
#define int long long
using namespace std;
constexpr int INF = 0x7fffffff;
void solve() {
    int n, k; cin >> n >> k;
    vector<int> r(n + 1);
    for (int i = 1; i <= n; ++ i) cin >> r[i];
    dfs(0, 0);
    function<void(int, int)> dfs = [&](int x, int sum) {
        if (x == n + 1) {
            if (sum % k == 0) {
                for (int i = 1; i <= n; ++ i) cout << a[i] << " \n"[i == n];
            }
            return;
        }
    }
}
signed main() {
    cin.tie(0) -> sync_with_stdio(0);
    int _ = 1; //cin >> _;
    while(_ --) solve();
    return 0;
}