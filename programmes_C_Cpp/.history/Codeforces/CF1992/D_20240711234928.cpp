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
    vector<int>dp(n+2,0);
    dp[0]=1;
    for(int i=0;i<=n+1;++i){
        if(!dp[i]) continue;
        for(int j=1;j<=m&&i+j<=n;++j){
            int next=i+j;
            if(next==n+1||s[next-1]=='L') dp[next]=1;
            else if(s[next-1]=='W'){
                int water=0;
                while(next<=n&&s[next-1]=='W'&&water<k){
                    dp[next]=1;
                    ++next;
                    ++water;
                }
                if(next==n+1){cout<<"YES\n";return;}
            }
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