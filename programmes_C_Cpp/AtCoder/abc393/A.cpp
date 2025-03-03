#pragma GCC optimize(1)
#pragma GCC optimize(2)
#pragma GCC optimize(3, "Ofast", "inline")
#include <bits/stdc++.h>
#define int long long
using namespace std;
constexpr int INF = 0x7fffffff;
void solve() {
    string a, b; cin >> a >> b;
    int f1 = a == "sick", f2 = b == "sick";
    if (f1 && f2) cout << "1\n";
    if (f1 && !f2) cout << "2\n";
    if (!f1 && f2) cout << "3\n";
    if (!f1 && !f2) cout << "4\n";
    return;
}
signed main() {
    cin.tie(0) -> sync_with_stdio(0);
    int _ = 1; //cin >> _;
    while(_ --) solve();
    return 0;
}