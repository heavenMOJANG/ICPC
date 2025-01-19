#pragma GCC optimize(1)
#pragma GCC optimize(2)
#pragma GCC optimize(3,"Ofast","inline")
#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int,int>PII;
typedef pair<ll,ll>PLL;
const ll inf=0x3f3f3f3f;
ll n,m,g[1010][1010],sum;
int main(int argc,const char*argv[]){
    ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    cin>>n>>m;
    for(ll i=1;i<=n;++i)
        for(ll j=1;j<=n;++j) g[i][j]=(i==j?0:inf);
    for(ll i=1;i<=n;++i) g[i][i]=0;
    for(ll i=1;i<=m;++i){ll u,v,w;cin>>u>>v>>w,g[u][v]=min(w,g[u][v]);}
    for(ll k=1;k<=n;++k)
        for(ll i=1;i<=n;++i)
            for(ll j=1;j<=n;++j) if(g[i][k]!=inf&&g[k][j]!=inf&&g[i][j]>g[i][k]+g[k][j]) g[i][j]=g[i][k]+g[k][j];
    for(ll i=2;i<=n;++i) sum+=g[1][i]+g[i][1];
    cout<<sum;
    return 0;
}