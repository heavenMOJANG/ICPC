#pragma GCC optimize(1)
#pragma GCC optimize(2)
#pragma GCC optimize(3,"Ofast","inline")
#include<bits/stdc++.h>
typedef long long ll;
using namespace std;
constexpr ll inf=0x7fffffff;
constexpr ll N=1000010;
struct Edge{ll to,nxt,w;}e[N<<1];
ll h,x,y,z,dis[N],head[N],idx,inq[N],res;
void addEdge(ll u,ll v,ll w){e[idx]={v,head[u],w},head[u]=idx++;}
void spfa(ll s){
    queue<ll>q;
    memset(dis,63,sizeof(dis));
    q.push(1);dis[1]=1;inq[1]=1;
    while(!q.empty()){
        ll u=q.front();q.pop();
        inq[u]=0;
        for(ll i=head[u];~i;i=e[i].nxt){
            ll v=e[i].to;
            if(dis[v]>dis[u]+e[i].w){
                dis[v]=dis[u]+e[i].w;
                if(!inq[v]){
                    q.push(v);
                    inq[v]=1;
                }
            }
        }
    }
}
void solve(){
    memset(head,-1,sizeof(head));
    cin>>h>>x>>y>>z;
    if(x==1||y==1||z==1){cout<<h<<"\n";return;}
    for(ll i=0;i<x;++i) addEdge(i,(i+y)%x,y),addEdge(i,(i+z)%x,z);
    spfa(1);
    for(ll i=0;i<x;++i) if(dis[i]<=h) res+=(h-dis[i])/x+1;
    cout<<res<<"\n";
    return;
}
int main(int argc,const char*argv[]){
    ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    ll _=1;
    while(_--) solve();
    return 0;
}