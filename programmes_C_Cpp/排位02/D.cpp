#pragma GCC optimize(1)
#pragma GCC optimize(2)
#pragma GCC optimize(3,"Ofast","inline")
#include<bits/stdc++.h>
#define int long long
using namespace std;
constexpr int inf=0x7fffffff;
constexpr int dx[]={0,0,-1,1};
constexpr int dy[]={-1,1,0,0};
struct Node{
    int x,y,d;
};
char g[2010][2010];
int dis[2010][2010],vis[2010][2010];
void solve(){
    int n,m,d;cin>>n>>m>>d;
    int sx,sy,tx,ty;
    for(int i=0;i<n;++i)
        for(int j=0;j<m;++j){
            cin>>g[i][j];
            if(g[i][j]=='S') sx=i,sy=j;
            if(g[i][j]=='T') tx=i,ty=j;
        }
    queue<Node>q;
    while(!q.empty()){
        Node u=q.front();q.pop();
        
    }
    return;
}
signed main(){
    ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    int _=1;
    while(_--) solve();
    return 0;
}
