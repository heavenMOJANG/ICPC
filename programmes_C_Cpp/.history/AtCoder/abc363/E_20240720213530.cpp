#pragma GCC optimize(1)
#pragma GCC optimize(2)
#pragma GCC optimize(3,"Ofast","inline")
#include<bits/stdc++.h>
#define int long long
using namespace std;
constexpr int inf=0x7fffffff;
constexpr int dx[]={-1,0,1,0};
constexpr int dy[]={0,1,0,-1};
struct Node{
    pair<int,int>p;
    int h;
    bool operator>(const Node&x)const{return h<x.h;};
};
int n,m,k,sum,vis[1010][1010],h[1010][1010];
priority_queue<Node>pq;
signed main(){
    cin.tie(0)->sync_with_stdio(0);
    cin>>n>>m>>k;
    sum=n;
    for(int i=0;i<n;++i)
        for(int j=0;j<m;++j){
            cin>>h[i][j];
            if(i==0||i==n-1||j==0||j==m-1){
                pq.push({{i,j},h[i][j]});
                vis[i][j]=1;
            }
        }
    /*
    for(int i=1;i<=k;++i){
        while(!pq.empty()&&pq.top().h<=i){
            auto [x,y]=pq.top().p;
            sum--;
            for(int j=0;j<4;++j){
                int tx=x+dx[j],ty=y+dy[j];
                if(tx<0||tx>=n||ty<0||ty>=m||vis[tx][ty]) continue;
                pq.push({{tx,ty},h[tx][ty]});
                vis[tx][ty]=1;
            }
        }
        cout<<sum<<"\n";
    }
    */
    return 0;
}