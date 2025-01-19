#pragma GCC optimize(1)
#pragma GCC optimize(2)
#pragma GCC optimize(3,"Ofast","inline")
#include<bits/stdc++.h>
typedef long long ll;
using namespace std;
constexpr ll inf=0x7fffffff;
constexpr ll N=200010;
ll n,q,nxt[N][20],f[N][20],d[N],c[N];
stack<ll>s;
void solve(){
    cin>>n>>q;
    for(ll i=1;i<=n;++i){
        cin>>d[i]>>c[i];
        while(!s.empty()&&d[s.top()]<d[i]) nxt[s.top()][0]=i,s.pop();
		s.push(i);
    }
    for(ll i=1;i<=n;++i) f[i][0]=c[i];
	for(ll j=1;1<<(j-1)<=n;++j)
		for(ll i=1;i<=n;++i){
			nxt[i][j]=nxt[nxt[i][j-1]][j-1];
			f[i][j]=f[i][j-1]+f[nxt[i][j-1]][j-1];
		}
    for(ll i=1,r,v,k=log2(n);i<=q;++i){
        cin>>r>>v;
        for(ll j=k+1;j>=0;--j)
			if(v>f[r][j]) v-=f[r][j],r=nxt[r][j];
        cout<<r<<"\n";
    }
    return;
}
int main(int argc,const char*argv[]){
    ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    ll _=1;
    while(_--) solve();
    return 0;
}
