#pragma GCC optimize(1)
#pragma GCC optimize(2)
#pragma GCC optimize(3,"Ofast","inline")
#include<bits/stdc++.h>
#define int long long
using namespace std;
constexpr int inf=0x7fffffff;
constexpr int mod=998244353;
void solve(){
    int n;cin>>n;
    vector<int>a(n+1),d(n+1,0);
    for(int i=1;i<=n;++i) cin>>a[i];
    for(int i=1;i<=n;++i)
        for(int j=i;j<=n;j+=i) d[i]=max(d[i],a[j]);
    int ans=0;
    sort(++d.begin(),d.end());
    auto qpow=[&](int b,int x)->int
    {
        int res=1;
        while(x){
            if(x&1) res=res*b%mod;
            b=b*b%mod;
            x>>=1;
        }
        return res;
    };
    for(int i=1,j=0;i<=n;i++,j++) ans=(ans+d[i]%mod*qpow(2,j)%mod)%mod;
    cout<<ans<<"\n";
    return;
}
signed main(){
    ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    int _=1;
    while(_--) solve();
    return 0;
}
