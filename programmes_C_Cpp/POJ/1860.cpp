#pragma GCC optimize(1)
#pragma GCC optimize(2)
#pragma GCC optimize(3,"Ofast","inline")
#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const ll inf=0x3f3f3f3f;
struct node{ll to,nxt;double w,c;}edge[110];
ll n,m,s,u,v,head[110],vis[110],idx;
double v,r,c,dis[110];
void add(ll u,ll v,double w,double c){edge[idx]={v,head[u],w,c},head[u]=idx++;}
void Dijkstra(ll u){

}
int main(int argc,const char*argv[]){
    ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    cin>>n>>m>>s>>v;
    for(ll i=1;i<=m;++i){
        cin>>u>>v;
        cin>>r>>c;
        add(u,v,r,c);
        cin>>r>>c;
        add(v,u,r,c);
    }
    for()
    return 0;
}