#pragma GCC optimize(1)
#pragma GCC optimize(2)
#pragma GCC optimize(3,"Ofast","inline")
#include<bits/stdc++.h>
#define int long long
using namespace std;
constexpr int INF = 0x7fffffff;
void solve() {
    int l = 2, r = 999;
    int cnt = 7;
    while (cnt --) {
        int lmid = l + (r - l) / 3;
        int rmid = r - (r - l) / 3;
        cout << "? " << lmid << " " << rmid << endl;
        int s; cin >> s;
        if (s == lmid * (mid + 1)) l = mid + 1;
        else if (s == mid * (mid + 2)) {cout << "! " << mid + 1 << endl; return;}
        else r = mid;
    }
    return;
}
signed main() {
    cin.tie(0) -> sync_with_stdio(0);
    int _ = 1; cin >> _;
    while(_ --) solve();
    return 0;
}