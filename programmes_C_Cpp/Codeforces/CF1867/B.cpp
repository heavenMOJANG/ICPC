#pragma GCC optimize(1)
#pragma GCC optimize(2)
#pragma GCC optimize(3,"Ofast","inline")
#include<bits/stdc++.h>
typedef long long ll;
using namespace std;
constexpr ll inf=0x7fffffff;
ll n;
string s;
void solve(){
    cin>>n>>s;
    s=" "+s;
    ll cnt=0;
    for(ll i=1;i<=n/2;++i) cnt+=(s[i]!=s[n-i+1]);
    if(n&1) for(ll i=0;i<=n;++i) cout<<((i>=cnt&&i<=n-cnt)?"1":"0");
    else for(ll i=0;i<=n;++i) cout<<((i>=cnt&&i<=n-cnt&&(i-cnt)%2==0)?"1":"0");
    cout<<"\n";
    return;
}
int main(int argc,const char*argv[]){
    ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    ll _=1;cin>>_;
    while(_--) solve();
    return 0;
}
