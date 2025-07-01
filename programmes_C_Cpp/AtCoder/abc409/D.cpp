#pragma GCC optimize(3, "Ofast", "inline")
#include <bits/stdc++.h>
#define int long long
using namespace std;
constexpr int INF = 0x7fffffff;
void solve() {
    int n; cin >> n;
    string s; cin >> s;
    int l = -1;
    for (int i{}; i + 1 < n; ++ i) if (s[i] > s[i + 1]) { l = i; break; }
    if (l == -1) { cout << s << "\n"; return; }
    int r = l;
    while (r + 1 < n && s[r + 1] <= s[l]) r ++;
    for (int i{}; i < l; ++ i) cout << s[i];
    for (int i = l + 1; i <= r; ++ i) cout << s[i];
    cout << s[l];
    for (int i = r + 1; i < n; ++ i) cout << s[i];
    cout << "\n";
    return;
}
signed main() {
    cin.tie(0) -> sync_with_stdio(0);
    int _ = 1; cin >> _;
    while(_ --) solve();
    return 0;
}