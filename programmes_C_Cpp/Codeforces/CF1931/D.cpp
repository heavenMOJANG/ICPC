#pragma GCC optimize(1)
#pragma GCC optimize(2)
#pragma GCC optimize(3,"Ofast","inline")
#include<bits/stdc++.h>
#define int long long
using namespace std;
constexpr int inf=0x7fffffff;
void solve(){
    int n,x,y;cin>>n>>x>>y;
    vector<int>a(n+10);
    for(int i=1;i<=n;++i) cin>>a[i];
    map<pair<int,int>,int>mp;
    int ans=0;
    for(int i=1;i<=n;++i){
        int r1=a[i]%x,r2=a[i]%y;
        ans+=mp[{(x-r1%x)%x,r2}];
        mp[{r1,r2}]++;
    }
    cout<<ans<<"\n";
    return;
}
signed main(){
    ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    int _=1;cin>>_;
    while(_--) solve();
    return 0;
}
