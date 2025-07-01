#pragma GCC optimize(3, "Ofast", "inline")
#include <bits/stdc++.h>
#include <atcoder/mincostflow>
#define int long long
using namespace std;
constexpr int INF = 0x7fffffff;
constexpr int N = 2e12;
void solve() {
    int h, w; cin >> h >> w;
    vector a(h, vector<int> (w));
    for (auto && row : a)
        for (auto && x : row) cin >> x;
    atcoder::mcf_graph<int, int> g(h * w + 2);
    for (int i{}; i < h; ++ i)
        for (int j{}; j < w - 1; ++ j)
            if (a[i][j] + a[i][j + 1] < 0)
                g.add_edge(1 + i * w + j + ((i ^ j) & 1), 1 + i * w + j + !((i ^ j) & 1), 1, a[i][j] + a[i][j + 1] + N);
    for (int i{}; i < h - 1; ++ i)
        for (int j{}; j < w; ++ j)
            if (a[i][j] + a[i + 1][j] < 0)
                g.add_edge(1 + (i + ((i ^ j) & 1)) * w + j, 1 + (i + !((i ^ j) & 1)) * w + j, 1, a[i][j] + a[i + 1][j] + N);
    for (int i{}; i < h; ++ i)
        for (int j{}; j < w; ++ j)
            if ((i ^ j) & 1) g.add_edge(1 + i * w + j, 1 + h * w, 1, 0);
            else g.add_edge(0, 1 + i * w + j, 1, 0);
    int ans{};
    for (const auto& [flow, cost] : g.slope(0, 1 + h * w)) ans = min(ans, cost - flow * N);
    cout << transform_reduce(begin(a), end(a), -ans, plus{}, [](const auto& row) {
        return reduce(begin(row), end(row));
    }) << "\n";
    return;
}
signed main() {
    cin.tie(0) -> sync_with_stdio(0);
    int _ = 1; //cin >> _;
    while(_ --) solve();
    return 0;
}