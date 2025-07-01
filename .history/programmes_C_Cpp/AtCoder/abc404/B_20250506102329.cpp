#pragma GCC optimize(1)
#pragma GCC optimize(2)
#pragma GCC optimize(3, "Ofast", "inline")
#include <bits/stdc++.h>
#define int long long
using namespace std;
constexpr int INF = 0x7fffffff;
void solve() {
    int n; cin >> n;
    string s[n], t[n];
    for (int i{}; i < n; ++ i) cin >> s[i];
    for (int i{}; i < n; ++ i) cin >> t[i];
    int cnt{};
    while (1) {
        int ok = 1;
        vector tmp(n, vector<char>(n));
        for (int i{}; i < n; ++ i)
            for (int j{}; j < n; ++ j) tmp[][i] = s[i][j];
        int x = -1, y = -1;
        for (int i{}; i < n; ++ i)
            for (int j{}; j < n; ++ j)
                if (s[i][j] != t[i][j]) { x = i, y = j; ok = 0; break; }
    }
    cout << cnt << "\n";    
    return;
}
signed main() {
    cin.tie(0) -> sync_with_stdio(0);
    int _ = 1; //cin >> _;
    while(_ --) solve();
    return 0;
}