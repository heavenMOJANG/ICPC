#pragma GCC optimize(1)
#pragma GCC optimize(2)
#pragma GCC optimize(3,"Ofast","inline")
#include<bits/stdc++.h>
#define int long long
using namespace std;
constexpr int inf = 0x7fffffff;
void solve() {
    int n; cin >> n;
    vector<int> a(n + 1);
    for (int i = 1; i <= n; ++ i) cin >> a[i];
    vector<int> vis(n + 1, 0);
    int ans = 0, sum = 0;
    for (int i = 1; i <= n; ++ i) {
        int len = 0, x = i;
        while (!vis[x]) {
            vis[x] = 1;
            x = a[x];
            len ++;
        }
        if (len > 1) 
            if (len % 4 == 2) sum += len;
            else ans += (len + 3) / 4;
    }
    cout << ans + sum / 4 << "\n";
    return;
}
signed main() {
    cin.tie(0) -> sync_with_stdio(0);
    int _ = 1; cin >> _;
    while(_ --) solve();
    return 0;
}