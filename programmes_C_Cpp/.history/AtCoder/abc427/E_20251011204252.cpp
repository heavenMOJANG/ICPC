#pragma GCC optimize(3, "Ofast", "inline")
#include <bits/stdc++.h>
#define int long long
using namespace std;
constexpr int INF = 0x7fffffff;
constexpr int dx[] = {-1, 1, 0, 0};
constexpr int dy[] = {0, 0, -1, 1};
struct Hash {
    size_t operator() (const bitset<144>& b) const noexcept {
        const uint64_t* p = reinterpret_cast<const uint64_t*> (&b);
        return hash<uint64_t>{}(p[0]) ^ (hash<uint64_t>{}(p[1]) << 1);
    }
};
void solve() {
    int n, m; cin >> n >> m;
    vector<string> g(n);
    for (auto && x : g) cin >> x;
    bitset<144> s;
    int si = -1, sj = -1;
    for (int i{}; i < n; ++ i)
        for (int j{}; j < m; ++ j) {
            if (g[i][j] == '#') s[i * m + j] = 1;
            else if (g[i][j] == 'T') si = i, sj = j;
        }
    queue<bitset<144>> q;
    unordered_map<bitset<144>, int, Hash> mp;
    q.push(s); mp[s] = 0;
    while (!q.empty()) {
        auto u = q.front(); q.pop();
        int d = mp[u];
        for (int k{}; k < 4; ++ k) {
            bitset<144> v;
            int ok = 1;
            for (int i{}; i < n; ++ i) {
                for (int j{}; j < m; ++ j) {
                    int p = i * m + j;
                    if (!u[p]) continue;
                    int ni = i + dx[k], nj = j + dy[k];
                    if (ni < 0 || ni >= n || nj < 0 || nj >= m) continue;
                    if (ni == si && nj == sj) { ok = 0; break; }
                    v[ni * m + nj] = 1;
                }
               if (!ok) break;
            }
            if (!ok) continue;
            if (v.none()) { cout << d + 1 << "\n"; return; }
            if (!mp.count(v)) { mp[v] = d + 1; q.push(v); }
        }
    }
    cout << "-1\n";
    return;
}
signed main() {
    cin.tie(nullptr) -> sync_with_stdio(false);
    int _ = 1; //cin >> _;
    while(_ --) solve();
    return 0;
}