#pragma GCC optimize(1)
#pragma GCC optimize(2)
#pragma GCC optimize(3,"Ofast","inline")
#include<bits/stdc++.h>
#define int long long
using namespace std;
constexpr int INF = 0x7fffffff;
void solve()
{
    int n,m,h; cin>>n>>m>>h;
    vector<short> horse(n+1);
    while(h--) {
        int u; cin>>u;
        horse[u] = 1;
    }
    vector<vector<PII>> adj(n+1);
    while(m--) {
        int u,v,w; cin>>u>>v>>w;
        adj[u].emplace_back(v, w), adj[v].emplace_back(u, w);
    }
    
    vector<array<ll,4>> dis(n+1);
    for(auto &i:dis) i.fill(1e18);
/*
0: 以1为起点，无马
1: 以1为起点，有马
2: 以n为起点，无马
3: 以n为起点，有马
*/
    auto dijkstra = [&](int rt, int bas)->void {
        std::priority_queue<TLI, vector<TLI>, std::greater<TLI>> pq;
        dis[rt][bas] = 0;
        pq.emplace(0, rt, bas);
        while(pq.size()) {
            auto [uDis,u,ubas] = pq.top(); pq.pop();
            if(uDis>dis[u][ubas]) continue;
            for(auto [v,w]:adj[u]) {
                auto vDis = uDis+(w>>(ubas&1));
                auto vbas = ubas|horse[v];
                if(dis[v][vbas]<=vDis) continue;
                dis[v][vbas] = vDis;
                pq.emplace(vDis, v, vbas);
            }
        }
    };
    dijkstra(1, 0|horse[1]);
    dijkstra(n, 2|horse[n]);
    
    ll res = 1e18;
    for(int i=1; i<=n; ++i)
        res = std::min(res, std::max(std::min(dis[i][0], dis[i][1]), std::min(dis[i][2], dis[i][3])));
    if(res==1e18) cout<<-1<<endl;
    else cout<<res<<endl;
}
signed main() {
    cin.tie(0) -> sync_with_stdio(0);
    int _ = 1; //cin >> _;
    while(_ --) solve();
    return 0;
}