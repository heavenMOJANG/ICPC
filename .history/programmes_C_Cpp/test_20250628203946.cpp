#include <bits/stdc++.h>
using namespace std;

int N, M, E;
int cur_mask;                       // 输入图的边 mask
map<pair<int,int>,int> eid;        // 边(i,j)->id
vector<pair<int,int>> edges;       // id->(i,j)
int best = INT_MAX;

int degs[8];
bool used[28];

// 回溯选边 sel_mask 已经选中的边 mask，选了 cnt 条边
void dfs(int sel_mask, int cnt) {
    if (cnt == N) {
        // 所有顶点度 == 2
        int diff = __builtin_popcount(cur_mask ^ sel_mask);
        best = min(best, diff);
        return;
    }
    // 找度 < 2 中最小的 u
    int u = -1;
    for (int i = 0; i < N; i++)
        if (degs[i] < 2) { u = i; break; }
    // 还需要给 u 补 (2 - degs[u]) 条边，一定是 2-degs[u] == 2  
    // 所以直接从所有 v>w>u 中挑两条
    vector<int> cand;
    for (int v = u+1; v < N; v++) {
        if (degs[v] < 2 && !used[eid[{u,v}]])
            cand.push_back(v);
    }
    int C = cand.size();
    // 从 cand 中任意选 2 个不同的 v,w
    for (int i = 0; i < C; i++) {
        for (int j = i+1; j < C; j++) {
            int v = cand[i], w = cand[j];
            int e1 = eid[{u,v}], e2 = eid[{u,w}];
            // 选这两条
            used[e1] = used[e2] = true;
            degs[u] += 2; degs[v]++; degs[w]++;
            dfs(sel_mask | (1<<e1) | (1<<e2), cnt + 2);
            // 回溯
            used[e1] = used[e2] = false;
            degs[u] -= 2; degs[v]--; degs[w]--;
        }
    }
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    cin >> N >> M;
    // 枚举所有 i<j 边
    for(int i=0, idx=0; i<N; i++){
        for(int j=i+1; j<N; j++){
            eid[{i,j}] = idx++;
            edges.emplace_back(i,j);
        }
    }
    // 读入当前图
    for(int i=0; i<M; i++){
        int a,b; cin>>a>>b; --a;--b;
        if (a>b) swap(a,b);
        cur_mask |= 1 << eid[{a,b}];
    }
    // 初始化
    memset(degs, 0, sizeof(degs));
    memset(used, 0, sizeof(used));
    // 从空图开始选 N 条边，最后保证每个顶点度为 2
    dfs(0, 0);
    cout << best << "\n";
    return 0;
}
