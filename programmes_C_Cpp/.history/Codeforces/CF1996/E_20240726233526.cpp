#pragma GCC optimize(1)
#pragma GCC optimize(2)
#pragma GCC optimize(3,"Ofast","inline")
#include<bits/stdc++.h>
#define int long long
using namespace std;
constexpr int inf = 0x7fffffff;
void solve() {
    string s; cin >> s;
    int n = s.size();
    vector<int> pre(n + 1, 0);
    s = " " + s;
    for (int i = 1; i <= n; ++ i) {
        if (s[i] == '0') pre[i] = -1;
        else pre[i] = 1;
        pre[i] += pre[i - 1];
    }
    return;
}
signed main() {
    cin.tie(0) -> sync_with_stdio(0);
    int _ = 1; //cin >> _;
    while(_ --) solve();
    return 0;
}