#pragma GCC optimize(1)
#pragma GCC optimize(2)
#pragma GCC optimize(3,"Ofast","inline")
#include<bits/stdc++.h>
#define int long long
using namespace std;
constexpr int inf=0x7fffffff;
constexpr int mod=1e9+7;
void solve(){
    int l,r;cin>>l>>r;
    int ans=0;
    int p=4,ma=1e18;
    for(int i=2;i<60;++i){
        if(p>r)break;
        int a=p;
        p*=2;
        if(p<=l)continue;
        int num=0,t=1;
        while(t<=a/i)t*=i,num++;
        int j=t;
        while(j<=min(p-1,r)){
            if(j<=l/i){j*=i;num++;continue;}
            int rr=min(p-1,r);
            if(ma/i<j);
            else rr=min(rr,j*i-1);
            ans=(ans+(rr-l+1)*num)%mod;
            l=rr+1;
            if(j<=min(p-1,r)/i)j*=i;
            else break;
            num++;
        }
        if(l>r)break;
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
