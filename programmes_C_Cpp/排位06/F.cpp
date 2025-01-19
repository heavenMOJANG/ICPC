#pragma GCC optimize(1)
#pragma GCC optimize(2)
#pragma GCC optimize(3,"Ofast","inline")
#include<bits/stdc++.h>
#define int long long
#define double long double
using namespace std;
constexpr int inf=0x7fffffff;
int idx;
void solve(){
    int a,b,n;
    char ch;
    cin>>a>>ch>>b>>n;
    vector<vector<double>>dp(110,vector<double>(110,0.0));
    double p=(double)a/b;
    dp[0][0]=1;
    for(int i=1;i<=n;++i)
        for(int j=0;j*b<=i*a;++j){
            dp[i][j]=dp[i-1][j]*(1-p);
            if(j) dp[i][j]+=dp[i-1][j-1]*p;
        }   
    double sum=0;
    for(int i=0;i*b<=n*a;++i) sum+=dp[n][i];
    cout<<"Case #"<<++idx<<": "<<fixed<<setprecision(8)<<(int)(1/sum)<<"\n";
    return;
}
signed main(){
    ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    int _=1;cin>>_;
    while(_--) solve();
    return 0;
}
