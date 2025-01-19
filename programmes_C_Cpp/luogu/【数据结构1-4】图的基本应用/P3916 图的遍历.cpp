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
struct Node{ll to,nxt;}edge[100010];
ll n,m,head[100010],idx,ans[100010];
void add_edge(ll u,ll v){edge[idx]={v,head[u]},head[u]=idx++;}
void dfs(ll x,ll y){
    if(ans[x]) return;
    ans[x]=y;
    for(ll i=head[x];~i;i=edge[i].nxt){
        ll v=edge[i].to;
        dfs(v,y);
    }
}
int main(int argc,const char*argv[]){
    ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    memset(head,-1,sizeof(head));
    cin>>n>>m;
    for(ll i=1,u,v;i<=m;++i) cin>>u>>v,add_edge(v,u);
    for(ll i=n;i>=1;--i) dfs(i,i);
    for(ll i=1;i<=n;++i) cout<<ans[i]<<" ";
    return 0;
}