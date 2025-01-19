#pragma GCC optimize(1)
#pragma GCC optimize(2)
#pragma GCC optimize(3,"Ofast","inline")
#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
ll nt[4][2]={{0,1},{1,0},{0,-1},{-1,0}};
ll n,m,sx,sy,ex,ey,res,vis[310][310];
char g[310][310];
struct Node{ll x,y,step;};
void teleport(ll &a,ll &b){
	for(ll i=1;i<=n;++i)
		for(ll j=1;j<=m;++j) if(g[i][j]==g[a][b]&&(i!=a||j!=b)){a=i,b=j;return;}
}
void bfs(ll sx,ll sy){
	queue<Node>q;
	q.push(Node{sx,sy,0});
	vis[sx][sy]=1;
	Node ft;
	while(!q.empty()){
		ft=q.front();
		if(ft.x==ex&&ft.y==ey){res=ft.step;break;}
		if('A'<=g[ft.x][ft.y]&&g[ft.x][ft.y]<='Z') teleport(ft.x,ft.y);
		for(ll i=0;i<4;++i){
			ll tx=ft.x+nt[i][0],ty=ft.y+nt[i][1];
			if(tx>=1&&tx<=n&&ty>=1&&ty<=m&&vis[tx][ty]!=1&&g[tx][ty]!='#'){
				vis[tx][ty]=1;
				q.push(Node{tx,ty,ft.step+1});
			}
		}
		q.pop();
	}
}
int main(){
	ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
	cin>>n>>m;
	for(ll i=1;i<=n;++i)
		for(ll j=1;j<=m;++j){
			cin>>g[i][j];
			if(g[i][j]=='@') sx=i,sy=j;
			if(g[i][j]=='=') ex=i,ey=j;
	}
	bfs(sx,sy);
	cout<<res;
	return 0;
}