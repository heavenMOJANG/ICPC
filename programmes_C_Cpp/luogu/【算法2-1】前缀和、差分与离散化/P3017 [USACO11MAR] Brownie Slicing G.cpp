#pragma GCC optimize(1)
#pragma GCC optimize(2)
#pragma GCC optimize(3,"Ofast","inline")
#include<bits/stdc++.h>
typedef long long ll;
using namespace std;
constexpr ll inf=0x7fffffff;
ll r,c,a,b,g[510][510];
ll calc(ll a,ll b,ll c,ll d) {return g[c][d]-g[a-1][d]-g[c][b-1]+g[a-1][b-1];}
ll check(ll x) {
	ll res=0,st=1;
	for(ll i=1;i<=r;++i) {
		ll p=0,q=1;
		for(ll j=1;j<=c;++j) if(calc(st,q,i,j)>=x) p++,q=j+1;
		if(p>=b) st=i+1,res++;	
	}
    return res>=a;
}
void solve(){
    cin>>r>>c>>a>>b;
    for(ll i=1;i<=r;++i)
        for(ll j=1;j<=c;++j)
            cin>>g[i][j],g[i][j]+=g[i-1][j]+g[i][j-1]-g[i-1][j-1];
    ll l=1,r=4000*500*500;
	while(l<=r){
		ll mid=l+r>>1;
		if(check(mid)) l=mid+1;
		else r=mid-1;
	}
    cout<<l-1;
    return;
}
int main(int argc,const char*argv[]){
    ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    solve();
    return 0;
}