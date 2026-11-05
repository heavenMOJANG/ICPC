#pragma GCC optimize(3, "Ofast", "inline")
#include <bits/stdc++.h>
#define int long long
using namespace std;
constexpr int INF = 0x7fffffff;
void solve() {
    int N, M; cin >> N >> M;
    vector<int> fac;
    for (int i{1}; i <= N / i; ++ i)
        if (N % i == 0) {
            fac.emplace_back(i % M);
            if (i != N / i) fac.emplace_back(N / i % M);
        }
    vector<int> dis(M, -1);
    queue<int> q; q.push(1 % M);
    dis[1 % M] = 0;
    while (!q.empty()) {
        int u{q.front()}; q.pop();
        for (int f : fac) {
            int v{u * f % M};
            if (dis[v] != -1) continue;
            dis[v] = dis[u] + 1;
            q.push(v);
        }
    }
    for (int i : views::iota(0, M))
        cout << (dis[i] == -1 ? dis[i] : max(1ll, dis[i])) << "\n";
    return;
}
signed main() {
    cin.tie(nullptr) -> sync_with_stdio(false);
    int _ = 1; //cin >> _;
    while(_ --) solve();
    return 0;
}