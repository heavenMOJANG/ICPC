#pragma GCC optimize(1)
#pragma GCC optimize(2)
#pragma GCC optimize(3,"Ofast","inline")
#include<bits/stdc++.h>
typedef long long ll;
using namespace std;
constexpr ll inf=0x7fffffff;
ll a,b,t,d;
map<ll,ll>mp;
void init(){
    for(ll i=1;i*i<=1e9;++i) mp[i*i]=1;
}
void solve(){
    cin>>a>>b;
    if(a>b) swap(a,b);
    t=sqrt(b-a);
    d=b-a;
    if(t*t==d){cout<<"1\n";return;}
    if(d&1||d%4==0){cout<<"2\n";return;}
    for(auto it=mp.begin();it!=mp.end();++it)
        if(mp.find(d-(it->first))!=mp.end()){cout<<"2\n";return;}
    cout<<"3\n";
    return;
}
int main(int argc,const char*argv[]){
    ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    ll _=1;cin>>_;
    init();
    while(_--) solve();
    return 0;
}