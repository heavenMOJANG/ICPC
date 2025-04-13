#pragma GCC optimize(1)
#pragma GCC optimize(2)
#pragma GCC optimize(3, "Ofast", "inline")
#include <bits/stdc++.h>
#define int long long
using namespace std;
constexpr int INF = 0x7fffffff;
void solve() {
    int n; cin >> n;
    vector<int> cnt(14, 0);
    for (int i = 0; i < 7; ++ i) {
        int x; cin >> x;
        cnt[x] ++;
    }
    for (int i = 1; i < 14; ++ i)
        for (int j = 1; j < 14; ++ j) {
            if (i != j && cnt[i] >= 3 && cnt[j] >= 2) { cout << "Yes\n"; return; }
        }
    cout << "No\n";
    return;
}
signed main() {
    cin.tie(0) -> sync_with_stdio(0);
    int _ = 1; //cin >> _;
    while(_ --) solve();
    return 0;
}