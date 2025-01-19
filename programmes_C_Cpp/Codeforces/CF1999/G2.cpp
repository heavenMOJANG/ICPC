#pragma GCC optimize(1)
#pragma GCC optimize(2)
#pragma GCC optimize(3,"Ofast","inline")
#include<bits/stdc++.h>
#define int long long
using namespace std;
constexpr int INF = 0x7fffffff;
void solve() {
    int l = 2, r = 999;
    while (l < r) {
        int lmid = l + (r - l) / 3;
        int rmid = r - (r - l) / 3;
        cout << "? " << lmid << " " << rmid << endl;
        int s; cin >> s;
        if (s == lmid * rmid) l = rmid + 1;
        else if (s == lmid * (rmid + 1)) l = lmid + 1, r = rmid;
        else r = lmid;
    }
    cout << "! " << l << "\n";
    return;
}
signed main() {
    cin.tie(0) -> sync_with_stdio(0);
    int _ = 1; cin >> _;
    while(_ --) solve();
    return 0;
}