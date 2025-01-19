#pragma GCC optimize(1)
#pragma GCC optimize(2)
#pragma GCC optimize(3,"Ofast","inline")
#include<bits/stdc++.h>
#define int long long
using namespace std;
constexpr int INF = 0x7fffffff;
constexpr int N = 1e6 + 10;
void solve() {
    int q; cin >> q;
    int cnt = 0;
    vector<int> a(N, 0);
    while (q --) {
        int op, x; cin >> op;
        if (op == 1) {
            cin >> x;
            a[x] ++;
            if (a[x] == 1) cnt ++;
        }
        if (op == 2) {
            cin >> x;
            a[x] --;
            if (a[x] == 0) cnt --;
        }
        if (op == 3) cout << cnt << "\n";
    }
}
signed main() {
    cin.tie(0) -> sync_with_stdio(0);
    int _ = 1; //cin >> _;
    while(_ --) solve();
    return 0;
}