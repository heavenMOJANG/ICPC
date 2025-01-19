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
    vector<ll>v[n+1];
    for(ll i=1,len,x;i<=n;++i){
        cin>>len;
        for(ll j=0;j<len;++j) cin>>x,v[i].push_back(x);
        sort(v[i].begin(),v[i].end());
    }
    ll minn=LLONG_MAX,p=0,res=LLONG_MAX;
    for(ll i=1;i<=n;++i){
        if(v[i][1]<minn) minn=v[i][1],p=i;
        if(v[i][0]<res) res=v[i][0];
    }
    ll sum=0;
    for(ll i=1;i<=n;++i) sum+=v[i][1];
    sum=sum-v[p][1]+res;
    cout<<sum<<"\n";
    return;
}
int main(int argc,const char*argv[]){
    ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    ll _=1;cin>>_;
    while(_--) solve();
    return 0;
}
