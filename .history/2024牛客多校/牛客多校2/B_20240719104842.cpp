#pragma GCC optimize(1)
#pragma GCC optimize(2)
#pragma GCC optimize(3,"Ofast","inline")
#include<bits/stdc++.h>
#define int long long
#define pii pair<int,int>
using namespace std;
constexpr int N=1e5+10;
struct Node{
    int id,dis;
    bool operator<(const Node&x)const{return dis>x.dis;}
};
struct Edge{int u,v,w;}e[N];
int n,m,q;
vector<pii>g[N];
signed main(){
    cin.tie(0)->sync_with_stdio(0);
    cin>>n>>m>>q;
    for(int i=0,u,v,w;i<m;++i){
        cin>>e[i].u>>e[i].v>>e[i].w;
        g[e[i].u].push_back({e[i].v,e[i].w});
        g[e[i].v].push_back({e[i].u,e[i].w});
    }
    sort(e,e+m,[](const Edge&x,const Edge&y){return x.w<y.w;});
    while(q--){
        int k;cin>>k;
        if(k<=sqrt(N)){
            map<int,int>done;
            for(int i=0,x;i<k;++i) cin>>x,done[x]=0;
            priority_queue<Node>pq;
            pq.push({done.begin()->first,0});
            int ans=0,cnt=0;
            while(!pq.empty()){
                Node u=pq.top();pq.pop();
                if(done[u.id]) continue;
                done[u.id]=1;
                ans+=u.dis;
                cnt++;
                for(auto [v,w]:g[u.id]){
                    if(done.count(v)==0||done[v]) continue;
                    pq.push({v,w});
                }
            }
            cout<<(cnt==k?ans:-1ll)<<"\n";
        }
        else{
            map<int,int>f,h;
            for(int i=0,x;i<k;++i) cin>>x,f[x]=x,h[x]=0;
            function<int(int)> findSet=[&](int x){
                return f[x]==x?f[x]:f[x]=findSet(f[x]);
            };
            int ans=0,cnt=0;
            for(int i=0;i<m;++i){
                if(cnt==n-1) break;
                if(f.count(e[i].u)==0||f.count(e[i].v)==0) continue;
                int e1=findSet(e[i].u);
                int e2=findSet(e[i].v);
                if(e1==e2) continue;
                else{
                    ans+=e[i].w;
                    if(h[e1]==h[e2]) h[e1]++,f[e2]=e1;
                    else{
                        if(h[e1]<h[e2]) f[e1]=e2;
                        else f[e2]=e1;
                    }
                    cnt++;
                }
            }
            cout<<(cnt==k-1?ans:-1ll)<<"\n";
        }
    }
    return 0;
}