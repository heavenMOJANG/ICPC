#pragma GCC optimize(1)
#pragma GCC optimize(2)
#pragma GCC optimize(3,"Ofast","inline")
#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int,int>PII;
typedef pair<ll,ll>PLL;
ll dx[]={-1,1,0,0};
ll dy[]={0,0,-1,1};
struct Edge{ll u,v,w;}edge[200010];
ll n,m,f[5010];
ll cmp(Edge x,Edge y){return x.w<y.w;}
ll find_set(ll x){return f[x]==x?f[x]:f[x]=find_set(f[x]);}
void Kruskal(){
    ll res=0,cnt=0;
    sort(edge+1,edge+1+m,cmp);
    for(ll i=1;i<=n;++i) f[i]=i;
    for(ll i=1;i<=m;++i){
        if(cnt==n-1) break;
        ll fu=find_set(edge[i].u),fv=find_set(edge[i].v);
        if(fu==fv) continue;
        else{
            res+=edge[i].w;
            f[fu]=fv;
            cnt++;
        }
    }
    if(cnt==n-1) cout<<res;
    else cout<<"orz";
}
int main(int argc,const char*argv[]){
    ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    cin>>n>>m;
    for(ll i=1;i<=m;++i) cin>>edge[i].u>>edge[i].v>>edge[i].w;
    Kruskal();
    return 0;
}