#pragma GCC optimize(3, "Ofast", "inline")
#include <bits/stdc++.h>
#define int long long
using namespace std;
constexpr int INF = 0x7fffffff;
void solve() {
    string S, T; cin >> S >> T;
    int N = S.size(), M = T.size();
    vector nxt(N + 1, vector<int> (26, N));
    for (int i = N - 1; ~i; -- i) {
        for (int c{}; c < 26; ++ c) nxt[i][c] = nxt[i + 1][c];
        nxt[i][S[i] - 'a'] = i;
    }
    int ans{};
    for (int i{}; i < N; ++ i) {
        int cur = i, ok = 1;
        for (int j{}; j < M; ++ j) {
            cur = nxt[cur][T[j] - 'a'];
            if (cur == N) { ok = 0; break; }
            cur ++;
        }
        if (ok) ans += cur - 1 - i;
        else ans += N - i;
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
