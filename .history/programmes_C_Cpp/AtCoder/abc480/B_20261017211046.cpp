#pragma GCC optimize(3, "Ofast", "inline")
#include <bits/stdc++.h>
#define int long long
using namespace std;
constexpr int INF = 0x7fffffff;
void solve() {
    int N, M; cin >> N >> M;
    vector<string> S(N);
    vector<int> ans(N);
    for (auto && s : S) cin >> s;
    while (M --) {
        string T; cin >> T;
        int best{2}, idx{-1}, cnt{};
        for (int i : views::iota(0, N)) {
            if (S[i].size() != T.size()) continue;
            int d{};
            for (int j : views::iota(0, (int)T.size())) d += S[i][j] != T[j];
            if (d < best) best = d, idx = i, cnt = 1;
            else if (d == best) cnt++;
        }
        if (best <= 1 && cnt == 1) ans[idx] ++;
    }
    for (int i : views::iota(0, N)) cout << ans[i] << "\n";
    return;
}
signed main() {
    cin.tie(nullptr) -> sync_with_stdio(false);
    int _ = 1; //cin >> _;
    while(_ --) solve();
    return 0;
}