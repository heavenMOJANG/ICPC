#pragma GCC optimize(1)
#pragma GCC optimize(2)
#pragma GCC optimize(3,"Ofast","inline")
#include<bits/stdc++.h>
#define int long long
using namespace std;
constexpr int INF = 0x7fffffff;
void solve() {
    int n; cin >> n;
    vector<int> a(n + 1), pre(n + 1, 0);
    for (int i = 1; i <= n; ++ i) cin >> a[i], pre[i] = pre[i - 1] + a[i];
    vector<int> L, R;
    string s; cin >> s; s = " " + s;
    for (int i = 1; i <= n; ++ i)
        if (s[i] == 'L') L.emplace_back(i);
        else R.emplace_back(i);
    if (L.size() == 0 || R.size() == 0) {cout << "0\n"; return;}
    int l = 0, r = R.size() - 1;
    int ans = 0;
    while(L[l] < R[r] && l < L.size() && r >= 0) {
        ans += pre[R[r]] - pre[L[l] - 1];
        l ++, r --;
    }
    cout << ans << "\n";
}
signed main() {
    cin.tie(0) -> sync_with_stdio(0);
    int _ = 1; cin >> _;
    while(_ --) solve();
    return 0;
}