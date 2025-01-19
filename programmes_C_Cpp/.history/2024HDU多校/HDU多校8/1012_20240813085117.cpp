#pragma GCC optimize(1)
#pragma GCC optimize(2)
#pragma GCC optimize(3,"Ofast","inline")
#include<bits/stdc++.h>
#define int long long
using namespace std;
constexpr int INF = 0x7fffffff;
void solve() {
    int n; cin >> n;
    string s[3]; cin >> s[0] >> s[1] >> s[2];
    int maxn = 0;
    for (int i = 0; i < 3; ++ i) {
        int res = 0;
        for (int j = 0; j < n; ++ j) if (s[i] != s[(i + 1) % 3]) res ++;
        maxn = max(maxn, res);
    }
    cout << n - (maxn + 1) / 2 << "\n";
}
signed main() {
    cin.tie(0) -> sync_with_stdio(0);
    int _ = 1; cin >> _;
    while(_ --) solve();
    return 0;
}