#pragma GCC optimize(1)
#pragma GCC optimize(2)
#pragma GCC optimize(3,"Ofast","inline")
#include<bits/stdc++.h>
typedef long long ll;
using namespace std;
constexpr ll inf=0x7fffffff;
void solve(){
    ll n,k,q;cin>>n>>k;
    string s;cin>>s;
    vector<ll>l(n),r(n),f(n);
    for(ll i=0;i<k;++i) cin>>l[i],l[i]--;
    for(ll i=0;i<k;++i) cin>>r[i],r[i]--;
    cin>>q;
    for(ll i=0,x;i<q;++i) cin>>x,f[x-1]^=1;
    for(ll i=0;i<k;++i){
        ll flag=0;
        for(ll j=l[i];j<=l[i]+r[i]-j;++j){
            flag^=f[j]^f[l[i]+r[i]-j];
            if(flag) swap(s[j],s[l[i]+r[i]-j]);
        }
    }
    cout<<s<<"\n";
    return;
}
int main(int argc,const char*argv[]){
    ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    ll _=1;cin>>_;
    while(_--) solve();
    return 0;
}
