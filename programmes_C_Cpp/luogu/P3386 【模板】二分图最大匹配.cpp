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
ll e,n,m,g[510][510],match[510],reserve_boy[510],sum;
ll dfs(ll u){
    for(ll i=1;i<=m;++i)
        if(!reserve_boy[i]&&g[u][i]){
            reserve_boy[i]=1;
            if(!match[i]||dfs(match[i])){
                match[i]=u;
                return 1;
            }
        }
    return 0;
}
int main(int argc,const char*argv[]){
    ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    cin>>n>>m>>e;
    for(ll i=1,u,v;i<=e;++i) cin>>u>>v,g[u][v]=1;
    for(ll i=1;i<=n;++i){
        memset(reserve_boy,0,sizeof(reserve_boy));
        if(dfs(i)) sum++;
    }
    cout<<sum;
    return 0;
}