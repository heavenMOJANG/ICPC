#include <bits/stdc++.h>
using namespace std;
using ll = long long;
const ll NEG = (ll)-4e18;

int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int N, K;
    cin >> N >> K;
    vector<ll> A(N+1);
    for(int i=1;i<=N;i++) cin >> A[i];
    vector<vector<int>> adj(N+1);
    for(int i=1,u,v;i<N;i++){
        cin >> u >> v;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }
    // 1) 先做一次遍历，记录父子关系与后序
    vector<int> parent(N+1,-1), order;
    order.reserve(N);
    stack<int> st;
    st.push(1); parent[1]=0;
    while(!st.empty()){
        int v = st.top(); st.pop();
        order.push_back(v);
        for(int u: adj[v]){
            if(parent[u]==-1){
                parent[u] = v;
                st.push(u);
            }
        }
    }
    // 得到的是一个前序，我们反过来就是后序
    reverse(order.begin(), order.end());
    // 2) dp0[v][j], dp1[v][j]  j=0..K
    vector< array<ll,6> > dp0(N+1), dp1(N+1);
    for(int v: order){
        // 初始化
        for(int j=0;j<=K;j++){
            dp0[v][j] = dp1[v][j] = NEG;
        }
        dp0[v][0] = 0;
        dp1[v][0] = A[v];

        // 依次合并每个孩子 u
        for(int u: adj[v]){
            if(parent[u] != v) continue; // 只看子节点
            // 先拷贝当前 dp
            array<ll,6> cur0 = dp0[v], cur1 = dp1[v];
            // 清空 dp[v]
            for(int j=0;j<=K;j++){
                dp0[v][j] = dp1[v][j] = NEG;
            }
            // 枚举 cur 的状态 和 子树 u 的状态
            for(int j1=0;j1<=K;j1++){
                for(int t1=0;t1<2;t1++){
                    ll val1 = (t1==0 ? cur0[j1] : cur1[j1]);
                    if(val1<NEG/2) continue;
                    for(int j2=0;j2+j1<=K;j2++){
                        // case 子树 u 不留开放端点
                        ll c0 = dp0[u][j2];
                        if(c0 > NEG/2){
                            // t 不变
                            if(t1==0){
                                dp0[v][j1+j2] = max(dp0[v][j1+j2], val1 + c0);
                            } else {
                                dp1[v][j1+j2] = max(dp1[v][j1+j2], val1 + c0);
                            }
                        }
                        // case 子树 u 留一个开放端点
                        ll c1 = dp1[u][j2];
                        if(c1 > NEG/2){
                            if(t1==0){
                                // 从 child 开一个新开放端到 parent
                                // +A[v]
                                dp1[v][j1+j2] = max(dp1[v][j1+j2],
                                                   val1 + c1 + A[v]);
                            } else {
                                // 和已有一个开放端在 v 处闭合，完整路径数 +1
                                if(j1 + j2 + 1 <= K){
                                    dp0[v][j1+j2+1] = max(dp0[v][j1+j2+1],
                                                          val1 + c1);
                                }
                            }
                        }
                    }
                }
            }
        }
    }

    // 3) 根在 1 处，统计答案
    ll ans = 0;
    // 先所有不留开放端点的情况
    for(int j=0;j<=K;j++){
        ans = max(ans, dp0[1][j]);
    }
    // 再考虑把根处的开放端闭合成一条完整路径
    for(int j=0;j<=K-1;j++){
        ans = max(ans, dp1[1][j]);
    }
    cout << ans << "\n";
    return 0;
}
