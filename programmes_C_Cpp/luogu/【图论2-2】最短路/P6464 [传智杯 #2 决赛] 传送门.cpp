#pragma GCC optimize(1)
#pragma GCC optimize(2)
#pragma GCC optimize(3,"Ofast","inline")
#include<bits/stdc++.h>
typedef long long ll;
using namespace std;
const ll inf=0x3f3f3f3f;
ll n,m,g[110][110],minn=LLONG_MAX,res;
int main(int argc,const char*argv[]){
    ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    cin>>n>>m;
    for(ll i=1;i<=n;++i)
        for(ll j=1;j<=n;++j) g[i][j]=(i==j?0LL:inf);
    for(ll i=1,u,v,w;i<=m;++i) cin>>u>>v>>w,g[u][v]=g[v][u]=w;
    for(ll k=1;k<=n;++k)
        for(ll i=1;i<=n;++i)
            for(ll j=1;j<=n;++j) g[i][j]=min(g[i][j],g[i][k]+g[k][j]);
    for(ll i=1;i<n;++i)
        for(ll j=i+1;j<=n;++j){
            res=0;
            for(ll a=1;a<n;++a)
                for(ll b=a+1;b<=n;++b)
                    if(a!=i||b!=j) res+=min(g[a][b],min(g[a][i]+g[j][b],g[a][j]+g[i][b]));     
            minn=min(minn,res);
        }
    cout<<minn;
    return 0;
}
