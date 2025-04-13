#pragma GCC optimize(1)
#pragma GCC optimize(2)
#pragma GCC optimize(3, "Ofast", "inline")
#include <bits/stdc++.h>
#define int long long
using namespace std;
constexpr int INF = 0x7fffffff;
struct Node {
    int x, y;
    bool operator < (const Node &rhs) const {
        return (x + y) == (rhs.x + rhs.y) ? x < rhs.x : (x + y) < (rhs.x + rhs.y);
    }
};
void solve() {
    int n; cin >> n;
    vector<int> t(n + 1);
    for (int i = 1; i <= n; ++ i) cin >> t[i];

    return;
}
signed main() {
    cin.tie(0) -> sync_with_stdio(0);
    int _ = 1; //cin >> _;
    while(_ --) solve();
    return 0;
}