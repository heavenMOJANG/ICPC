#pragma GCC optimize(1)
#pragma GCC optimize(2)
#pragma GCC optimize(3,"Ofast","inline")
#include<bits/stdc++.h>
typedef long long ll;
using namespace std;
const ll inf=0x3f3f3f3f;
ll n,m,g[110][110],res;
int main(int argc,const char*argv[]){
    ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    cin>>n>>m;
    for(ll i=1,u,v;i<=m;++i) cin>>u>>v,g[u][v]=1;
    for(ll k=1;k<=n;++k)
        for(ll i=1;i<=n;++i)
            for(ll j=1;j<=n;++j) g[i][j]|=g[i][k]&g[k][j];
    for(ll i=1;i<=n;++i){
		ll tmp=1;
		for(ll j=1;j<=n;++j){
			if(i==j) continue;
			else tmp=tmp&&(g[i][j]||g[j][i]);
		}
		res+=tmp;
	}
    cout<<res;
    return 0;
}
