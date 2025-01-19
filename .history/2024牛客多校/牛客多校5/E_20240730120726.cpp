#pragma GCC optimize(1)
#pragma GCC optimize(2)
#pragma GCC optimize(3,"Ofast","inline")
#include<bits/stdc++.h>
#define int long long
using namespace std;
constexpr int inf = 0x7fffffff;
void solve() {
    int n; cin >> n;
    vector<int> a(n), b(n);
    for (int i = 0; i < n; ++ i) cin >> a[i];
    int cntMay = 0, cntEqual = 0;
    for (int i = 0; i < n; ++ i)  {
        cin >> b[i];
        if (a[i] == b[i]) cntEqual ++;
        if (a[i] > b[i]) cntMay ++;
    }
    cout << cntMay + cntEqual / 2 << "\n";
    return;
}
signed main() {
    cin.tie(0) -> sync_with_stdio(0);
    int _ = 1; cin >> _;
    while(_ --) solve();
    return 0;
}