#pragma GCC optimize(3, "Ofast", "inline")
#include <bits/stdc++.h>
#define int long long
using namespace std;
constexpr int INF = 0x7fffffff;
const int N = 2e5 + 10;
void init_lca() {
    
}
int 
int get_dist(int u, int v) {
    return dep[u] + dep[v] - 2 * dep[get_lca(u, v)];
}
bool on_path(int u, int v, int x) {
    return get_dist(u, v) == get_dist(u, x) + get_dist(x, v);
}

int jump(int u, int anc) {
    int target_depth = dep[anc] + 1;
    for (int j = 20 - 1; j >= 0; j--) {
        if (fa[u][j] != -1 && dep[fa[u][j]] >= target_depth) {
            u = fa[u][j];
        }
    }
    return u;
}
void solve() {
    int n; cin >> n;
    vector<int> g[n], dep(n), sz(n);
    vector fa(n, vector<int>(20, -1));
    function<void(int, int, int)> dfs = [&](int u, int p, int d) {
        dep[u] = d;
        fa[u][0] = p;
        sz[u] = 1;
        for (int v : g[u]) {
            if (v != p) {
                dfs(v, u, d + 1);
                sz[u] += sz[v];
            }
        }
    };
    for (int j = 1; j < 20; ++ j)
        for (int i{}; i < n; ++ i) {
            if (fa[i][j - 1] != -1) fa[i][j] = fa[fa[i][j - 1]][j - 1];
            else fa[i][j] = -1;
        }
    auto lca = [&](int u, int v) {
        if (dep[u] < dep[v]) swap(u, v);
        for (int j = 19; ~j; -- j) {
            if (fa[u][j] != -1 && dep[fa[u][j]] >= dep[v]) u = fa[u][j];
        }
        if (u == v) return u;
        for (int j = 19; ~j; -- j)
            if (fa[u][j] != fa[v][j]) u = fa[u][j], v = fa[v][j];
        return fa[u][0];
    };
}
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    if (!(cin >> N)) return 0;

    for (int i = 0; i < N - 1; i++) {
        int u, v;
        cin >> u >> v;
        g[u].push_back(v);
        g[v].push_back(u);
    }
    dfs(0, -1, 0);
    init_lca();

    long long ans = 0;
    int u = 0, v = 0;
    for (int x = 1; x <= N; x++) {
        long long count = 0;
        int lca = get_lca(u, v);
        
        if (u == v) {
            long long bad_paths = 0;
            for(int child : g[0]) {
                long long s = sz[child];
                bad_paths += s * (s + 1) / 2;
            }
            long long total_paths = (long long)N * (N + 1) / 2;
            count = total_paths - bad_paths;
        } else {
            int sz_u = sz[u];
            int sz_v = sz[v];
            if (lca == u) {
                int child = jump(v, u);
                sz_u = N - sz[child];
            }
            else if (lca == v) {
                int child = jump(u, v);
                sz_v = N - sz[child];
            }
            count = (long long)sz_u * sz_v;
        }
        ans += count;
        if (x == N) break;
        if (on_path(u, v, x)) {
            continue;
        }

        if (on_path(x, v, u)) {
            u = x;
        }
        else if (on_path(u, x, v)) {
            v = x;
        }
        else {
            break;
        }
    }

    cout << ans << endl;

    return 0;
}
