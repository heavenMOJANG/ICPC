#pragma GCC optimize(1)
#pragma GCC optimize(2)
#pragma GCC optimize(3,"Ofast","inline")
#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef unsigned long long ull;
typedef pair<ll,ll> pll;
const ll inf=0x3f3f3f3f;
ll dx[]={-1,0,1,0,0};
ll dy[]={0,-1,0,1,0};
struct Node{ll x,y,t;};
ll m,g[310][310],vis[310][310];
ll bfs(){
    queue<Node>q;
    q.push({0,0,0});
    vis[0][0]=1;
    while(!q.empty()){
        Node u=q.front();q.pop();
        for(ll i=0;i<4;++i){
            ll tx=u.x+dx[i],ty=u.y+dy[i];
            if(tx<0||ty<0) continue;
            if(!vis[tx][ty]&&(g[tx][ty]==-1||g[tx][ty]>u.t+1)){
                if(g[tx][ty]==-1) return u.t+1;
                q.push({tx,ty,u.t+1});
                vis[tx][ty]=1;
            }
        }
    }
    return -1;
}
int main(int argc,const char*argv[]){
    ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    memset(g,-1,sizeof(g));
    cin>>m;
    for(ll i=1,x,y,t;i<=m;++i){
        cin>>x>>y>>t;
        for(ll j=0;j<5;++j){
            ll tx=x+dx[j],ty=y+dy[j];
            if(tx<0||ty<0) continue;
            if(g[tx][ty]==-1||g[tx][ty]>t) g[tx][ty]=t;
        }
    }
    if(g[0][0]==-1) return puts("0"),0;
    cout<<bfs();
    return 0;
}