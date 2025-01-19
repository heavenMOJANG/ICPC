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
    vector<int>dp(n+2,inf);
    dp[0]=0;
    for(int i=1;i<=n+1;++i){
        for(int j=max(0,i-m);j<i;++j){
            if(dp[j]!=inf){
                if(i==n+1||(i<=n&&s[i-1]=='L')) dp[i]=min(dp[i],dp[j]);
            }
            else if(i<=n&&s[i-1]=='W') dp[i]=min(dp[i],dp[j]+1);
        }
    }
    cout<<(dp[n+1]<=k?"YES\n":"NO\n");
    return;
}
signed main(){
    cin.tie(0)->sync_with_stdio(0);
    int _=1;cin>>_;
    while(_--) solve();
    return 0;
}