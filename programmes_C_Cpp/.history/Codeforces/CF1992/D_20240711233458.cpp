#pragma GCC optimize(1)
#pragma GCC optimize(2)
#pragma GCC optimize(3,"Ofast","inline")
#include<bits/stdc++.h>
#define int long long
using namespace std;
constexpr int inf=0x7fffffff;
void solve(){
    int n,m,k;cin>>n>>m>>k;
    string s;cin>>s;
    vector<int>l;
    vector<int>dp(n+2,0);
    dp[0]=1;
    int cnt=0;
    for(int i=0;i<=n;++i){
        if(!dp[i]) continue;
        if(i==0||s[i-1]=='L'){
            for(int j=1;j<=min(m,n-i+1);++j)
                if(i+j<=n&&s[i+j-1]!='C') dp[i+j]=1;
        }
        if(i<n&&s[i]=='W'){
            if(cnt<k) cnt++,dp[i+1]=1;
            else break;
        }
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