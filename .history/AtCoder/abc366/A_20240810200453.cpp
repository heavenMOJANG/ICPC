#pragma GCC optimize(1)
#pragma GCC optimize(2)
#pragma GCC optimize(3,"Ofast","inline")
#include<bits/stdc++.h>
#define int long long
using namespace std;
constexpr int INF = 0x7fffffff;
void solve() {
    int n, t, a; cin >> n >> t >> a;
    if (t > a) {
        if (a + n > t) cout << "No\n";
        else cout << "Yes\n";
    }
    if (t == a) cout << "No\n";
    if (t < a) {
        if (t + n > a) cout << "No\n";
        else cout << "Yes\n";
    }
}
signed main() {
    cin.tie(0) -> sync_with_stdio(0);
    int _ = 1; //cin >> _;
    while(_ --) solve();
    return 0;
}