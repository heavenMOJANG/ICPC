#pragma GCC optimize(3, "Ofast", "inline")
#include <bits/stdc++.h>
#define int long long
using namespace std;
constexpr int INF = 0x7fffffff;
void solve() {
    int n; cin >> n;
    int flag{};
    vector C(n + 1, vector<int> (n + 1));
    for (int i = 1; i <= n; ++ i)
        for (int j = i + 1; j <= n; ++ j) cin >> C[i][j];
    for (int a = 1; a <= n - 2; ++ a)
        for (int b = a + 1; b <= n - 1; ++ b)
            for (int c = b + 1; c <= n; ++ c)
                if (C[a][b] + C[b][c] < C[a][c]) flag = 1;
    cout << (flag ? "Yes\n" : "No\n");
    return;
}
signed main() {
    cin.tie(nullptr) -> sync_with_stdio(false);
    int _ = 1; //cin >> _;
    while(_ --) solve();
    return 0;
}