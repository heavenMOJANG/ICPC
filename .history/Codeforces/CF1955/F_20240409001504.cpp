#pragma GCC optimize(1)
#pragma GCC optimize(2)
#pragma GCC optimize(3,"Ofast","inline")
#include<bits/stdc++.h>
#define int long long
using namespace std;
constexpr int inf=0x7fffffff;
void solve(){
    vector<int>p(5,0);
    int xorSum=0,ans=0;
    for(int i=1;i<=4;++i){
        cin>>p[i];
        ans+=p[i]/2;
        if(p[i]&1) xorSum^=i;
    }
    ans+=(xorSum==0);
    int cnt=0;
    for(int i=1;i<=4;++i) if(p[i]%2==0) cnt++;
    if(cnt==4) ans--;
    cout<<ans<<"\n";
    return;
}
signed main(){
    ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    int _=1;cin>>_;
    while(_--) solve();
    return 0;
}