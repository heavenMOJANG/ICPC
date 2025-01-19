#pragma GCC optimize(1)
#pragma GCC optimize(2)
#pragma GCC optimize(3,"Ofast","inline")
#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef unsigned long long ull;
typedef pair<ll,ll> pll;
const ll inf=0x3f3f3f3f;
ll n,m;
map<ll,ll>mp;
int main(int argc,const char*argv[]){
    ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    cin>>n;
    for(ll i=1,x;i<=n;++i) cin>>x,mp[x]=i;
    cin>>m;
    for(ll i=1,x;i<=m;++i) cin>>x,cout<<(mp.find(x)!=mp.end()?mp[x]:0ll)<<"\n";
    return 0;
}