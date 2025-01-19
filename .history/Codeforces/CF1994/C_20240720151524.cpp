#pragma GCC optimize(1)
#pragma GCC optimize(2)
#pragma GCC optimize(3,"Ofast","inline")
#include<bits/stdc++.h>
#define int long long
using namespace std;
constexpr int inf=0x7fffffff;
void solve(){
    int n,x;cin>>n>>x;
    vector<int>a(n+1,0);
    for(int i=1;i<=n;++i) cin>>a[i],a[i]+=a[i-1];
    int ans=0;
    vector<int>dp(n+1);
    for(int i=n;i>=1;--i){
        int p=upper_bound(a.begin()+i,a.end(),a[i-1]+x)-a.begin();
        dp[i]=p-i;
        if(p+1<=n) dp[i]+=dp[p+1];
        ans+=dp[i];
    }
    cout<<ans<<"\n";
    return;
}
signed main(){
    cin.tie(0)->sync_with_stdio(0);
    int _=1;cin>>_;
    while(_--) solve();
    return 0;
}