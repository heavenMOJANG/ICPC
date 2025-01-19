#pragma GCC optimize(1)
#pragma GCC optimize(2)
#pragma GCC optimize(3,"Ofast","inline")
#include<bits/stdc++.h>
typedef long long ll;
using namespace std;
constexpr ll inf=0x7fffffff;
ll n,m;
void solve(){
    cin>>n>>m;
    if(m==1){
        for(ll i=0;i<=n;++i) cout<<"0\n";
        return;
    }
    if(n==1){
        cout<<"2\n";
        for(ll i=0;i<m;++i) cout<<i<<" \n"[i==m-1];
        return;
    }
    vector<vector<ll>>g(n,vector<ll>(m));
    if(n<m){
        ll t=n+1;
        vector<ll>d(n+1);
        cout<<n+1<<"\n";
        for(ll i=0;i<n;++i)
            for(ll j=0;j<n+1;++j)
                if(!i) g[i][j]=j,d[(i-j+n+1)%t]=g[i][j];
                else g[i][j]=d[(i-j+n+1)%(n+1)];
        for(ll i=0;i<n;++i)
            for(ll j=n+1;j<m;++j) g[i][j]=j;
    }
    else{
        ll t=min(n,m);
        cout<<t<<"\n";
        vector<ll>d(t);
        for(ll i=0;i<t;++i)
            for(ll j=0;j<t;++j){
                if(i<2) g[i][j]=j;
                if(i==2){
                    g[i][j]=(j-1+t)%t;
                    d[(i-j+t)%t]=g[i][j];
                }
                if(i>2) g[i][j]=d[(i-j+t)%t];
            }
        for(ll i=t;i<n;++i)
            for(ll j=0;j<m;++j) g[i][j]=g[0][j];
    }
    for(ll i=0;i<n;++i)
        for(ll j=0;j<m;++j) cout<<g[i][j]<<" \n"[j==m-1];
    return;
}
int main(int argc,const char*argv[]){
    ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    ll _=1;cin>>_;
    while(_--) solve();
    return 0;
}
