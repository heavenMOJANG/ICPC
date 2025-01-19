#pragma GCC optimize(1)
#pragma GCC optimize(2)
#pragma GCC optimize(3,"Ofast","inline")
#include<bits/stdc++.h>
typedef long long ll;
using namespace std;
constexpr ll inf=0x7fffffff;
void solve(){
    ll n,k;cin>>n>>k;
    vector<ll>a(n+1),d(n+1),vis(n+1);
    for(ll i=1;i<=n;++i) cin>>a[i],d[a[i]]++;
    if(k==1){
        for(ll i=1;i<=n;++i) if(a[i]!=i){cout<<"NO\n";return;}
        cout<<"YES\n";
        return;
    }
    auto dfs=[&](auto self,ll x)->void
    {
        vis[x]=1;
        if(--d[a[x]]==0) self(self, a[x]);
    };
    for(ll i=1;i<=n;++i) if(!d[i]&&!vis[i]) dfs(dfs,i);
    for(ll i=1;i<=n;++i){
        if(vis[i]) continue;
        ll cnt=0;
        for(ll j=i;!vis[j];j=a[j]) vis[j]=1,cnt++;
        if(k!=cnt){cout<<"NO\n";return;}
    }
    cout<<"YES\n";
    return;
}
int main(int argc,const char*argv[]){
    ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    ll _=1;cin>>_;
    while(_--) solve();
    return 0;
}
