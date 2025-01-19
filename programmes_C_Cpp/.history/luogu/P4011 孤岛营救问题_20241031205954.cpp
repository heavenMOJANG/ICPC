#pragma GCC optimize(1)
#pragma GCC optimize(2)
#pragma GCC optimize(3, "Ofast", "inline")
#include <bits/stdc++.h>
#define int long long
using namespace std;
constexpr int INF = 0x7fffffff;
constexpr int N = 20;
constexpr int dx[] = {-1, 0, 1, 0};
constexpr int dy[] = {0, 1, 0, -1};
struct Node {
    int x, y, step, sts;
    Node(int _x, int _y, int _step, int _sts) : x(_x), y(_y), step(_step), sts(_sts) {}
};
int n, m, p, k, s;
int g[N][N][N][N], vis[N][N][1ll << N], keyNum[N][N], key[N][N][N];
queue<Node> q;
int getKeyStatus(int x, int y) {
    int res{};
    for (int i = 1; i <= keyNum[x][y]; ++ i) {
        res |= 1ll << key[x][y][i] - 1;
    }
    return res;
}
void bfs() {
    vis[1][1][getKeyStatus(1, 1)] = 1;
    q.push({1, 1, getKeyStatus(1, 1), 0});
}
signed main() {
    cin.tie(0) -> sync_with_stdio(0);
    cin >> n >> m >> p >> k;
    for (int i = 1; i <= k; ++ i) {
        int Xi, Yi, Xj, Yj, G; cin >> Xi >> Yi >> Xj >> Yj >> G;
        if (!G) g[Xi][Yi][Xj][Yj] = g[Xj][Yj][Xi][Yi] = -1;
        else g[Xi][Yi][Xj][Yj] = g[Xj][Yj][Xi][Yi] = G;
    }
    cin >> s;
    for (int i = 1; i <= s; ++ i) {
        int Xi, Yi, Qi; cin >> Xi >> Yi >> Qi;
        key[Xi][Yi][++ keyNum[Xi][Yi]] = Qi;
    }
    return 0;
}