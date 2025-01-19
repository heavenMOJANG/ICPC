#pragma GCC optimize(1)
#pragma GCC optimize(2)
#pragma GCC optimize(3,"Ofast","inline")
#include<bits/stdc++.h>
#define int long long
using namespace std;
constexpr int inf=0x7fffffff;
void solve(){
    int n;cin>>n;
    vector<int>a(n);
    for(int i=0;i<n;++i) cin>>a[i];
    vector<int>dp(3,0),ndp(3);
    dp[1]=dp[2]=inf;
    for(int i=0;i<n;++i){
        fill(ndp.begin(),ndp.end(),inf);
        ndp[0]=*min_element(dp.begin(),dp.begin()+3)+(a[i]>0);
        if(a[i]<=2){
            ndp[0]=min(ndp[0],dp[0]);
            ndp[1]=min(ndp[1],dp[0]+1);
        }
        if(a[i]<=4){
            ndp[2]=min(ndp[2],dp[1]+1);
            ndp[1]=min(ndp[1],dp[2]+1);
        }
        swap(dp,ndp);
    }
    cout<<*min_element(dp,dp+3)<<"\n";
    return;
}
signed main(){
    cin.tie(0)->sync_with_stdio(0);
    int _=1;cin>>_;
    while(_--) solve();
    return 0;
}