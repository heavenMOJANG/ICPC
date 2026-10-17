#pragma GCC optimize(3, "Ofast", "inline")
#include <bits/stdc++.h>
#define int long long
using namespace std;
constexpr int INF = 0x7fffffff;
void solve() {
    int N; cin >> N;
    int ans{}, r{1};
    for (int i{1}; i < N; ++ i) {
        r = max(r, i);
        while (r < N) {
            cout << "? " << i << " " << r + 1 << endl;
            string ask; cin >> ask;
            if (ask == "Yes") r ++;
            else break;
        }
        ans += r - i;
    }
    cout << "! " << ans << endl;
    return;
}
signed main() {
    cin.tie(nullptr) -> sync_with_stdio(false);
    int _ = 1; //cin >> _;
    while(_ --) solve();
    return 0;
}