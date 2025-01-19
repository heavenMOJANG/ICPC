#pragma GCC optimize(1)
#pragma GCC optimize(2)
#pragma GCC optimize(3,"Ofast","inline")
#include<bits/stdc++.h>
#define int long long
using namespace std;
constexpr int inf = 0x7fffffff;
void solve() {
    int n, k; cin >> n >> k;
    vector<vector<char>>a(n, vector<char>(n));
    for (int i = 0; i < n; ++ i) {
        for (int j = 0; j < n; ++ j) {
            cin >> a[i][j];
            if (i % k == 0 && j % k == 0) cout << a[i][j];
        }
        cout << "\n";
    }   
    return;
}
signed main() {
    cin.tie(0) -> sync_with_stdio(0);
    int _ = 1; cin >> _;
    while(_ --) solve();
    return 0;
}