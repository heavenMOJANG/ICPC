#pragma GCC optimize(3, "Ofast", "inline")
#include <bits/stdc++.h>
#define int long long
using namespace std;
constexpr int INF = 0x7fffffff;
constexpr int N = 2e5 + 10;
void solve() {
    int n, c; cin >> n >> c;
    vector<int> a;
    int ans{};
    for (int i{}; i < n; ++ i) {
        int x; cin >> x;
        if (x > c) ans ++;
        else a.emplace_back(x);
    }
    n = a.size();
    sort(a.begin(), a.end());
    for (int i = n - 1; ~i; -- i) {
        if (a[i] > c) ans ++;
        else for (int j = i - 1; ~j; -- j) a[j] *= 2;
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