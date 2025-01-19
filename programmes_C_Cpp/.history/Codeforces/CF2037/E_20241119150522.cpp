#pragma GCC optimize(1)
#pragma GCC optimize(2)
#pragma GCC optimize(3, "Ofast", "inline")
#include <bits/stdc++.h>
#define int long long
using namespace std;
constexpr int INF = 0x7fffffff;
int ask(int l, int r) {
    cout << "? " << l << " " << r << endl;
    int res{}; cin >> res;
    return res;
}
void solve() {
    int n; cin >> n;
    int p{}, cur{}, k{};
    string s(n, ' ');
    for (int i = 2; i <= n; ++ i) {
        int t = ask(1, i);
        if (t > cur) {
            s[i - 1] = '1';
            if (!p) p = i, k = t;
        } else s[i - 1] = '0';
        cur = t;
    }
    if (!p) { cout << "! IMPOSSIBLE" << endl; return; }
    return;
}
signed main() {
    cin.tie(0) -> sync_with_stdio(0);
    int _ = 1; //cin >> _;
    while(_ --) solve();
    return 0;
}