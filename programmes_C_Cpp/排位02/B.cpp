#pragma GCC optimize(1)
#pragma GCC optimize(2)
#pragma GCC optimize(3,"Ofast","inline")
#include<bits/stdc++.h>
#define int long long
using namespace std;
constexpr int inf=0x7fffffff;
constexpr int mod=1e9+7;
void solve(){
    string s;cin>>s;
    int k;cin>>k;
    int n=s.size();s=" "+s;
    vector<int>fac(n+10,0);
    fac[n]=1;
    for(int i=n-1;i>=1;--i) fac[i]=fac[i+1]*k%mod;
    vector<int>a(n+10,0);
    for(int i=1;i<=n;++i) a[i]=s[i]-'0';
    vector<int>p(n+10,0);
    p[n]=1;
    for(int i=n-1;i>=1;--i) p[i]=p[i+1]*10%mod;
    vector<int>l(n+10,0),r(n+10,0);
    for(int i=1;i<=n;++i) l[i]=(l[i-1]*10+a[i])%mod;
    r[n]=s[n]-'0';
    int ans=0;
    for(int i=n-1;i>=1;--i) r[i]=(r[i+1]+p[i]*a[i]%mod)%mod;
    for(int i=1;i<=n;++i){
        int t1=r[i+1],t2=l[i-1],t3=a[i];
        ans=(ans+fac[i]*(p[i]*(45*t2%mod+t3*(t3-1)/2)%mod+t3*(t1+1)%mod)%mod)%mod;
    }
    cout<<ans<<"\n";
    return;
}
signed main(){
    ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    int _=1;
    while(_--) solve();
    return 0;
}
