#pragma GCC optimize(1)
#pragma GCC optimize(2)
#pragma GCC optimize(3,"Ofast","inline")
#include<bits/stdc++.h>
typedef long long ll;
using namespace std;
constexpr ll inf=0x7fffffff;
constexpr ll N=100010;
ll n,a[N],b[N],d[N];
map<ll,ll>mp;
void solve(){
    cin>>n;
    for(ll i=1;i<=n;++i) cin>>a[i],mp[a[i]]=i;
    for(ll i=1;i<=n;++i) cin>>b[i];
    ll len=0;
    for(ll i=1;i<=n;++i)
		if(mp[b[i]]>d[len]) d[++len]=mp[b[i]];
		else{
			ll p=lower_bound(d+1,d+1+len,mp[b[i]])-d;
			d[p]=mp[b[i]];
		}
    cout<<len;
    return;
}
int main(int argc,const char*argv[]){
    ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    ll _=1;
    while(_--) solve();
    return 0;
}
