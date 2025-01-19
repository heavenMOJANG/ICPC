#pragma GCC optimize(1)
#pragma GCC optimize(2)
#pragma GCC optimize(3,"Ofast","inline")
#include<bits/stdc++.h>
#define int long long
#define pii pair<int,int>
using namespace std;
constexpr int inf=0x7fffffff;
void solve(){
    int n;cin>>n;
    vector<int>a(n+10,0),s(n+10,0),dp(n+10,0);
    for(int i=1;i<=n;++i) cin>>a[i],s[i]=s[i-1]+a[i];
    a[n+1]=0;
    s[n+1]=s[n];
    int l=1,r=1e15;
    auto check=[&](int x){
        priority_queue<pii,vector<pii>,greater<pii>>q;
        dp[1]=a[1];
        q.push({0,0});
        for(int i=1;i<=n+1;++i){
            while(!q.empty()&&s[i-1]-s[q.top().second]>x) q.pop();
            dp[i]=q.top().first+a[i];
            q.push({dp[i],i});
        }
        return dp[n+1]<=x;
    };
    while(l<r){
        int mid=l+r>>1;
        if(check(mid)) r=mid;
        else l=mid+1;
    }
    cout<<l<<"\n";
    return;
}
signed main(){
    ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    int _=1;cin>>_;
    while(_--) solve();
    return 0;
}
