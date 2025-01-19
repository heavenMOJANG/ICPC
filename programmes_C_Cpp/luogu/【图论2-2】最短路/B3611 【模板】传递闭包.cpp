#pragma GCC optimize(1)
#pragma GCC optimize(2)
#pragma GCC optimize(3,"Ofast","inline")
#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
ll n,g[110][110];
int main(int argc,const char**argv){
    ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    cin>>n;
    for(ll i=1;i<=n;++i)
        for(ll j=1;j<=n;++j) cin>>g[i][j];
    for(ll k=1;k<=n;++k)
        for(ll i=1;i<=n;++i)
            for(ll j=1;j<=n;++j)
                g[i][j]|=g[i][k]&&g[k][j];
    for(ll i=1;i<=n;++i){
        for(ll j=1;j<=n;++j) cout<<g[i][j]<<" ";
        cout<<"\n";
    }
    return 0;
}