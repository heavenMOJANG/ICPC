#pragma GCC optimize(1)
#pragma GCC optimize(2)
#pragma GCC optimize(3,"Ofast","inline")
#include<bits/stdc++.h>
typedef long long ll;
using namespace std;
constexpr ll inf=0x7fffffff;
ll n,k,a[100010];
void solve(){
    cin>>n>>k;
    map<ll,ll>vis;
    vector<ll>v;
    for(ll i=1,x;i<=n;++i) cin>>x,v.push_back(x),vis[x]=1;
    for(ll i=0;i<=n;++i) if(vis.find(i)==vis.end()) v.push_back(i);
    ll len=n+1,m=len-k%len;
    for(ll i=0;i<n;++i) cout<<v[m%len]<<" ",m++;
    cout<<"\n";
    return;
}
int main(int argc,const char*argv[]){
    ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    ll _=1;cin>>_;
    while(_--) solve();
    return 0;
}
