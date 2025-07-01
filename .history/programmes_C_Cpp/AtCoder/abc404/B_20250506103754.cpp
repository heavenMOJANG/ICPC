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
    int minn = INF;
    for (int k{}; k < 4; k ++) {
        vector tmp(n, vector<char>(n));
        int cnt{};
        if (k) for (int i{}; i < n; ++ i) for (int j{}; j < n; ++ j) tmp[j][n - 1 - i] = s[i][j];
        else for (int i{}; i < n; ++ i) for (int j{}; j < n; ++ j) tmp[i][j] = s[i][j];
        for (int i{}; i < n; ++ i)
            for (int j{}; j < n; ++ j)
                if (tmp[i][j] != t[i][j]) cnt ++;
        minn = min(minn, k + cnt);
        for (int i{}; i < n; ++ i) for (int j{}; j < n; ++ j) s[i][j] = tmp[i][j];
        cout << "Case:" << k << "\n";
        for (int i{}; i < n; ++ i) cout << s[i] << "\n";
    }
    cout << minn << "\n";    
    return;
}
signed main() {
    cin.tie(0) -> sync_with_stdio(0);
    int _ = 1; //cin >> _;
    while(_ --) solve();
    return 0;
}