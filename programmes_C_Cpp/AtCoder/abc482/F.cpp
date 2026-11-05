#pragma GCC optimize(3, "Ofast", "inline")
#include <bits/stdc++.h>
#define int long long
using namespace std;
constexpr int INF = 0x7fffffff;
void solve() {
    int N, M; cin >> N >> M;
    if (M == 1) { cout << "1\n"; return; }
    vector<int> fac;
    for (int i{2}; i <= N / i; ++ i)
        while (N % i == 0) {
            if (i % M != 1) fac.emplace_back(i % M);
            N /= i;
        }
    if (N > 1 && N % M != 1) fac.emplace_back(N % M);
    int K{(int)fac.size()};
    if (!K) {
        for (int i : views::iota(0, M)) cout << (i == 1 ? 1ll : -1ll) << "\n";
        return;
    }
    vector<int> dis(K * M, LLONG_MAX);
    vector<bool> vis(K * M);
    deque<int> dq; dq.push_back(1);
    dis[1] = 0;
    while (!dq.empty()) {
        int u{dq.front()}; dq.pop_front();
        if (vis[u]) continue;
        vis[u] = true;
        int j{u / M}, r{u % M};
        int w{j == K - 1}, b{(j + 1) % K * M};
        for (int v : {
            b + r,
            b + r * fac[j] % M
        }) {
            if (dis[v] <= dis[u] + w) continue;
            dis[v] = dis[u] + w;
            if (w) dq.push_back(v);
            else dq.emplace_front(v);
        }
    }
    for (int i : views::iota(0, M)) cout << (dis[i] == LLONG_MAX ? -1ll : max(1ll, dis[i])) << "\n";
    return;
}
signed main() {
    cin.tie(nullptr) -> sync_with_stdio(false);
    int _ = 1; //cin >> _;
    while(_ --) solve();
    return 0;
}