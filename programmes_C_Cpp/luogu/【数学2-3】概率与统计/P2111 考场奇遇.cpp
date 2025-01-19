#pragma GCC optimize(1)
#pragma GCC optimize(2)
#pragma GCC optimize(3,"Ofast","inline")
#include<bits/stdc++.h>
#define int long long
#define double long double
using namespace std;
constexpr int inf=0x7fffffff;
double dp[60][60];
void solve(){
    int n,q;
    double a;
    cin>>n>>a>>q;
    a/=100.0;
    if(n>50){cout<<"1.000\n";return;}
    dp[0][0]=1.0;
    for(int i=1;i<=n;++i){
        char ch;cin>>ch;
        for(int j=0;j<=n;++j){
            if(ch=='0') dp[i][j]=dp[i-1][j]*a+dp[i-1][j-1]*(1-a);
            else dp[i][j]=dp[i-1][j]*(1-a)+dp[i-1][j-1]*a;
        }
    }
    double res=0.0;
    for(int i=q;i<=n;++i) res+=dp[n][i];
    cout<<fixed<<setprecision(3)<<res<<"\n";
    return;
}
signed main(){
    ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    int _=1;
    while(_--) solve();
    return 0;
}
