#pragma GCC optimize(1)
#pragma GCC optimize(2)
#pragma GCC optimize(3,"Ofast","inline")
#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef unsigned long long ull;
typedef pair<ll,ll> pll;
const ll inf=0x3f3f3f3f;
const ll mod=80112002;
struct Edge{ll to,nxt;}edge[500010];
ll n,m,head[5010],ind[5010],ans[5010],idx,res;
queue<ll>q;
void add_edge(ll u,ll v){edge[idx]={v,head[u]},head[u]=idx++;}
void topSort(){
	while(!q.empty()){
		ll u=q.front();q.pop();
        for(ll i=head[u];~i;i=edge[i].nxt){
            ll v=edge[i].to;
            ind[v]--;
            if(!ind[v]) q.push(v);
            ans[v]=(ans[v]+ans[u])%mod;
        }
	}
}
int main(int argc,const char*argv[]){
    ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    memset(head,-1,sizeof(head));
    cin>>n>>m;
    for(ll i=1,u,v;i<=m;++i) cin>>u>>v,add_edge(u,v),ind[v]++;
    for(ll i=1;i<=n;++i) if(!ind[i]) ans[i]=1,q.push(i);
    topSort();
    for(ll i=1;i<=n;++i) if(head[i]==-1) res=(res+ans[i])%mod;
    cout<<res;
    return 0;
}