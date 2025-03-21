#pragma GCC optimize(1)
#pragma GCC optimize(2)
#pragma GCC optimize(3, "Ofast", "inline")
#include <bits/stdc++.h>
#define int long long
using namespace std;
constexpr int INF = 0x7fffffff;
void solve() {
    int n; cin >> n;
    string s; cin >> s; s = " " + s;
    vector<int> pre0(n + 1, 0), pre1(n + 1, 0);
    for (int i = 1; i <= n; ++ i) {
        pre0[i] = pre0[i - 1];
        pre1[i] = pre1[i - 1];
        if (s[i] == '-') pre0[i] ++;
        else pre1[i] ++;
    }
    int ans{};
    for (int i = 2; i <= n - 1; ++ i) {
        if (s[i] == '-')
    }
    return;
}
signed main() {
    cin.tie(0) -> sync_with_stdio(0);
    int _ = 1; //cin >> _;
    while(_ --) solve();
    return 0;
}