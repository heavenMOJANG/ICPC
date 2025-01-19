#pragma GCC optimize(1)
#pragma GCC optimize(2)
#pragma GCC optimize(3,"Ofast","inline")
#include<bits/stdc++.h>
typedef long long ll;
using namespace std;
ll t,n,k,g[1010][1010];
int main(int argc,const char*argv[]){
    ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    cin>>t;
    while(t--){
        memset(g,0,sizeof(g));
        ll cnt=0;
        cin>>n>>k;
        for(ll i=1;i<=n;++i)
            for(ll j=1;j<=n;++j) cin>>g[i][j];
        for(ll i=1;i<=n;++i)
            for(ll j=1;j<=n;++j) if(g[i][j]!=g[n-i+1][n-j+1]) cnt++;
        if(cnt&&!k){cout<<"NO\n";continue;}
        if(!cnt&&!k){cout<<"YES\n";continue;}
        if(k%cnt==0) cout<<"YES\n";
        else cout<<"NO\n";
    }
    return 0;
}