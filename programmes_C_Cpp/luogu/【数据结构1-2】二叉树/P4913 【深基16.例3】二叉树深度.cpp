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
struct Edge{ll to,nxt;}edge[2000010];
ll n,dep[1000010],head[1000010],idx,maxd;
void add_edge(ll u,ll v){edge[idx]={v,head[u]},head[u]=idx++;}
void dfs(ll u){
    for(ll i=head[u];~i;i=edge[i].nxt){
        ll v=edge[i].to;
        dep[v]=dep[u]+1;
        dfs(v);
    }
}
int main(int argc,const char*argv[]){
    ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    memset(head,-1,sizeof(head));
    ll n;
    cin>>n;
    for(ll i=1;i<=n;++i){
        ll ls,rs;cin>>ls>>rs;
        if(ls) add_edge(i,ls);
        if(rs) add_edge(i,rs);
    }
    dep[1]=1;
    dfs(1);
    for(ll i=1;i<=n;++i) maxd=max(maxd,dep[i]);
    cout<<maxd;
    return 0;
}