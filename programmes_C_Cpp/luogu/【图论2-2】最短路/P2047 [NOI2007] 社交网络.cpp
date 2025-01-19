#pragma GCC optimize(1)
#pragma GCC optimize(2)
#pragma GCC optimize(3,"Ofast","inline")
#include<bits/stdc++.h>
typedef long long ll;
using namespace std;
const ll inf=0x3f3f3f3f;
ll n,m,g[110][110],c[110][110];
long double ans[110];
int main(int argc,const char*argv[]){
    ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    cin>>n>>m;
    for(ll i=1;i<=n;++i)
        for(ll j=1;j<=n;++j) g[i][j]=inf;
    for(ll i=1,u,v,w;i<=m;++i)
        cin>>u>>v>>w,g[u][v]=g[v][u]=w,c[u][v]=c[v][u]=1;
    for(ll k=1;k<=n;++k)
        for(ll i=1;i<=n;++i)
            for(ll j=1;j<=n;++j)
                if(g[i][j]>g[i][k]+g[k][j]){
					g[i][j]=g[i][k]+g[k][j];
					c[i][j]=c[i][k]*c[k][j];
				}
                else if(g[i][j]==g[i][k]+g[k][j]) c[i][j]+=c[i][k]*c[k][j];
    for(ll k=1;k<=n;++k)
		for(ll i=1;i<=n;++i)
			for(ll j=1;j<=n;++j){
				if(k==i||k==j||i==j) continue;
				if(g[i][j]==g[i][k]+g[k][j]&&c[i][j]) ans[k]+=1.0*c[i][k]*c[k][j]/c[i][j];
			}
    for(ll i=1;i<=n;++i) cout<<fixed<<setprecision(3)<<ans[i]<<"\n";
    return 0;
}
