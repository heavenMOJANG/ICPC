#pragma GCC optimize(3, "Ofast", "inline")
#include <bits/stdc++.h>
using namespace std;
constexpr int dx[] = {-1, 1, 0, 0};
constexpr int dy[] = {0, 0, -1, 1};
struct SafeHash {
    size_t operator()(const bitset<144>& b) const noexcept {
        // 安全但稍慢：使用 to_string() 的 hash
        // 对 144 位长度固定的小字符串开销可以接受且无 UB。
        static const hash<string> hs;
        return hs(b.to_string());
    }
};

void solve() {
    int n, m; if (!(cin >> n >> m)) return;
    vector<string> g(n);
    for (int i = 0; i < n; ++i) cin >> g[i];

    bitset<144> s;
    int si = -1, sj = -1;
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < m; ++j) {
            if (g[i][j] == '#') s.set(i * m + j);
            else if (g[i][j] == 'T') { si = i; sj = j; }
        }
    }

    if (s.none()) { cout << 0 << "\n"; return; }

    queue<bitset<144>> q;
    unordered_map<bitset<144>, int, SafeHash> mp;
    q.push(s); mp[s] = 0;

    while (!q.empty()) {
        auto u = q.front(); q.pop();
        int d = mp[u];
        for (int k = 0; k < 4; ++k) {
            bitset<144> v;
            bool ok = true;
            for (int i = 0; i < n && ok; ++i) {
                for (int j = 0; j < m; ++j) {
                    int p = i * m + j;
                    if (!u[p]) continue;
                    int ni = i + dx[k], nj = j + dy[k];
                    if (ni < 0 || ni >= n || nj < 0 || nj >= m) continue;
                    if (ni == si && nj == sj) { ok = false; break; }
                    v.set(ni * m + nj);
                }
            }
            if (!ok) continue;
            if (v.none()) { cout << d + 1 << "\n"; return; }
            if (!mp.count(v)) { mp[v] = d + 1; q.push(v); }
        }
    }
    cout << "-1\n";
}
signed main() {
    cin.tie(nullptr) -> sync_with_stdio(false);
    int _ = 1; //cin >> _;
    while(_ --) solve();
    return 0;
}
