#pragma GCC optimize(1)
#pragma GCC optimize(2)
#pragma GCC optimize(3,"Ofast","inline")
#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef unsigned long long ull;
typedef pair<ll,ll> pll;
const ll inf=0x3f3f3f3f;
struct Edge{
    ll u,v,w;
    bool operator<(const Edge&t)const{return w<t.w;}
}edge[4000010];
struct Node{ll x,y;}a[2010];
ll n,f[2010],c[2010],k[2010],idx,ans1[2010],cnt1,ax[2010],ay[2010],cnt2;
ll getDis(Node a,Node b){return llabs(a.x-b.x)+llabs(a.y-b.y);}
ll find_set(ll x){return f[x]==x?x:f[x]=find_set(f[x]);}
ll kruskal(){
    ll res=0,cnt=0;
    sort(edge+1,edge+1+idx);
    for(ll i=1;i<=n;++i) f[i]=i;
    for(ll i=1;i<=idx;++i){
        if(cnt==n-1) break;
        ll fu=find_set(edge[i].u),fv=find_set(edge[i].v);
        if(fu==fv) continue;
        else{
            if(!edge[i].u||!edge[i].v) ans1[++cnt1]=edge[i].u+edge[i].v;
            else ax[++cnt2]=edge[i].u,ay[cnt2]=edge[i].v;
            res+=edge[i].w;
            f[fu]=fv;
            cnt++;
        }
    }
    return res;
}
int main(int argc,const char*argv[]){
    ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    cin>>n;
    for(ll i=0;i<=n;++i) f[i]=i;
    for(ll i=1;i<=n;++i) cin>>a[i].x>>a[i].y;
    for(ll i=1;i<=n;++i) cin>>c[i];
    for(ll i=1;i<=n;++i) cin>>k[i];
    for(ll i=1;i<=n;++i) edge[++idx]={0,i,c[i]},edge[idx++]={i,0,c[i]};
    for(ll i=1;i<n;++i)
        for(ll j=i+1;j<=n;++j)
            edge[++idx]={i,j,(k[i]+k[j])*getDis(a[i],a[j])};
    n++;
    cout<<kruskal()<<"\n"<<cnt1<<"\n";
    for(ll i=1;i<=cnt1;++i) cout<<ans1[i]<<" ";
    cout<<"\n"<<cnt2<<"\n";
    for(ll i=1;i<=cnt2;++i) cout<<ax[i]<<" "<<ay[i]<<"\n";
    return 0;
}