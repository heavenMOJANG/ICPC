#pragma GCC optimize(3, "Ofast", "inline")
#include <bits/stdc++.h>
#define int long long
using namespace std;
constexpr int INF = 0x7fffffff;
constexpr int N = 2e5 + 10;
void solve() {
    int a, b, x, y; cin >> a >> b >> x >> y;
    if (a == b) { cout << "0\n"; return; }
    if (a > b) {
        if (a - b == 1 && (a & 1)) cout << y << "\n";
        else cout << "-1\n";
        return;
    }
    int d = b - a;
    int da = a & 1 ? a + 1 : a;
    int db = (b - 1) & 1 ? b - 2 : b - 1;
    int q = da > db ? 0ll : (db - da) / 2 + 1;
    cout << q * min(x, y) + (d - q) * x << "\n";
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