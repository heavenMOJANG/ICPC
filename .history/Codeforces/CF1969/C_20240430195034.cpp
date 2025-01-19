#pragma GCC optimize(1)
#pragma GCC optimize(2)
#pragma GCC optimize(3,"Ofast","inline")
#include<bits/stdc++.h>
#define int long long
using namespace std;
constexpr int inf=0x7fffffff;
void solve(){
    int n,k;cin>>n>>k;
    vector<int>a(n+1);
    for(int i=1;i<=n;++i) cin>>a[i];
    vector<vector<int>>dp(n+1,vector<int>(k+1,LLONG_MAX));
    dp[0][0]=0;
    for(int i=1;i<=n;++i)
        for(int pre=0;pre<=min(i-1,k);++pre)
            for(int suf=0;i+suf<=n&&pre+suf<=k;++suf)
                for(int turn=0;pre+suf+turn<=k;++turn)
                    dp[i+suf][pre+suf+turn]=min(dp[i+suf][pre+suf+turn],dp[i-pre-1][turn]+(suf+pre+1)*a[i]);
    cout<<*min_element(dp[n].begin(),dp[n].end())<<"\n";
    return;
}
signed main(){
    std::cin.tie(0)->sync_with_stdio(0);
    int _=1;cin>>_;
    while(_--) solve();
    return 0;
}