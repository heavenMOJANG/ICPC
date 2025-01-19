#pragma GCC optimize(1)
#pragma GCC optimize(2)
#pragma GCC optimize(3,"Ofast","inline")
#include<bits/stdc++.h>
#define int long long
using namespace std;
constexpr int inf=0x7fffffff;
void solve(){
    int n,m,k;cin>>n>>m>>k;
    string s;cin>>s;s=" "+s;
    vector<int>dp(n+2,-1);
    dp[0]=0;
    for(int i=1;i<=n;++i){
        if(s[i]=='C') continue;
        if(s[i]=='L'){
            for(int j=1;j<=m&&i+j<=n+1;++j) dp[i+j]=k;
        }
        else 
    }
    cout<<(dp[n+1]?"YES\n":"NO\n");
    return;
}
signed main(){
    cin.tie(0)->sync_with_stdio(0);
    int _=1;cin>>_;
    while(_--) solve();
    return 0;
}