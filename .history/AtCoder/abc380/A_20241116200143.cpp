#pragma GCC optimize(1)
#pragma GCC optimize(2)
#pragma GCC optimize(3, "Ofast", "inline")
#include <bits/stdc++.h>
#define int long long
using namespace std;
constexpr int INF = 0x7fffffff;
void solve() {
    string s; cin >> s;
    int a[4] = {0, 0, 0, 0};
    for (auto ch : s) {
        if (ch == '1') a[1] ++;
        if (ch == '2') a[2] ++;
        if (ch == '3') a[3] ++;
    }
    cout << (a[1] == 1 && a[2] == 2 && a[3] == 3 ? "Yes\n" : "No\n");
    return;
}
signed main() {
    cin.tie(0) -> sync_with_stdio(0);
    int _ = 1; //cin >> _;
    while(_ --) solve();
    return 0;
}