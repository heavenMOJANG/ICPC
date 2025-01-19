#pragma GCC optimize(1)
#pragma GCC optimize(2)
#pragma GCC optimize(3,"Ofast","inline")
#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef unsigned long long ull;
typedef pair<ll,ll> pll;
const ll inf=0x3f3f3f3f;
ll dx[]={-1,0,1,1,1,0,-1,-1};
ll dy[]={1,1,1,0,-1,-1,-1,0};
struct Node{ll x,y;};
ll n,m,vis[110][110],res;
char g[110][110];
void bfs(ll x,ll y){
    queue<Node>q;
    q.push({x,y});
    vis[x][y]=1;
    while(!q.empty()){
        Node u=q.front();q.pop();
        for(ll i=0;i<8;++i){
            ll tx=u.x+dx[i],ty=u.y+dy[i];
            if(1<=tx&&tx<=n&&1<=ty&&ty<=m&&!vis[tx][ty]&&g[tx][ty]=='W'){
                q.push({tx,ty});
                vis[tx][ty]=1;
            }
        }
    }

}
int main(int argc,const char*argv[]){
    ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    cin>>n>>m;
    for(ll i=1;i<=n;++i)
        for(ll j=1;j<=m;++j) cin>>g[i][j];
    for(ll i=1;i<=n;++i)
        for(ll j=1;j<=m;++j) if(g[i][j]=='W'&&!vis[i][j]) bfs(i,j),res++;
    cout<<res;
    return 0;
}