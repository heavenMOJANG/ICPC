#pragma GCC optimize(3, "Ofast", "inline")
#include <bits/stdc++.h>
#define int long long
using namespace std;
constexpr int INF = 0x7fffffff;
void solve() {
    int N, M; cin >> N >> M;
    vector<int> cnt(N + 1, 0);
    int d{};
    auto add = [&](int c) -> void {
        if (!cnt[c]) d ++;
        cnt[c] ++;
    };
    auto del = [&](int c) -> void {
        cnt[c] --;
        if (!cnt[c]) d --;
    };
    struct Node { int from, to; };
    vector<vector<Node>> T(M + 1);
    for (int i{}; i < N; ++ i) {
        int A, D, B; cin >> A >> D >> B;
        if (D == 1) add(B);
        else {
            add(A);
            if (A != B) T[D].emplace_back(A, B);
        }
    }
    for (int i{1}; i <= M; ++ i) {
        for (const auto& [A, B] : T[i]) del(A), add(B);
        cout << d << "\n";
    }
    return;
}
signed main() {
    cin.tie(nullptr) -> sync_with_stdio(false);
    int _ = 1; //cin >> _;
    while(_ --) solve();
    return 0;
}