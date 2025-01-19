#pragma GCC optimize(1)
#pragma GCC optimize(2)
#pragma GCC optimize(3,"Ofast","inline")
#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
struct Edge{ll u,v,e;}edge[1000010];
ll t,n,f[1000010],a[2000010],idx,len;
ll cmp(Edge x,Edge y){return x.e>y.e;}
ll find_set(ll x){return f[x]==x?x:f[x]=find_set(f[x]);}
void merge_set(ll x,ll y){
    ll fx=find_set(x),fy=find_set(y);
    f[fx]=fy;
    return;
}
int main(int argc,const char*argv[]){
    ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    cin>>t;
    while(t--){
        memset(f,0,sizeof(f));
        memset(a,0,sizeof(a));
        memset(edge,0,sizeof(edge));
        idx=0;
        cin>>n;
        for(ll i=1;i<=n;++i) cin>>edge[i].u>>edge[i].v>>edge[i].e,a[++idx]=edge[i].u,a[++idx]=edge[i].v;
        sort(a+1,a+1+idx);
        len=unique(a+1,a+1+idx)-a-1;
        for(ll i=1;i<=n;++i){
            edge[i].u=lower_bound(a+1,a+1+len,edge[i].u)-a-1;
            edge[i].v=lower_bound(a+1,a+1+len,edge[i].v)-a-1;
        }
        sort(edge+1,edge+1+n,cmp);
        for(ll i=1;i<=len;++i) f[i]=i;
        ll flag=1;
        for(ll i=1;i<=n;++i){
            ll u=edge[i].u,v=edge[i].v,e=edge[i].e;
            if(e==1) merge_set(u,v);
            if(e==0) if(find_set(u)==find_set(v)){cout<<"NO\n",flag=0;break;}
        }
        if(flag) cout<<"YES\n";
    }
    return 0;
}