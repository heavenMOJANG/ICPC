#pragma GCC optimize(3, "Ofast", "inline")
#include <bits/stdc++.h>
#include <atcoder/maxflow.hpp>
#define int long long
using namespace std;
using namespace atcoder;
constexpr int INF = 0x7fffffff;
void solve() {
    int N, M; cin >> N >> M;
    vector<string> S(N);
    for (auto && s : S) cin >> s;
    int s{N * M}, t{N * M + 1};
    mf_graph<int> G(N * M + 2);
    auto id = [&](int x, int y) { return x * M + y; };
    int ans{};
    for (int i : views::iota(0, N))
        for (int j : views::iota(0, M)) {
            if (S[i][j] == '#') continue;
            int p{id(i, j)};
            if (S[i][j] == '+') G.add_edge(s, p, 1), ans ++;
            else G.add_edge(p, t, 1);
        }
    for (int i : views::iota(0, N))
        for (int j : views::iota(0, M)) {
            if (S[i][j] == '#') continue;
            int p{id(i, j)};
            if (j + 1 < M && S[i][j + 1] != '#') {
                int q{id(i, j + 1)};
                G.add_edge(p, q, INF);
                G.add_edge(q, p, INF);
            }
            if (i + 1 < N && S[i + 1][j] != '#') {
                int q{id(i + 1, j)};
                G.add_edge(q, p, INF);
            }
        }
    cout << ans - G.flow(s, t) << "\n";
    return;
}
signed main() {
    cin.tie(nullptr) -> sync_with_stdio(false);
    int _ = 1; //cin >> _;
    while(_ --) solve();
    return 0;
}