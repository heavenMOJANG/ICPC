#pragma GCC optimize(3, "Ofast", "inline")
#include <bits/stdc++.h>
#define int long long
using namespace std;
constexpr int INF = 0x7fffffff;
void solve() {
    int N, M; cin >> N >> M;
    vector<set<int>> B(M + 1);
    for (int i{}; i < N; ++ i) {
        int C, S; cin >> C >> S;
        B[C].insert(S);
    }
    for (int i{1}; i <= M; ++ i)
        cout << (B[i].empty() ? -1ll : *B[i].rbegin()) << " \n"[i == M];
    return;
}
signed main() {
    cin.tie(nullptr) -> sync_with_stdio(false);
    int _ = 1; //cin >> _;
    while(_ --) solve();
    return 0;
}