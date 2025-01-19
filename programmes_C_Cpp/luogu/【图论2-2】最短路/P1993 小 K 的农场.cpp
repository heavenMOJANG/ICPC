#pragma GCC optimize(1)
#pragma GCC optimize(2)
#pragma GCC optimize(3,"Ofast","inline")
#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef unsigned long long ull;
typedef pair<int,int>PII;
typedef pair<ll,ll>PLL;
const ll inf=0x3f3f3f3f;
const ll N=5010;
ll dx[]={-1,1,0,0};
ll dy[]={0,0,-1,1};
struct Edge{ll to,nxt,w;}edge[2*N];
ll n,m,head[N],dis[N],inq[N],neg[N],idx;
void add_edge(ll u,ll v,ll w){edge[idx]={v,head[u],w},head[u]=idx++;}
ll spfa(ll s){
    queue<ll>q;
    fill(dis+1,dis+1+n,inf);
    dis[s]=0;
    neg[s]=inq[s]=1;
    q.push(s);
    while(!q.empty()){
        ll u=q.front();q.pop();
        inq[u]=0;
        for(ll i=head[u];~i;i=edge[i].nxt){
            ll v=edge[i].to;
            if(dis[v]>dis[u]+edge[i].w){
                dis[v]=dis[u]+edge[i].w;
                if(!inq[v]){
                    inq[v]=1;
                    q.push(v);
                    neg[v]++;
                    if(neg[v]>n) return 1;
                }
            }
        }
    }
    return 0;
}
int main(int argc,const char*argv[]){
    ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    memset(head,-1,sizeof(head));
    cin>>n>>m;
    for(ll i=1;i<=n;++i) add_edge(0,i,0);
    for(ll i=1,op,u,v,w;i<=m;++i){
        cin>>op>>v>>u;
        if(op==1) cin>>w,add_edge(u,v,-w);
        if(op==2) cin>>w,add_edge(v,u,w);
        if(op==3) add_edge(u,v,0);
    }
    if(spfa(0)) return puts("No"),0;
    else return puts("Yes"),0;
}