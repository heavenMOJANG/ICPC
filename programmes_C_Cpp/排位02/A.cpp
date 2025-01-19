#pragma GCC optimize(1)
#pragma GCC optimize(2)
#pragma GCC optimize(3,"Ofast","inline")
#include<bits/stdc++.h>
#define int long long
using namespace std;
constexpr int inf=0x7fffffff;
void solve(){
    int n;cin>>n;
    vector<int>a(n+1),l(n+1),r(n+1);
    int dp[n+1];
    for(int i=1;i<=n;++i) cin>>a[i];
    int cnt=1;
    dp[1]=a[1];
    l[1]=1;
    for(int i=2;i<=n;++i){
        dp[dp[cnt]<=a[i]?++cnt:upper_bound(dp+1,dp+1+cnt,a[i])-dp]=a[i];
        l[i]=max(l[i-1],cnt);
    }
    for(int i=1,j=n;i<j;i++,j--) swap(a[i],a[j]);
    cnt=1,dp[1]=a[1];
    r[1]=1;
    for(int i=2;i<=n;++i){
        dp[dp[cnt]<=a[i]?++cnt:upper_bound(dp+1,dp+cnt+1,a[i])-dp]=a[i];
        r[i]=max(r[i-1], cnt);
    }
    int ans1=0;
    for(int i=1;i<=n;++i) ans1=max(ans1,l[i]+r[n-i]);
    cnt=1;
    dp[1]=a[1];
    for(int i=2;i<=n;++i){
        dp[dp[cnt]>=a[i]?++cnt:upper_bound(dp+1,dp+cnt+1,a[i],greater<int>())-dp]=a[i];
        r[i]=max(r[i-1],cnt);
    }
    for(int i=1,j=n;i<j;i++,j--) swap(a[i], a[j]);
    cnt=1,dp[1]=a[1];
    l[1]=1;
    for (int i=2;i<=n;++i){
        dp[dp[cnt]>=a[i]?++cnt:upper_bound(dp+1,dp+cnt+1,a[i],greater<int>())-dp]=a[i];
        l[i]=max(l[i-1],cnt);
    }
    int ans2=0;
    for (int i=1;i<=n;++i) ans2=max(ans2,l[i]+r[n-i]);
    cout<<max(ans1,ans2);
    return;
}
signed main(){
    ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    int _=1;
    while(_--) solve();
    return 0;
}
