#pragma GCC optimize(1)
#pragma GCC optimize(2)
#pragma GCC optimize(3, "Ofast", "inline")
#include <bits/stdc++.h>
#define int long long
using namespace std;
constexpr int INF = 0x7fffffff;
void solve() {
    int n; cin >> n;
    string s; cin >> s;
    if (n == 1) { cout << (s == "/" ? "Yes\n" : "No\n"); return; }
    for (int i = 0; i < (n - 1) / 2; ++ i) if (s[i] != '1') { cout << "No\n"; return; }
    if (s[(n - 1) / 2] != '/') { cout << "No\n"; return; }
    for (int i = (n - 1) / 2 + 1; i < n; ++ i) if (s[i] != '2') { cout << "No\n"; return; }
    cout << "Yes\n";
    return;
}
signed main() {
    cin.tie(0) -> sync_with_stdio(0);
    int _ = 1; //cin >> _;
    while(_ --) solve();
    return 0;
}