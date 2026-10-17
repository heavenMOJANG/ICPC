#pragma GCC optimize(3, "Ofast", "inline")
#include <bits/stdc++.h>
#define int long long
using namespace std;
constexpr int INF = 0x7fffffff;
constexpr int dx[8] = {-1, -1, -1, 0, 0, 1, 1, 1};
constexpr int dy[8] = {-1, 0, 1, -1, 1, -1, 0, 1};
void solve() {
    int H, W; cin >> H >> W;
    vector<string> S(H);
    int fb{}, fw{};
    for (int i{}; i < H; ++ i) {
        cin >> S[i];
        for (int j{}; j < W; ++ j)
            if (S[i][j] == '#') fb = 1;
            else fw = 1;
    }
    if (!fb || !fw) {
        for (int i{}; i < H; ++ i) cout << string(W, '.') << "\n";
        return;
    }
    vector<int> D(H * W, -1);
    queue<int> Q;
    auto get = [&](int x, int y) -> int { return x * W + y; };
    for (int i{}; i < H; ++ i)
        for (int j{}; j < W; ++ j) {
            fb = 0, fw = 0;
            for (int ii{-1}; ii <= 1; ++ ii)
                for (int jj{-1}; jj <= 1; ++ jj) {
                    int ni = i + ii, ny = j + jj;
                    if (0 <= ni && ni < H && 0 <= ny && ny < W) {
                        if (S[ni][ny] == '#') fb = 1;
                        else fw = 1;
                    }
                }
            if (fb && fw) {
                D[get(i, j)] = 0;
                Q.push(get(i, j));
            }   
        }
    while (!Q.empty()) {
        int u = Q.front(); Q.pop();
        int x = u / W, y = u % W;
        for (int i{}; i < 8; ++ i) {
            int nx = x + dx[i], ny = y + dy[i];
            if (0 <= nx && nx < H && 0 <= ny && ny < W) {
                int v = get(nx, ny);
                if (D[v] == -1) {
                    D[v] = D[u] + 1;
                    Q.push(v);
                }
            }
        }
    }
    for (int i{}; i < H; ++ i) {
        string ans{};
        for (int j{}; j < W; ++ j) {
            int r = D[get(i, j)];
            if (r & 1) ans += (S[i][j] == '#' ? '.' : '#');
            else ans += S[i][j];
        }
        cout << ans << "\n";
    }
    return;
}
signed main() {
    cin.tie(nullptr) -> sync_with_stdio(false);
    int _ = 1; //cin >> _;
    while(_ --) solve();
    return 0;
}
