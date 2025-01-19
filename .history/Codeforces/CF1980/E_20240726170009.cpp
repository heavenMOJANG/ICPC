#pragma GCC optimize(1)
#pragma GCC optimize(2)
#pragma GCC optimize(3,"Ofast","inline")
#include<bits/stdc++.h>
#define int long long
using namespace std;
constexpr int inf = 0x7fffffff;
void solve() {
    int n, m; cin >> n >> m;
    vector<vector<int>> a(n, vector<int>(m)), b(n, vector<int>(m));
    map<vector<int>, int> mpRowA, mpColA, mpRowB, mpColB;
    for (int i = 0; i < n; ++ i) {
        vector<int> t(m);
        for (int j = 0; j < m; ++ j) cin >> a[i][j], t[j] = a[i][j];
        sort(t.begin(), t.end());
        mpRowA[t] ++;
    }
    for (int j = 0; j < m; ++ j) {
        vector<int> t(n);
        for (int i = 0;i < n; ++ i) t[i] = a[i][j];
        sort(t.begin(), t.end());
        mpColA[t] ++;
    }
    for (int i = 0; i < n; ++ i) {
        vector<int> t(m);
        for (int j = 0; j < m; ++ j) cin >> b[i][j], t[j] = b[i][j];
        sort(t.begin(),t.end());
        mpRowA[t] ++;
    }
    for (int j = 0; j < m; ++ j) {
        vector<int> t(n);
        for (int i = 0;i < n; ++ i) t[i] = b[i][j];
        sort(t.begin(), t.end());
        mpColB[t] ++;
    }
    return;
}
signed main() {
    cin.tie(0) -> sync_with_stdio(0);
    int _ = 1; cin >> _;
    while(_ --) solve();
    return 0;
}