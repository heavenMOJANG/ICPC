#pragma GCC optimize(1)
#pragma GCC optimize(2)
#pragma GCC optimize(3,"Ofast","inline")
#include<bits/stdc++.h>
#define int long long
using namespace std;
constexpr int inf=0x7fffffff;
constexpr int mod=1e9+7;
void solve(){
    vector<vector<int>>c(1010,vector<int>(1010,0));
    vector<int>d(1010);
    d[0]=d[2]=1,d[1]=0;
    for(int i=3;i<=1000;++i) d[i]=(i-1)*(d[i-1]+d[i-2])%mod;
    for(int i=0;i<=1000;++i) c[i][0]=1;
    for(int i=1;i<=1000;++i)
        for(int j=1;j<=i;++j) c[i][j]=(c[i-1][j]+c[i-1][j-1])%mod;
    int _,idx=0;cin>>_;
    while(_--){
        int n,m,k;cin>>n>>m>>k;
        int res=0;
        for(int i=0;i<=n-m;++i) res=(res+d[n-k-i]*c[n-m][i]%mod)%mod;
        res=res*c[m][k]%mod;
        cout<<"Case "<<++idx<<": "<<res<<"\n";
    }
    return;
}
signed main(){
    ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    solve();
    return 0;
}
