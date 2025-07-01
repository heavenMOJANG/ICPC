#pragma GCC optimize(3, "Ofast", "inline")
#include <bits/stdc++.h>
#define int long long
using namespace std;
constexpr int INF = 0x7fffffff;
void solve() {
    int n; cin >> n;
    string s; cin >> s;
    string ans = s;
    if (n == 1) { cout << ans << "\n"; return; }
    char minc = s[1];
    int p = 1;
    for (int i = 2; i < n; ++ i) if (s[i] < minc) minc = s[i], p = i;
    string t = s; swap(t[p - 1], t[p]);
    cout << min(ans, t) << "\n";
    return;
}
signed main() {
    cin.tie(0) -> sync_with_stdio(0);
    int _ = 1; cin >> _;
    while(_ --) solve();
    return 0;
}