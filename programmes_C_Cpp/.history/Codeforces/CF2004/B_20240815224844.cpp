#pragma GCC optimize(1)
#pragma GCC optimize(2)
#pragma GCC optimize(3,"Ofast","inline")
#include<bits/stdc++.h>
#define int long long
using namespace std;
constexpr int INF = 0x7fffffff;
void solve() {
    int l, r, L, R; cin >> l >> r >> L >> R;
    vector<int> a(101, 0);
    for (int i = l; i <= r; ++ i) a[i] ++;
    for (int i = L; i <= R; ++ i) a[i] ++;
    int cnt = 0;
    for (int i = 1; i <= 100; ++ i) if (a[i] == 2) cnt ++;
    if (!cnt) {cout << "1\n"; return;}
    for (int i = 1; i <= 100; ++ i)
        if (a[i] == 2) {
            if (i != 1 && a[i - 1]) cnt ++;
            break;
        }
    for (int i = 100; i >= 1; -- i)
        if (a[i] == 2) {
            if (i != 100 && a[i + 1]) cnt ++;
        }
    cout << cnt - 1 << "\n";
}
signed main() {
    cin.tie(0) -> sync_with_stdio(0);
    int _ = 1; cin >> _;
    while(_ --) solve();
    return 0;
}