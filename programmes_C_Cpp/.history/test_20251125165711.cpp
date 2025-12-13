#pragma GCC optimize(3, "Ofast", "inline")
#include <bits/stdc++.h>
#define int long long
using namespace std;
constexpr int INF = 0x7fffffff;
constexpr int N = 2e5 + 10;
void solve() {
    int n; cin >> n;
    vector<int> a(n + 1);
    for (int i = 1; i <= n; ++ i) cin >> a[i];
    vector<int> pre(n + 1, 0);
    for (int i = 1; i <= n; ++ i) pre[i] = (pre[i - 1] + a[i]) % 3;
    int ok{};
    for (int l = 1; l <= n - 2 && !ok; ++ l)
        for (int r = l + 1; r <= n - 1 && !ok; ++ r) {
            int s1 = pre[l], s2 = (pre[r] - pre[l] + 3) % 3, s3 = (pre[n] - pre[r] + 3) % 3;
            if (s1 == s2 && s2 == s3) {
                cout << l << " " << r << "\n";
                ok = 1;
            } else {
                if (s1 != s2 && s1 != s3 && s2 != s3) {
                    cout << l << " " << r << "\n";
                    ok = 1;
                }
            }
        }
    if (!ok) cout << "0 0\n";
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