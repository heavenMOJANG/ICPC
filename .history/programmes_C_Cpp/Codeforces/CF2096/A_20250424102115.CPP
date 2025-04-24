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
    int l = 1, r = n;
    vector<int> a(n + 1);
    for (int i = n; i; -- i) {
        if (s[i - 1] == '<') a[i] = l ++;
        else a[i] = r --;
        cout << a[i] << "\n";
    }
    a[0] = l;
    for (int i = 1; i <= n; ++ i) cout << a[i] << " \n"[i == n];
    return;
}
signed main() {
    cin.tie(0) -> sync_with_stdio(0);
    int _ = 1; cin >> _;
    while(_ --) solve();
    return 0;
}