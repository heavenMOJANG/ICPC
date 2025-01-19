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
    int ans = 0;
    vector<int> v;
    for (int i = 1; i <= n; ++ i) {
        int len = 0, x = i;
        while (!vis[x]) {
            vis[x] = 1;
            x = a[x];
            len ++;
        }
        if (len >= 4) ans += (len + 3) / 4;
        else if (len > 1) v.emplace_back(len);  
    }
    sort(v.begin(), v.end());
    int l = 0, r = v.size() - 1, sum = 0;
    while(l < r) {
        sum = v[r];
        while (sum < 4 && l + 1 < r) sum += a[++ l];
        cout << "sum:" << sum << "\n";
        ans += (sum + 3) / 4;
        r --;
        if(r == l) break;
    }
    cout << ans << "\n";
    return;
}
signed main() {
    cin.tie(0) -> sync_with_stdio(0);
    int _ = 1; cin >> _;
    while(_ --) solve();
    return 0;
}