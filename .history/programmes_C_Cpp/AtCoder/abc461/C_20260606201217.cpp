#pragma GCC optimize(3, "Ofast", "inline")
#include <bits/stdc++.h>
#define int long long
using namespace std;
constexpr int INF = 0x7fffffff;
void solve() {
    int N, K, M; cin >> N >> K >> M;
    struct J {int C, V;};
    vector<J> S(N);
    for (int i{}; i < N; ++ i) cin >> S[i].C >> S[i].V;
    ranges::sort(S, ranges::greater{}, &J::V);
    int ans{}, diff{};
    vector<bool> used(N + 1, 0 );
    vector<int> ok;
    for (int i{}; i < K; ++ i) {
        ans += S[i].V;
        if (!used[S[i].C]) used[S[i].C] = 1, diff ++;
        else ok.emplace_back(S[i].V);
    }
    if (diff >= M) { cout << ans << "\n"; return; }
    vector<int> add;
    for (int i = K; i < N; ++ i)
        if (!used[S[i].C]) used[S[i].C] = 1, add.emplace_back(S[i].V);
    int need = M - diff;
    ranges::sort(ok);
    ranges::sort(add, ranges::greater{});
    for (int i{}; i < need; ++ i) ans += add[i] - ok[i];
    cout << ans << "\n";
    return;
}
signed main() {
    cin.tie(nullptr) -> sync_with_stdio(false);
    int _ = 1; //cin >> _;
    while(_ --) solve();
    return 0;
}