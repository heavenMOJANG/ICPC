#pragma GCC optimize(1)
#pragma GCC optimize(2)
#pragma GCC optimize(3,"Ofast","inline")
#include<bits/stdc++.h>
typedef long long ll;
using namespace std;
constexpr ll inf=0x7fffffff;
ll n,q,a[100010],s[100010],ss[100010];
void solve(){
    cin>>n>>q;
    for(ll i=1;i<=n;++i) cin>>a[i],s[i]=(s[i-1]+a[i])&1;
    for(ll i=1;i<=n;++i) ss[i]=ss[i-1]+((s[i]^1)&1);
    for(ll i=1,l,r,k,t;i<=q;++i){
        cin>>l>>r>>k;
        if(!s[l-1]) t=ss[r]-ss[l-1];
        else t=r-l+1-(ss[r]-ss[l-1]);
        cout<<((t>=k&&(s[r]-s[l-1])%2==0)?"YES\n":"NO\n"); 
    }
    return;
}
int main(int argc,const char*argv[]){
    ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    ll _=1;cin>>_;
    while(_--) solve();
    return 0;
}