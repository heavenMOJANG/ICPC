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
    int maxA = 0, maxB = 0;
    for (int i = 0; i < n; ++ i) {
        cin >> a[i] >> b[i];
        maxA = max(maxA, a[i]);
        maxB = max(maxB, b[i]);
    }
    X += maxA, Y += maxB;
    map<pii, int> mp, tmp;
    mp[{0, 0}] = 0;
    for (int i = 0; i < n; ++ i) {
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
        if (i == n - 1) cout << ans << "\n";
    }
    return;
}
signed main() {
    cin.tie(0) -> sync_with_stdio(0);
    int _ = 1; //cin >> _;
    while(_ --) solve();
    return 0;
}