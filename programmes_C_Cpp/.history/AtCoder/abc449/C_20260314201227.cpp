#pragma GCC optimize(3, "Ofast", "inline")
#include <bits/stdc++.h>
#define int long long
using namespace std;
constexpr int INF = 0x7fffffff;
void solve() {
    int N, L, R; cin >> N >> L >> R;
    string S; cin >> S;
    vector<int> pos[26];
    for (int i{}; i < N; ++ i) pos[S[i] - 'a'].emplace_back(i);
    int ans{};
    for (int c{}; c < 26; ++ c) {
        auto v = pos[c];
        int pl{}, pr{};
        for (int r{}; r < v.size(); ++ r) {
            while (pr < r && v[r] - v[pr] > R) pr ++;
            while (pl < r && v[r] - v[pl] >= L) pl ++;
            ans += pl - pr;
        }
    }
    cout << ans << "\n";
    return;
}
signed main() {
    cin.tie(nullptr) -> sync_with_stdio(false);
    int _ = 1; //cin >> _;
    while(_ --) solve();
    return 0;
}