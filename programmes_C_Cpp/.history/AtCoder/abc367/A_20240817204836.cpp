#pragma GCC optimize(1)
#pragma GCC optimize(2)
#pragma GCC optimize(3,"Ofast","inline")
#include<bits/stdc++.h>
#define int long long
using namespace std;
constexpr int INF = 0x7fffffff;
void solve() {
    int a, b, c; cin >> a >> b >> c;
    if (b > c) {
        if (a > b || a < c) cout << "No\n";
        else cout << "Yes\n";
    }
    else {
        if (b < a && a < c) cout << "No\n";
        else cout << "Yes\n";
    }
}
signed main() {
    cin.tie(0) -> sync_with_stdio(0);
    int _ = 1; //cin >> _;
    while(_ --) solve();
    return 0;
}