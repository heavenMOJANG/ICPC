#include <bits/stdc++.h>
using namespace std;

struct StateHash {
    size_t operator()(const bitset<144>& b) const noexcept {
        // 把 bitset 拆成若干 64 位块进行哈希
        const uint64_t* p = reinterpret_cast<const uint64_t*>(&b);
        return std::hash<uint64_t>{}(p[0]) ^ (std::hash<uint64_t>{}(p[1]) << 1);
    }
};

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int H, W;
    cin >> H >> W;
    vector<string> S(H);
    for (int i = 0; i < H; ++i) cin >> S[i];

    int Tr = -1, Tc = -1;
    bitset<144> start;
    for (int r = 0; r < H; ++r) {
        for (int c = 0; c < W; ++c) {
            char ch = S[r][c];
            if (ch == '#') start.set(r * W + c);
            else if (ch == 'T') Tr = r, Tc = c;
        }
    }

    // 四个方向：上、下、左、右
    const int dr[4] = {-1, 1, 0, 0};
    const int dc[4] = {0, 0, -1, 1};

    queue<bitset<144>> q;
    unordered_map<bitset<144>, int, StateHash> dist;

    q.push(start);
    dist[start] = 0;

    while (!q.empty()) {
        auto cur = q.front(); q.pop();
        int d = dist[cur];

        for (int k = 0; k < 4; ++k) {
            bitset<144> nxt;
            bool invalid = false;

            for (int r = 0; r < H; ++r) {
                for (int c = 0; c < W; ++c) {
                    int id = r * W + c;
                    if (!cur[id]) continue;
                    int nr = r + dr[k];
                    int nc = c + dc[k];
                    // 垃圾飞出边界 -> 消失
                    if (nr < 0 || nr >= H || nc < 0 || nc >= W) continue;
                    // 如果移动到 T 的位置 -> 脏了
                    if (nr == Tr && nc == Tc) {
                        invalid = true;
                        break;
                    }
                    nxt.set(nr * W + nc);
                }
                if (invalid) break;
            }

            if (invalid) continue;
            if (nxt.none()) {
                cout << d + 1 << "\n";
                return 0;
            }
            if (!dist.count(nxt)) {
                dist[nxt] = d + 1;
                q.push(nxt);
            }
        }
    }

    cout << -1 << "\n";
    return 0;
}
