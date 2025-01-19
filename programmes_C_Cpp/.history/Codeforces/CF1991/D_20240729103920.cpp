#pragma GCC optimize(1)
#pragma GCC optimize(2)
#pragma GCC optimize(3,"Ofast","inline")
#include<bits/stdc++.h>
#define int long long
using namespace std;
constexpr int inf = 0x7fffffff;
void solve() {
    int n; cin >> n;
    switch (n) {
        case 1 : cout << "1\n1\n"; break;
        case 2 : cout << "2\n1 2\n"; break;
        case 3 : cout << "2\n1 2 2\n"; break;
        case 4 : cout << "3\n1 2 2 3\n"; break;
        case 5 : cout << "3\n1 2 2 3 3\n"; break;
        case 6 : cout << "4\n1 2 2 3 3 4\n"; break;
        default : for (int i = 1; i <= n; ++ i) cout << (i % 4 ? i % 4 : 4) << " \n"[i == n];
    }
    return;
}
signed main() {
    cin.tie(0) -> sync_with_stdio(0);
    int _ = 1; //cin >> _;
    while(_ --) solve();
    return 0;
}