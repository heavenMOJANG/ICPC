#pragma GCC optimize(1)
#pragma GCC optimize(2)
#pragma GCC optimize(3,"Ofast","inline")
#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef unsigned long long ull;
typedef pair<ll,ll> pll;
const ll inf=0x3f3f3f3f;
ll dx[]={-1,1,0,0};
ll dy[]={0,0,-1,1};
ll n,m,t,sx,sy,fx,fy,g[10][10],vis[10][10],res;
ll check(ll x,ll y){
	if (x < 1 || x > n || y < 1 || y > m) return false;
	if (g[x][y]==1||vis[x][y]==1) return false;
	return true;
}
void dfs(ll x,ll y){
	if(x==fx&&y==fy){res++;return;}
	vis[x][y]=1;
	for (ll i=0;i<4;++i){
        ll tx=x+dx[i],ty=y+dy[i];
		if (1<=tx&&tx<=n&&1<=ty&&ty<=m&&!g[tx][ty]&&!vis[tx][ty]){
			dfs(tx,ty);
			vis[tx][ty]=0;
		}
	}
}
int main(int argc,const char*argv[]){
    ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    cin>>n>>m>>t>>sx>>sy>>fx>>fy;
    for(ll i=1,x,y;i<=t;++i) cin>>x>>y,g[x][y]=1;
	dfs(sx,sy);
	cout<<res;
    return 0;
}