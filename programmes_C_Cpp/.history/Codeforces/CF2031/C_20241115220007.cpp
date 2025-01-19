#pragma GCC optimize(1)
#pragma GCC optimize(2)
#pragma GCC optimize(3, "Ofast", "inline")
#include <bits/stdc++.h>
#define int long long
using namespace std;
constexpr int INF = 0x7fffffff;
int check(int x) {
    int f = floor(sqrt(x));
    return f * f == x;
}
void solve() {
    int n; cin >> n;
    if (n & 1) {
        if (n < 27) { cout << "-1\n"; return; }
        vector<int> ans(n + 1);
        ans[1] = ans[10] = ans[26] = 1;
        ans[23] = ans[27] = 2;
        ans[24] = ans[25] = 3;
        int cnt = 4;
        for (int i = 2; i <= 8; ++ i) 
        return;
    } else
        for (int i = 1; i <= n; i += 2) cout << i << " " << i << " \n"[i == n - 1];
    return;
}
signed main() {
    cin.tie(0) -> sync_with_stdio(0);
    int _ = 1; cin >> _;
    while(_ --) solve();
    return 0;
}