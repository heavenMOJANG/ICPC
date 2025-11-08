#pragma GCC optimize(3, "Ofast", "inline")
#include <bits/stdc++.h>
#define int long long
using namespace std;
constexpr int INF = 0x7fffffff;
struct S { int x, y, d; };
void solve() {
    int h, w; cin >> h >> w;
    vector<string> g(h);
    for (auto && x : g) cin >> x;
    vector<vector<int>> go = {{0, 1, 2, 3}, {3, 2, 1, 0}, {1, 0, 3, 2}};
    vector<int> dis(4 * h * w, INF);
    auto get = [&](int x, int y, int d) { return 4 * x * w + 4 * y + d; };
    deque<S> dq; dq.push_back({0, 0, 1});
    dis[get(0, 0, 1)] = 0;
    int ans = INF;
    while (!dq.empty()) {
        auto [x, y, d] = dq.front(); dq.pop_front();
        int dd = dis[get(x, y, d)];
        if (dd != dis[get(x, y, d)]) continue;
        for (int k{}; k < 3; ++ k) {
            int nxt = go[k][d], w = ((k == 0 && g[x][y] == 'A') || (k == 1 && g[x][y] == 'B') || (k == 2 && g[x][y] == 'C')) ? 0ll : 1ll;
            int nxtd = dd + w;
            int nx = x, ny = y;
            switch (nxt) {
                case 0: nx = x - 1; break;
                case 1: ny = y + 1; break;
                case 2: nx = x + 1; break;
                case 3: ny = y - 1; break;
            }
            if (nx == h - 1 && ny == w) { ans = min(ans, nxtd); continue; }
            int id = get(nx, ny, nxt);
            if (nxtd < dis[id]) {
                dis[id] = nxtd;
                if (!w) dq.push_front({nx, ny, nxt});
                else dq.push_back({nx, ny, nxt});
            }
        }
    }
    cout << (ans == INF ? -1ll : ans) << '\n';
    return;
}
signed main() {
    cin.tie(nullptr) -> sync_with_stdio(false);
    int _ = 1; //cin >> _;
    while(_ --) solve();
    return 0;
}