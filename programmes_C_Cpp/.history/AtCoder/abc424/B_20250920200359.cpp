#pragma GCC optimize(3, "Ofast", "inline")
#include <bits/stdc++.h>
#define int long long
using namespace std;
constexpr int INF = 0x7fffffff;
void solve() {
    int n, m, k; cin >> n >> m >> k;
    vector<int> c(n + 1, 0);
    while (k --) {
        int a, b; cin >> a >> b;
        c[a] |= 1 << b;
        if (c[a] == (1 << (m + 1)) - 1) cout << "Yes ";
    }
    return;
}
signed main() {
    cin.tie(nullptr) -> sync_with_stdio(false);
    int _ = 1; //cin >> _;
    while(_ --) solve();
    return 0;
}