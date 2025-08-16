#include <bits/stdc++.h>
using namespace std;
using ll = long long;

static const int MAXN = 1000000 + 5;
int N;
long long K;
vector<pair<int,int>> g[MAXN];
bool vis[MAXN];
int sz[MAXN];
int maxSub[MAXN];
int totalSize;

// 计算子树大小，并找重心
void dfs_size(int u, int p) {
    sz[u] = 1;
    maxSub[u] = 0;
    for (auto &e : g[u]) {
        int v = e.first;
        if (v == p || vis[v]) continue;
        dfs_size(v, u);
        sz[u] += sz[v];
        maxSub[u] = max(maxSub[u], sz[v]);
    }
}
// 找到重心
int get_centroid(int u, int p) {
    dfs_size(u, p);
    totalSize = sz[u];
    int best = u, par = p;
    // 二次 DFS：在子树里找最大子树 ≤ 总尺寸/2
    function<void(int,int)> go = [&](int x, int fa){
        int mx = totalSize - sz[x];
        for (auto &e : g[x]) {
            int y = e.first;
            if (y == fa || vis[y]) continue;
            go(y, x);
            mx = max(mx, sz[y]);
        }
        if (mx * 2 <= totalSize) best = x;
    };
    go(u, p);
    return best;
}

// 收集以 u 为起点，当前累加和为 dist 的所有前缀和到 vec
void collect(int u, int p, ll dist, vector<ll> &vec) {
    vec.push_back(dist);
    for (auto &e : g[u]) {
        int v = e.first, w = e.second;
        if (v == p || vis[v]) continue;
        collect(v, u, dist + w, vec);
    }
}

// 统计：在 a, b 两个已排序数组中，a[i] + b[j] ≤ mid 的对数
ll count_pairs(const vector<ll> &A, const vector<ll> &B, ll mid) {
    ll cnt = 0;
    int i = 0, j = (int)B.size() - 1;
    while (i < (int)A.size() && j >= 0) {
        if (A[i] + B[j] <= mid) {
            cnt += j + 1;
            i++;
        } else j--;
    }
    return cnt;
}

ll answer;    // 全局计数
ll LIMIT;     // 当前二分的 mid

// 重心分解递归
void solve_centroid(int rt) {
    int C = get_centroid(rt, 0);
    vis[C] = true;

    // 存放每个子树采集来的前缀和
    vector<ll> all;
    all.push_back(0);          // 单点路径（C→C）
    // 遍历每个子树
    for (auto &e : g[C]) {
        int v = e.first, w = e.second;
        if (vis[v]) continue;
        vector<ll> vec;
        collect(v, C, w, vec);
        // 排序后，先统计 vec 与 all 之间的对数
        sort(vec.begin(), vec.end());
        sort(all.begin(), all.end());
        answer += count_pairs(vec, all, LIMIT);
        // 再把 vec 合并进 all
        for (auto &x : vec) all.push_back(x);
    }
    // 最后补上 all 本身（单点）
    // （因为 all 中已包含 0，COUNT 时已涵盖所有以 C 为端点的单点或跨子树的路径）

    // 递归处理各个子树
    for (auto &e : g[C]) {
        int v = e.first;
        if (!vis[v]) solve_centroid(v);
    }
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    cin >> N >> K;
    vector<int> fa(N+1), w(N+1);
    // 输入父节点
    for(int i = 2; i <= N; i++){
        cin >> fa[i];
    }
    // 输入点权
    for(int i = 1; i <= N; i++){
        cin >> w[i];
    }
    // 构建无向树：在边上存的是「子节点权值」
    for(int v = 2; v <= N; v++){
        int u = fa[v];
        // u ↔ v，权值加在 v 这一方向
        g[u].push_back({v, w[v]});
        g[v].push_back({u, w[v]});
    }

    // 二分答案区间：最小是 min(w[i])，最大是 sum(w[i])（最坏一条链上全走）
    ll lo = *min_element(w.begin()+1, w.begin()+N+1);
    ll hi = 0;
    for(int i = 1; i <= N; i++) hi += w[i];

    ll ans = hi;
    while (lo <= hi) {
        ll mid = (lo + hi) >> 1;
        LIMIT = mid;
        answer = 0;
        memset(vis+1, 0, N);
        solve_centroid(1);
        if (answer >= K) {
            ans = mid;
            hi = mid - 1;
        } else {
            lo = mid + 1;
        }
    }

    cout << ans << "\n";
    return 0;
}
