#pragma GCC optimize(1)
#pragma GCC optimize(2)
#pragma GCC optimize(3,"Ofast","inline")
#include<bits/stdc++.h>
#define N 2010
#define M 3010
#define endl "\n"
using namespace std;
typedef long long ll;
typedef pair<int,int>PII;
typedef pair<ll,ll>PLL;
ll dx[]={-1,1,0,0};
ll dy[]={0,0,-1,1};
struct Edge{ll to,nxt,w;}edge[M*2+10];
ll T,n,m,head[N],dis[N],idx,inq[N],neg[N];
void add(ll u,ll v,ll w){edge[idx]={v,head[u],w},head[u]=idx++;}
ll spfa(ll s){
    queue<ll>q;
    q.push(s);
    dis[s]=0;neg[s]=inq[s]=1;
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
    cin>>T;
    while(T--){
        memset(head,-1,sizeof(head));
        memset(dis,0x7f,sizeof(dis));
        memset(neg,0,sizeof(neg));
        memset(inq,0,sizeof(inq));
        memset(edge,0,sizeof(edge));
        idx=0;
        cin>>n>>m;
        for(ll i=1;i<=m;++i){
            ll u,v,w;cin>>u>>v>>w;
            if(w>=0) add(u,v,w),add(v,u,w);
            else add(u,v,w);
        }
        cout<<(spfa(1)?"YES\n":"NO\n");
    }
    return 0;
}