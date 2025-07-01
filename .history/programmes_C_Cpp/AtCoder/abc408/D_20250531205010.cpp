#pragma GCC optimize(3, "Ofast", "inline")
#include <bits/stdc++.h>
#define int long long
using namespace std;
constexpr int INF = 0x7fffffff;
void solve() {
    int n; cin >> n;
    string s; cin >> s;
    vector<int> a(n + 1, 0);
    int tot{};
    for (int i{}; i < n; ++ i) {
        if (s[i] == '1') tot ++, a[i + 1] = 1;
        else a[i + 1] = -1;
    }
    for (int i = 1; i <= n; ++ i) {
        
    }
    return;
}
signed main() {
    cin.tie(0) -> sync_with_stdio(0);
    int _ = 1; //cin >> _;
    while(_ --) solve();
    return 0;
}