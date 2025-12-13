#pragma GCC optimize(3, "Ofast", "inline")
#include <bits/stdc++.h>
#define int long long
using namespace std;
constexpr int INF = 0x7fffffff;
void solve() {
    int n, q; cin >> n >> q;
    vector<int> a(n + 1);
    for (int i = 1; i <= n; ++ i) cin >> a[i];
    for (int i = 1; i <= n; ++ i) a.emplace_back(a[i]);
    vector<int> p(2 * n + 1, 0);
    for (int i = 1; i <= 2 * n; ++ i) p[i] = p[i - 1] + a[i];
    int d{};
    while (q --) {
        int op; cin >> op;
        if (op == 1) {
            int c; cin >> c; c %= n;
            d = (d + c) % n;
        } else {
            int l, r; cin >> l >> r;
            l += d; r += d;
            cout << p[r] - p[l - 1] << "\n";
        }
    }
    return;
}
void test(int testcase) {
    string inf = to_string(testcase) + ".in";
    string outf = to_string(testcase) + ".out";
    freopen(inf.c_str(), "r", stdin);
    freopen(outf.c_str(), "w", stdout);
    int _ = 1; /cin >> _;
    while(_ --) solve();
    fclose(stdin);
    fclose(stdout);
    return;
}
signed main() {
    for (int i = 1; i <= 10; ++ i) test(i);
    return 0;
}