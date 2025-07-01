#include <bits/stdc++.h>
using namespace std;
using ll = long long;

const int MAXN = 300000 + 5;

int N, M, Q;
int U[MAXN], V[MAXN];
int parent_[MAXN];
int sz[MAXN];

// 并查集查找
int findp(int x) {
    return parent_[x] == x ? x : parent_[x] = findp(parent_[x]);
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    cin >> N >> M;
    for(int i = 1; i <= M; i++){
        cin >> U[i] >> V[i];
    }
    cin >> Q;
    vector<int> X(Q);
    for(int i = 0; i < Q; i++){
        cin >> X[i];
    }

    // 初始化 DSU
    for(int i = 1; i <= N; i++){
        parent_[i] = i;
        sz[i] = 1;
    }

    // mp[i] 记录当前代表元 i 与其他各代表元之间的边数
    vector<unordered_map<int,int>> mp(N+1);
    mp.reserve(N+1);
    // 先把原始 M 条边加到 mp 里
    for(int i = 1; i <= M; i++){
        int a = U[i], b = V[i];
        // 初始时每个点自己就是一个代表元
        mp[a][b]++;
        mp[b][a]++;
    }

    ll curEdges = M;
    ostringstream oss;

    // 处理每次收缩操作
    for(int qi = 0; qi < Q; qi++){
        int ei = X[qi];  // 要收缩的原始边编号
        int u = U[ei], v = V[ei];
        int pu = findp(u), pv = findp(v);
        if(pu != pv) {
            // 看看这两个集合之间有没有边
            auto it = mp[pu].find(pv);
            if(it != mp[pu].end()) {
                int cnt = it->second;
                // 总边数减少所有这些跨集合的边
                curEdges -= cnt;

                // 小集合并入大集合
                if(mp[pu].size() < mp[pv].size()) {
                    swap(pu, pv);
                }
                // 现在把 pv 合并到 pu
                // 遍历 pv 的邻接表，把它们搬到 pu
                for(auto &kv : mp[pv]) {
                    int nei = kv.first;
                    int c = kv.second;
                    if(nei == pu) continue;
                    // 把 pv–nei 这 c 条边，变为 pu–nei
                    mp[pu][nei] += c;
                    mp[nei][pu] += c;
                    // 在 nei 的表里，删除原来指向 pv 的，改为指向 pu
                    mp[nei].erase(pv);
                }
                // 清空 pv 的表，合并 DSU
                mp[pv].clear();
                parent_[pv] = pu;
                sz[pu] += sz[pv];
            }
        }
        // 输出当前边数
        oss << curEdges << "\n";
    }

    cout << oss.str();
    return 0;
}
