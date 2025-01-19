#pragma GCC optimize(1)
#pragma GCC optimize(2)
#pragma GCC optimize(3,"Ofast","inline")
#include<bits/stdc++.h>
#define int long long
using namespace std;
constexpr int INF = 0x7fffffff;
void solve() {
    int l, r, L, R; cin >> l >> r >> L >> R;
    vecotr<int> a(101, 0);
    for (int i = l; i <= r; ++ i) a[i] ++;
    for (int i = L; i <= R; ++ i) a[i] ++;
    

}
signed main() {
    cin.tie(0) -> sync_with_stdio(0);
    int _ = 1; //cin >> _;
    while(_ --) solve();
    return 0;
}