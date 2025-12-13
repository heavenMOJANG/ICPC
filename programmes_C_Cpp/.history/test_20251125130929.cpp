#pragma GCC optimize(3, "Ofast", "inline")
#include <bits/stdc++.h>
#define int long long
using namespace std;
constexpr int INF = 0x7fffffff;
void solve() {
    int n; cin >> n;
    string s; cin >> s; s = ' ' + s;
    vector<pair<char, int>> a;
    vector<int> pre0(n + 1, 0), pre1(n + 1, 0);
    for (int i = 1; i <= n; ++ i) {
        pre0[i] = pre0[i - 1] + (s[i] == '0');
        pre1[i] = pre1[i - 1] + (s[i] == '1');
    }
    a.emplace_back(s[1], 1);
    for (int i = 2; i <= n; ++ i)
        if (s[i] == a.back().first) a.back().second ++;
        else a.emplace_back(s[i], 1);
    int m = a.size();
    if (m <= 1) { cout << "0\n"; return; }
    int l = 1, ans = INF;
    for (int i{}; i < m; ++ i) {
        int r = l + a[i].second - 1;
        if (a[i].first == '0') {
            int cost = pre1[l - 1] + pre1[n] - pre1[r] + (pre0[l - 1] + pre0[n] - pre0[r]) * 2;
            ans = min(ans, cost);
        } else {
            int cost = pre0[l - 1] + pre0[n] - pre0[r] + (pre1[l - 1] + pre1[n] - pre1[r]) * 2;
            ans = min(ans, cost);
        }
        l += a[i].second;
    }
    cout << ans << "\n";
    return;
}
void test(int testcase) {
    string inf = to_string(testcase) + ".in";
    string outf = to_string(testcase) + ".out";
    freopen(inf.c_str(), "r", stdin);
    freopen(outf.c_str(), "w", stdout);
    int _ = 1; cin >> _;
    while(_ --) solve();
    fclose(stdin);
    fclose(stdout);
    return;
}
signed main() {
    for (int i = 1; i <= 10; ++ i) test(i);
    return 0;
}