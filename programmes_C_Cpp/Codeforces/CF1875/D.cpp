#pragma GCC optimize(1)
#pragma GCC optimize(2)
#pragma GCC optimize(3,"Ofast","inline")
#include<bits/stdc++.h>
#define int long long
using namespace std;
constexpr int inf=0x7fffffff;
int dp[200010];
void solve(){
    int n;cin>>n;
    map<int,int>mp;
    int maxn=0;
    for(int i=0,x;i<n;++i){
        cin>>x;
        maxn=!i?x:max(maxn,x);
        mp[x]++;
    }
    int p=0;
    while(mp.find(p)!=mp.end()) ++p;
    if(!p){cout<<"0\n";return;}
    int res=0,ans=(maxn+1)*n,pre=p;
    dp[p]=0;
    int sum=0;
    for(int i=p-1;i>=0;--i){
        dp[i]=(maxn+1)*n;
        for(int j=i+1;j<=p;++j) dp[i]=min(dp[i],dp[j]+(mp[i]-1)*j+i);
    }
    cout<<dp[0]<<"\n";
    return;
}
signed main(){
    ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    int _=1;cin>>_;
    while(_--) solve();
    return 0;
}
