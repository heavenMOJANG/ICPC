#pragma GCC optimize(3, "Ofast", "inline")
#include <bits/stdc++.h>
#define int long long
using namespace std;
constexpr int INF = 0x7fffffff;
void solve() {
    int a, b, c; cin >> a >> b >> c;
    if (a + b > c && a + c > b && b + c > a && (a == b || b == c || a == c)) cout << "Yes\n";
    else cout << "No\n";
    return;
}
signed main() {
    cin.tie(nullptr) -> sync_with_stdio(false);
    int _ = 1; //cin >> _;
    while(_ --) solve();
    return 0;
}