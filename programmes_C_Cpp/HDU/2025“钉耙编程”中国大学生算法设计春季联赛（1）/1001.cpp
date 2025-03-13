#pragma GCC optimize(1)
#pragma GCC optimize(2)
#pragma GCC optimize(3, "Ofast", "inline")
#include <bits/stdc++.h>
#define int long long
using namespace std;
constexpr int INF = 0x7fffffff;
void solve() {
    int n;
    string s; cin >> n >> s;
    int flag = -1;
    for (int i = 0; i < n; ++ i) {
        int rnk;
        string t; cin >> t;
        if (t == s) flag = i + 1;
    }
    cout << flag << "\n";
    return;
}
signed main() {
    cin.tie(0) -> sync_with_stdio(0);
    int _ = 1; cin >> _;
    while(_ --) solve();
    return 0;
}