#pragma GCC optimize(1)
#pragma GCC optimize(2)
#pragma GCC optimize(3,"Ofast","inline")
#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef unsigned long long ull;
const int inf=0x3f3f3f3f;
int dx[]={0,1,0,-1};
int dy[]={-1,0,1,0};
char g[1505][1505];
int vis[1505][1505][3],n,m,sx,sy,flag;
void dfs(int x,int y,int qx,int qy){
    if(vis[x][y][0]&&(vis[x][y][1]!=qx||vis[x][y][2]!=qy)) flag=1;
    if(vis[x][y][0]) return;
    if(flag) return;
    vis[x][y][1]=qx,vis[x][y][2]=qy,vis[x][y][0]=1;
    for(int i=0;i<4;++i){
        int xx=(x+dx[i]+n)%n,yy=(y+dy[i]+m)%m;
        if(g[xx][yy]!='#') dfs(xx,yy,qx+dx[i],qy+dy[i]);
    }
}
int main(int argc,const char*argv[]){
    ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
	while(cin>>n>>m) {
		flag=0;
        memset(vis,0,sizeof(vis));
        for(int i=0;i<n;++i)
            for(int j=0;j<m;++j){
                cin>>g[i][j];
                if(g[i][j]=='S') sx=i,sy=j;
            }
        dfs(sx,sy,sx,sy);
        cout<<(flag?"Yes\n":"No\n");
	}
    return 0;
}