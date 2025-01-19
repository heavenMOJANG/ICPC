#pragma GCC optimize(1)
#pragma GCC optimize(2)
#pragma GCC optimize(3,"Ofast","inline")
#include<bits/stdc++.h>
#define int long long
using namespace std;
constexpr int inf=0x7fffffff;
void solve(){
    vector<int>b(40,0),w(40,0);
    b[1]=b[2]=1;
    w[1]=w[2]=2;
    for(int i=3;i<=31;i+=2) b[i]=b[i+1]=b[i-1]+2,w[i]=w[i+1]=w[i-1]+2;
    int n,k;
    while(cin>>n>>k,n||k){
        if(k>=n*n){cout<<"0\n";continue;}
        vector<vector<vector<int>>>dp(2,vector<vector<int>>(40,vector<int>(1010,0)));
        for(int i=0;i<=n;++i) dp[0][i][0]=dp[1][i][0]=1;
        for(int i=1;i<=n;++i)
            for(int j=1;j<=k;++j){
                dp[0][i][j]=dp[0][i-1][j]+(b[i]-j+1)*dp[0][i-1][j-1];
                if(i!=n) dp[1][i][j]=dp[1][i-1][j]+(w[i]-j+1)*dp[1][i-1][j-1];
            }
        int res=0;
        for(int i=0;i<=k;++i) res+=dp[0][n][i]*dp[1][n-1][k-i];
        cout<<res<<"\n";
    }
    return;
}
signed main(){
    ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    int _=1;
    while(_--) solve();
    return 0;
}
