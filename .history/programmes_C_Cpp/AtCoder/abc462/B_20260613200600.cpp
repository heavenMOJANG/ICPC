#pragma GCC optimize(3, "Ofast", "inline")
#include <bits/stdc++.h>
#define int long long
using namespace std;
constexpr int INF = 0x7fffffff;
void solve() {
    int N; cin >> N;
    vector<int> ans[N + 1];
    for (int i{1}; i <= N; ++ i) {
        int K; cin >> K;
        for (int j{}; j < K; ++ j) {
            int x; cin >> x;
            ans[x].emplace_back(i);
        }
    }
    for (int i{1}; i <= N; ++ i) {
        cout << ans[i].size();
        for (int x : ans[i]) cout << " " << x;
        cout << "\n";
    }
    return;
}
signed main() {
    cin.tie(nullptr) -> sync_with_stdio(false);
    int _ = 1; //cin >> _;
    while(_ --) solve();
    return 0;
}
