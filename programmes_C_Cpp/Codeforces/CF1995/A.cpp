#pragma GCC optimize(1)
#pragma GCC optimize(2)
#pragma GCC optimize(3,"Ofast","inline")
#include<bits/stdc++.h>
#define int long long
using namespace std;
constexpr int inf = 0x7fffffff;
void solve() {
    int n, k; cin >> n >> k;
    int ans = 0;
    if (k == 0){cout << "0\n"; return;}
    vector<int> pre;
    pre.emplace_back(0);
    pre.emplace_back(n);
    for (int i = n - 1; i > 0; -- i) {
        pre.emplace_back(i);
        pre.emplace_back(i);
    }
    for (int i = 1; i < pre.size(); ++ i) {
        pre[i] += pre[i - 1];
        if (pre[i - 1] < k && k <= pre[i]) {
            cout << i << "\n";
            return;
        }
    }
    return;
}
signed main() {
    cin.tie(0) -> sync_with_stdio(0);
    int _ = 1; cin >> _;
    while(_ --) solve();
    return 0;
}