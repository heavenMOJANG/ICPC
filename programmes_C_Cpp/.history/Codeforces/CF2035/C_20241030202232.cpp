#pragma GCC optimize(1)
#pragma GCC optimize(2)
#pragma GCC optimize(3, "Ofast", "inline")
#include <bits/stdc++.h>
#define int long long
using namespace std;
constexpr int INF = 0x7fffffff;
void solve() {
    int n; cin >> n;
    if (n == 6) {cout << "2 3 4 5 1 6\n"; return;}
    vector<int> vis(n + 1, 0);
    vis[3] = vis[1] = vis[n - 1] = vis[n] = 1;
    if (n & 1) {
        cout << n << "\n";
        for (int i )
    } else {

    }

    return;
}
signed main() {
    cin.tie(0) -> sync_with_stdio(0);
    int _ = 1; //cin >> _;
    while(_ --) solve();
    return 0;
}