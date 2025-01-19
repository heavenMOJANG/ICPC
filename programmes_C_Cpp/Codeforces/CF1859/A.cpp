#pragma GCC optimize(1)
#pragma GCC optimize(2)
#pragma GCC optimize(3,"Ofast","inline")
#include<bits/stdc++.h>
typedef long long ll;
using namespace std;
constexpr ll inf=0x7fffffff;
ll n;
void solve(){
    cin>>n;
    vector<ll>a,b,c;
    for(ll i=1,x;i<=n;++i) cin>>x,a.push_back(x);
    sort(a.begin(),a.end());
    for(ll x:a) if(x==a[0]) b.push_back(x); else c.push_back(x);
    if(b.size()==0||c.size()==0){cout<<"-1\n";return;}
    cout<<b.size()<<" "<<c.size()<<"\n";
    for(ll x:b) cout<<x<<" ";cout<<"\n";
    for(ll x:c) cout<<x<<" ";cout<<"\n";
    return;
}
int main(int argc,const char*argv[]){
    ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    ll _=1;cin>>_;
    while(_--) solve();
    return 0;
}
