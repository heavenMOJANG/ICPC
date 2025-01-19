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
    for (int i = 0; i < n; ++ i) {
        cin >> a[i] >> b[i];
        tmp.clear();
        for (auto it = mp.begin(); it != mp.end(); ++ it) {
            int x = it->first.first, y = it->first.second, z = it->second;
            if (tmp.find({x, y}) == tmp.end()) tmp[{x, y}] = z;
            else tmp[{x, y}] = max(tmp[{x, y}], z);
            if (x + a[i] <= X && y + b[i] <= Y)
                tmp[{x + a[i], y + b[i]}] = max(tmp[{x + a[i], y + b[i]}], z + 1);
        }
    }
    return;
}
signed main() {
    cin.tie(0) -> sync_with_stdio(0);
    int _ = 1; //cin >> _;
    while(_ --) solve();
    return 0;
}