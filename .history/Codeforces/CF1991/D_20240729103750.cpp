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
        case 4 :
        case 5 :
        case 6 :
        default : 
    }
    return;
}
signed main() {
    cin.tie(0) -> sync_with_stdio(0);
    int _ = 1; //cin >> _;
    while(_ --) solve();
    return 0;
}