#pragma GCC optimize(3, "Ofast", "inline")
#include <bits/stdc++.h>
#define int long long
using namespace std;
constexpr int INF = 0x7fffffff;
void solve() {
    int N, K, M; cin >> N >> K >> M;
    struct S {int C, V;};
    vector<S> J(N);
    for (int i{}; i < N; ++ i) cin >> J[i].C >> J[i].V;
    ranges::sort(J, ranges::greater{}, &S::V);
    int ans{}, diff{};
    vector<int> used(N + 1, 0 ), ok;
    for (int i{}; i < K; ++ i) {
        ans += J[i].V;
        if (!used[J[i].C]) used[J[i].C] = 1, diff ++;
        else ok.emplace_back(J[i].V);
    }
    if (diff >= M) { cout << ans << "\n"; return; }
    vector<int> add;
    for (int i = K; i < N; ++ i)
        if (!used[J[i].C]) used[J[i].C] = 1, add.emplace_back(J[i].V);
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