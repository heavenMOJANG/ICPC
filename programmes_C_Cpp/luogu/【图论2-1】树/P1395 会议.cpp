#pragma GCC optimize(1)
#pragma GCC optimize(2)
#pragma GCC optimize(3,"Ofast","inline")
#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef unsigned long long ull;
typedef pair<int,int>PII;
typedef pair<ll,ll>PLL;
const ll inf=0x7f;
ll dx[]={-1,1,0,0};
ll dy[]={0,0,-1,1};
struct Edge{ll to,nxt;}edge[100010];
ll n,head[50010],idx,d[50010],dep[50010],ans[50010],maxn=LLONG_MAX,cnt,res;
void add_edge(ll u,ll v){edge[idx]={v,head[u]},head[u]=idx++;}
void dfs(ll u,ll f){
    d[u]=1;
    ll tmp=0;
    for(ll i=head[u];~i;i=edge[i].nxt){
        ll v=edge[i].to;
        if(v==f) continue;
        dfs(v,u);
        d[u]+=d[v];
        tmp=max(tmp,d[v]);
    }
    tmp=max(tmp,n-d[u]);
    if(tmp<maxn){
        maxn=tmp;
        cnt=0;
        ans[++cnt]=u;
    }
    else if(tmp==maxn) ans[++cnt]=u;
}
void get_depth(ll u,ll f){
    for(ll i=head[u];~i;i=edge[i].nxt){
        ll v=edge[i].to;
        if(v==f) continue;
        dep[v]=dep[u]+1;
        get_depth(v,u);
    }
}
int main(int argc,const char*argv[]){
    ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    memset(head,-1,sizeof(head));
    cin>>n;
    for(ll i=1,u,v;i<n;++i) cin>>u>>v,add_edge(u,v),add_edge(v,u);
    dfs(1,0);
    sort(ans+1,ans+1+cnt);
    get_depth(ans[1],-1);
    for(ll i=1;i<=n;++i) res+=dep[i];
    cout<<ans[1]<<" "<<res;
    return 0;
}