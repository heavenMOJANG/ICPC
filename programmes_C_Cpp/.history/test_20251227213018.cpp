#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

// 定义最大节点数
const int MAXN = 200005;
const int LOGN = 20;

vector<int> adj[MAXN];
int parent[MAXN][LOGN];
int depth[MAXN];
int sz[MAXN]; // 子树大小
int N;

// DFS初始化深度、父节点和子树大小
void dfs(int u, int p, int d) {
    depth[u] = d;
    parent[u][0] = p;
    sz[u] = 1;
    for (int v : adj[u]) {
        if (v != p) {
            dfs(v, u, d + 1);
            sz[u] += sz[v];
        }
    }
}

// 预处理倍增表
void init_lca() {
    for (int j = 1; j < LOGN; j++) {
        for (int i = 0; i < N; i++) {
            if (parent[i][j - 1] != -1)
                parent[i][j] = parent[parent[i][j - 1]][j - 1];
            else
                parent[i][j] = -1;
        }
    }
}

// 计算LCA
int get_lca(int u, int v) {
    if (depth[u] < depth[v]) swap(u, v);
    for (int j = LOGN - 1; j >= 0; j--) {
        if (parent[u][j] != -1 && depth[parent[u][j]] >= depth[v]) {
            u = parent[u][j];
        }
    }
    if (u == v) return u;
    for (int j = LOGN - 1; j >= 0; j--) {
        if (parent[u][j] != parent[v][j]) {
            u = parent[u][j];
            v = parent[v][j];
        }
    }
    return parent[u][0];
}

// 计算两点间距离
int get_dist(int u, int v) {
    return depth[u] + depth[v] - 2 * depth[get_lca(u, v)];
}

// 判断点 x 是否在路径 u-v 上
bool on_path(int u, int v, int x) {
    return get_dist(u, v) == get_dist(u, x) + get_dist(x, v);
}

// 找到 u 关于祖先 anc 的直接子节点（用于计算非LCA侧的子树大小）
// 前提：anc 是 u 的真祖先
int jump(int u, int anc) {
    // 我们需要找到 u 向上跳到 depth[anc] + 1 的位置
    int target_depth = depth[anc] + 1;
    for (int j = LOGN - 1; j >= 0; j--) {
        if (parent[u][j] != -1 && depth[parent[u][j]] >= target_depth) {
            u = parent[u][j];
        }
    }
    return u;
}

int main() {
    // 优化IO
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    if (!(cin >> N)) return 0;

    for (int i = 0; i < N - 1; i++) {
        int u, v;
        cin >> u >> v;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }

    // 以0为根进行DFS
    // 虽然题目说0-indexed，但为了处理parent数组的-1，还是正常处理
    // 注意：题目中节点是 0 到 N-1
    dfs(0, -1, 0);
    init_lca();

    long long ans = 0;
    
    // 当前覆盖 0...k 的路径端点
    int u = 0, v = 0;
    
    // 初始针对 k=0 (即集合{0})，实际上只要路径包含0即可
    // 但我们的逻辑是累加 cnt(x)，即包含 0...x-1 的路径数
    // 当 x=1 时，集合为 {0}，路径端点 u=0, v=0
    
    for (int x = 1; x <= N; x++) {
        // 计算当前 path(u, v) 的贡献，即包含 0...x-1 的路径数
        // 此时 u, v 包含了 0...x-1
        
        long long count = 0;
        int lca = get_lca(u, v);
        
        if (u == v) {
            // 只有点0的情况，所有包含0的路径。
            // 实际上对于任意单点 u，经过它的路径数很难直接算，
            // 但我们的逻辑是 u, v 是 0...x-1 的极值点。
            // 当 x=1, u=0, v=0。
            // 任意经过0的路径 (i, j)。i 在 0 的某个子树，j 在 0 的另一个子树(或0本身)。
            // 直接用全集 - 不经过0的路径更好算？
            // 不，根据我们在“计算子树大小”中的逻辑：
            // 连通块大小分别是 size[u] 和 N - size[jump(u, parent[u])] 如果 u 不是根
            // 因为根是0，所以 u=0, v=0 时，看似很复杂。
            // 但此时我们可以认为是一个端点在 0，另一个端点也在 0。
            // 实际上，对于 x=1，集合 {0}。只要路径经过 0。
            // 我们可以统一逻辑：
            // 合法的 i 必须在 u 的“外侧”， j 必须在 v 的“外侧”。
            // 如果 u=v=0，0是根。那么整个树都是合法的 i，整个树都是合法的 j？不对。
            // 这里的 u, v 定义的是核心路径的两端。
            // 对于 u=v=0，任何经过0的路径都是合法的。
            // 这种情况下，公式是：Total pairs - sum(pairs entirely in one subtree of 0)
            // pairs in subtree k: sz[k] * (sz[k]+1) / 2
            // pairs total: N * (N+1) / 2
            
            long long bad_paths = 0;
            for(int child : adj[0]) {
                long long s = sz[child];
                bad_paths += s * (s + 1) / 2;
            }
            long long total_paths = (long long)N * (N + 1) / 2;
            count = total_paths - bad_paths;
        } else {
            // u 和 v 不同
            int sz_u = sz[u];
            int sz_v = sz[v];
            
            // 如果 lca == u，说明 u 是 v 的祖先，u 的方向是“除了 v 所在分支的整个树”
            // 修正：u 的有效区域是 全树 减去 (u 向 v 方向的那个直接子节点) 的子树
            if (lca == u) {
                int child = jump(v, u);
                sz_u = N - sz[child];
            }
            // 同理检查 v
            else if (lca == v) {
                int child = jump(u, v);
                sz_v = N - sz[child];
            }
            
            count = (long long)sz_u * sz_v;
        }
        
        ans += count;

        // 准备下一轮：尝试加入节点 x (如果 x == N 循环结束，不需要加)
        if (x == N) break;
        
        // 检查 x 是否已经在路径上
        if (on_path(u, v, x)) {
            // 已经在路径上，u, v 不变，继续
            continue;
        }
        
        // 尝试延长路径
        // 只有两种可能的新路径：x-v (包含原u) 或 u-x (包含原v)
        // 检查 x-v 是否包含 u (即 u 在 x-v 路径上)
        if (on_path(x, v, u)) {
            u = x; // 更新端点
        }
        else if (on_path(u, x, v)) {
            v = x; // 更新端点
        }
        else {
            // 无法形成简单路径，分叉了
            break;
        }
    }

    cout << ans << endl;

    return 0;
}
