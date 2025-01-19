#pragma GCC optimize(1)
#pragma GCC optimize(2)
#pragma GCC optimize(3,"Ofast","inline")
#include<bits/stdc++.h>
#define int long long
using namespace std;
constexpr int inf=0x7fffffff;
void solve(){
    int k;cin>>k;
    vector<int>a(k);
    for(int i=0;i<k;++i){
        cin>>a[i];
        for(int j=0,x;j<a[i]-1;++j) cin>>x;
    }
    auto pre=a,suf=a;
    for(int i=1;i<k;++i) pre[i]|=pre[i-1];
    for(int i=k-2;i>=0;--i) suf[i]|=suf[i+1];
    int ans=pre.back();
    for(int i=0;i<k;++i){
        int t=0;
        if(i-1>=0) t|=pre[i-1];
        if(i+1<k) t|=suf[i+1];
        for(int j=0;j<20;++j)
            if(a[i]>>j&1){
                int x=(a[i]^(1ll<<j))|((1ll<<j)-1);
                ans=max(ans,t|x);
            }
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