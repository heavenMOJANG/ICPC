#pragma GCC optimize(1)
#pragma GCC optimize(2)
#pragma GCC optimize(3, "Ofast", "inline")
#include <bits/stdc++.h>
#define int long long
using namespace std;
constexpr int INF = 0x7fffffff;
void solve() {
    int n, k; cin >> n >> k;
    string s; cin >> s;
    int cnt{};
    for (int i{}; i < n; ++ i)
        if (s[i] == 'o') {
            cnt ++;
            if (i >= 1 && s[i - 1] == '?') s[i - 1] = '.';
            if (i <= n - 2 && s[i + 1] == '?') s[i + 1] = '.';
        }
    vector<bool> vis(n, 0);
    int l{}, r{};
    for (int i{}; i < n; ++ i) {

    } 
    return;
}
signed main() {
    cin.tie(0) -> sync_with_stdio(0);
    int _ = 1; //cin >> _;
    while(_ --) solve();
    return 0;
}