#pragma GCC optimize(1)
#pragma GCC optimize(2)
#pragma GCC optimize(3,"Ofast","inline")
#include<bits/stdc++.h>
typedef long long ll;
using namespace std;
constexpr ll inf=0x7fffffff;
constexpr ll mod=998244353;
ll f[200010]={1,1};
void solve(){
    string s;cin>>s;
    ll n=s.size();
    s=' '+s;
    ll cnt=0,res=0,ans=1;
    for(ll i=2;i<=n;++i)
        if(s[i]==s[i-1]) cnt++;
        else{
            if(cnt) ans=(ans*(cnt+1))%mod;
            res+=cnt;
            cnt=0;
        }
    if(cnt){
        ans=(ans*(cnt+1))%mod;
        res+=cnt;
        cnt=0;
    }
    ans=(ans*f[res])%mod;
    cout<<res<<" "<<ans<<"\n";
    return;
}
int main(int argc,const char*argv[]){
    ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    ll _=1;cin>>_;
    for(ll i=1;i<=200000;++i) f[i]=(f[i-1]*i)%mod;
    while(_--) solve();
    return 0;
}
