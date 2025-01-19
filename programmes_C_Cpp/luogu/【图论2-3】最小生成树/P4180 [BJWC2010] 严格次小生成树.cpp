#pragma GCC optimize(1)
#pragma GCC optimize(2)
#pragma GCC optimize(3,"Ofast","inline")
#include<bits/stdc++.h>
typedef long long ll;
using namespace std;
const ll inf=0x3f3f3f3f;
struct Edge{ll u,v,w,mark;}e[600010];
ll n,m,t1,t2,f[100010],fa[100010][30],len[100010][30][2],minn,d[100010],ans=1e18;
vector<ll>ed[100010],l[100010];
ll findSet(ll x){return f[x]==x?x:f[x]=findSet(f[x]);}
void merge(ll x,ll y){f[findSet(x)]=findSet(y);}
ll cmp(Edge x,Edge y){return x.w<y.w;}
void getM(ll x1,ll x2,ll x3,ll x4){
    ll a[5]={0,x1,x2,x3,x4};
    sort(a+1,a+5);ll tmp=unique(a+1,a+5)-a-1;
    t1=a[tmp],t2=a[tmp-1];
}
void kruskal(){
    sort(e+1,e+1+m,cmp);
    ll cnt=0;
    for(ll i=1;i<=n;++i) f[i]=i;
    for(ll i=1;i<=m;++i){
        if(findSet(e[i].u)!=findSet(e[i].v)){
            cnt++;
            merge(e[i].u,e[i].v);
            minn+=e[i].w,e[i].mark=1;
            ed[e[i].u].push_back(e[i].v);
            l[e[i].u].push_back(e[i].w);
            ed[e[i].v].push_back(e[i].u);
            l[e[i].v].push_back(e[i].w);
        }
        if(cnt==n-1) return;
    }
}
void bfs(){
    queue<ll>q;
    q.push(1);d[1]=1;
    while(!q.empty()){
        ll x=q.front();q.pop();
        for(ll i=0;i<ed[x].size();++i){
            ll y=ed[x][i];
            if(d[y]) continue;
            d[y]=d[x]+1,fa[y][0]=x,len[y][0][1]=l[x][i];
            q.push(y);
            for(ll j=1;j<=20;++j) fa[y][j]=fa[fa[y][j-1]][j-1];
            for(ll j=1;j<=20;++j){
                getM(len[y][j-1][1],len[y][j-1][0],len[fa[y][j-1]][j-1][1],len[fa[y][j-1]][j-1][0]);
                len[y][j][1]=t1,len[y][j][0]=t2;
            }
        }
    }
}
void lca(ll x,ll y){
    t1=-1,t2=-1;
    if(d[x]<d[y]) swap(x,y);
    for(ll i=20;i>=0;--i)
        if(d[fa[x][i]]>=d[y]){
            getM(t1,t2,len[x][i][0],len[x][i][1]);
            x=fa[x][i];
        }
    if(x==y) return;
    for(ll i=20;i>=0;--i)
        if(fa[x][i]!=fa[y][i]){
            getM(t1,t2,len[x][i][0],len[x][i][1]);
            getM(t1,t2,len[y][i][0],len[y][i][1]);
            x=fa[x][i],y=fa[y][i];
        }
    getM(t1,t2,len[x][0][0],len[x][0][1]);
    getM(t1,t2,len[y][0][0],len[y][0][1]);
}
int main(int argc,const char*argv[]){
    ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    cin>>n>>m;
    for(ll i=1;i<=m;++i){
        cin>>e[i].u>>e[i].v>>e[i].w;
        if(e[i].u==e[i].v) i--,m--;
    }
    kruskal();
    bfs();
    for(ll i=1;i<=m;++i)
        if(!e[i].mark){
            lca(e[i].u,e[i].v);
            ans=min(ans,minn+e[i].w-t2);
            if(e[i].w!=t1) ans=min(ans,minn+e[i].w-t1);
        }
    cout<<ans;
    return 0;
}
