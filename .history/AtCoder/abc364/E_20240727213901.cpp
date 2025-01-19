#pragma GCC optimize(1)
#pragma GCC optimize(2)
#pragma GCC optimize(3,"Ofast","inline")
#include<bits/stdc++.h>
#define int long long
#define pii pair<int, int>
using namespace std;
constexpr int inf = 0x7fffffff;
void solve() {
    int n, X, Y; cin >> n >> X >> Y;
    vector<int> a(n), b(n);
    map<pii, int> mp, tmp;
    mp[{0, 0}] = 0;
    int maxn = 0;
    for (int i = 0; i < n; ++ i) {
        cin >> a[i] >> b[i];
        tmp.clear();
        for (auto it = mp.begin(); it != mp.end(); ++ it) {
            int x = it -> first.first, y = it -> first.second, z = it -> second;
            if (tmp.find({x, y}) == tmp.end()) tmp[{x, y}] = z;
            else tmp[{x, y}] = max(tmp[{x, y}], z);
            if (x + a[i] <= X && y + b[i] <= Y)
                tmp[{x + a[i], y + b[i]}] = max(tmp[{x + a[i], y + b[i]}], z + 1);
        }
        mp.clear();
        int ans = -1;
        for (auto it = tmp.begin(); it != tmp.end(); ++ it) {
            if (it -> second > ans ) mp[it -> first] = it -> second;
            ans = it -> second;
        }
        maxn = max(maxn, ans);
    }
    cout << min(maxn + 1, n) << "\n";
    return;
}
signed main() {
    cin.tie(0) -> sync_with_stdio(0);
    int _ = 1; //cin >> _;
    while(_ --) solve();
    return 0;
}