#pragma GCC optimize(1)
#pragma GCC optimize(2)
#pragma GCC optimize(3,"Ofast","inline")
#include<bits/stdc++.h>
typedef long long ll;
using namespace std;
constexpr ll inf=0x7fffffff;
constexpr ll N=1e6+10;
ll n,k,m,p[N],res[N],go[N][65];
void solve(){
    cin>>n>>k>>m;
    for(ll i=1;i<=n;++i) cin>>p[i];
    go[1][0]=k+1;
    ll l=1,r=k+1;
    for(ll i=2;i<=n;++i){
        while(r+1<=n&&p[i]-p[l]>p[r+1]-p[i]) l++,r++;
        if(p[i]-p[l]>=p[r]-p[i]) go[i][0]=l;
        else go[i][0]=r;
    }
    for(ll i=1;i<=64;++i)
		for(ll j=1;j<=n;++j) go[j][i]=go[go[j][i-1]][i-1];
    for(ll i=1;i<=n;i++) res[i]=i;
    for(ll i=0;(1ll<<i)<=m;++i)
        if((m>>i)&1) for(ll j=1;j<=n;++j) res[j]=go[res[j]][i];
    for(ll i=1;i<=n;++i) cout<<res[i]<<" ";
    return;
}
int main(int argc,const char*argv[]){
    ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    ll _=1;
    while(_--) solve();
    return 0;
}
