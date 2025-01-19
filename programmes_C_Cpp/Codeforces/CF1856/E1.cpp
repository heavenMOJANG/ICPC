#pragma GCC optimize(1)
#pragma GCC optimize(2)
#pragma GCC optimize(3,"Ofast","inline")
#include<bits/stdc++.h>
typedef long long ll;
using namespace std;
constexpr ll inf=0x7fffffff;
struct Edge{ll to,nxt;}e[10010];
ll n,head[5010],idx,res;
void addEdge(ll u,ll v){e[idx]={v,head[u]},head[u]=idx++;}
void solve(){
    memset(head,-1,sizeof(head));
    cin>>n;
    for(ll i=2,u;i<=n;++i) cin>>u,addEdge(u,i);
    auto dfs=[&](auto self,ll u)->int{
        
    }
    return;
}
int main(int argc,const char*argv[]){
    ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    ll _=1;
    while(_--) solve();
    return 0;
}