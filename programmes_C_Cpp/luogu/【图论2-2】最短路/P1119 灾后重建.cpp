#pragma GCC optimize(1)
#pragma GCC optimize(2)
#pragma GCC optimize(3,"Ofast","inline")
#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef unsigned long long ull;
typedef pair<ll,ll> pll;
const ll inf=0x3f3f3f3f;
ll n,m,q,t[210],g[210][210];
int main(int argc,const char*argv[]){
    ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    cin>>n>>m;
    for(ll i=0;i<n;++i)
        for(ll j=0;j<n;++j) g[i][j]=inf;
    for(ll i=0;i<n;++i) cin>>t[i];
    for(ll i=0;i<n;++i) g[i][i]=0;
    for(ll i=0,u,v,w;i<m;++i){
        cin>>u>>v>>w;
        g[u][v]=g[v][u]=w;
    }
    cin>>q;
    ll cur=0;
    while(q--){
        ll x,y,T;cin>>x>>y>>T;
        while(t[cur]<=T&&cur<n){
            for(ll i=0;i<n;++i)
                for(ll j=0;j<n;++j)
                    g[i][j]=min(g[i][j],g[i][cur]+g[cur][j]);
            cur++;
        }
        if(t[x]>T||t[y]>T) cout<<"-1\n";
        else
            if(g[x][y]==0x3f3f3f3f) cout<<"-1\n";
            else cout<<g[x][y]<<"\n";
    }
    return 0;
}
