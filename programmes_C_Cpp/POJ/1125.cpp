#pragma GCC optimize(1)
#pragma GCC optimize(2)
#pragma GCC optimize(3,"Ofast","inline")
#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const ll inf=0x3f3f3f3f;
ll n,m,g[110][110],u,v,w;
int main(int argc,const char*argv[]){
    ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    while(cin>>n&&n){
        memset(g,inf,sizeof(g));
        for(ll i=1;i<=n;++i) g[i][i]=0;
        for(u=1;u<=n;++u){
            cin>>m;
            for(ll i=1;i<=m;++i) cin>>v>>w,g[u][v]=w;
        }
        for(ll k=1;k<=n;++k)
            for(ll i=1;i<=n;++i)
                for(ll j=1;j<=n;++j) g[i][j]=min(g[i][j],g[i][k]+g[k][j]);
        for(ll i=1;i<=n;++i){
            for(ll j=1;j<=n;++j) cout<<g[i][j]<<" ";
            cout<<"\n";
        }
    }
    return 0;
}