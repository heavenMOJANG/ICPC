#pragma GCC optimize(1)
#pragma GCC optimize(2)
#pragma GCC optimize(3, "Ofast", "inline")
#include <bits/stdc++.h>
#define int long long
using namespace std;
constexpr int INF = 0x7fffffff;
int calc(int n, string s) {
    int maxn{};
    vector pre(26, vector<int> (n + 2, 0));
    s = " " + s;
    for (int i = 1; i <= n; ++ i)
        for (int j = 0; j < 26; ++ j)
            if (s[i] - 'a' == j) pre[j][i] += pre[j][i - 1] + 1;
            else pre[j][i] += pre[j][i - 1];
    for (int i = 2; i <= n; ++ i)
        if (pre[s[i] - 'a'][i - 1]) maxn = max(maxn, n - i + 1);
    return maxn;
}
void solve() {
    int n; cin >> n;
    string s; cin >> s;
    int res0 = calc(n, s);
    reverse(s.begin(), s.end());
    int res1 = calc(n, s);
    cout << max(res0, res1) << "\n";
    return;
}
signed main() {
    cin.tie(0) -> sync_with_stdio(0);
    int _ = 1; //cin >> _;
    while(_ --) solve();
    return 0;
}