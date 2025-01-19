#pragma GCC optimize(1)
#pragma GCC optimize(2)
#pragma GCC optimize(3,"Ofast","inline")
#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef unsigned long long ull;
typedef pair<ll,ll> pll;
const ll inf=0x3f3f3f3f;
struct Edge{ll u,v,c;}e[2][200010],ans[200010];
ll n,m,k,f[20010],F[20010],idx[2],cnt[2],res;
ll findSet(ll x){return f[x]==x?x:f[x]=findSet(f[x]);}
ll FindSet(ll x){return F[x]==x?x:F[x]=FindSet(F[x]);}
int main(int argc,const char*argv[]){
    ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    cin>>n>>m>>k;
    for(ll i=1;i<=n;++i) f[i]=i;
    for(ll i=1,u,v,c;i<=m;++i) cin>>u>>v>>c,e[c][++idx[c]]={u,v,c};
    for(ll i=1;i<=n;++i) f[i]=F[i]=i;
    for(ll i=1;i<=idx[1];++i) f[findSet(e[1][i].u)]=findSet(e[1][i].v);
    for(ll i=1;i<=idx[0];++i){
        ll fx=findSet(e[0][i].u),fy=findSet(e[0][i].v);
        if (fx!=fy){
            cnt[0]++;
            f[fx]=fy;
            ans[++res]=e[0][i];
            F[FindSet(e[0][i].u)]=FindSet(e[0][i].v);
        }
    }
    if(cnt[0]>k) return puts("no solution"),0;
    for(ll i=1;i<=n;++i) f[i]=i;
    for(ll i=1;i<=idx[0];++i) f[findSet(e[0][i].u)]=findSet(e[0][i].v);
    for (ll i=1;i<=idx[1];++i){
        ll fx=findSet(e[1][i].u),fy=findSet(e[1][i].v);
        if (fx!=fy){
            cnt[1]++;
            f[fx]=fy;
            ans[++res]=e[1][i];
            F[FindSet(e[1][i].u)]=F[FindSet(e[1][i].v)];
        }
    }
    if(cnt[1]>n-k-1) return puts("no solution"),0;
    for(ll i=1;i<=idx[0];++i){
        if(cnt[0]==k) break;
        ll fx=FindSet(e[0][i].u),fy=FindSet(e[0][i].v);
        if(fx!=fy){
            cnt[0]++;
            F[fx]=fy;
            ans[++res]=e[0][i];
        }
    }
    if(cnt[0]<k) return puts("no solution"),0;
    for(ll i=1;i<=idx[1];++i){
        if(cnt[1]==n-k-1) break;
        ll fx=FindSet(e[1][i].u),fy=FindSet(e[1][i].v);
        if (fx!=fy){
            cnt[1]++;
            F[fx]=fy;
            ans[++res]=e[1][i];
        }
    }
    if(cnt[1]<n-k-1) return puts("no solution"),0;
    for(ll i=1;i<=res;++i) cout<<ans[i].u<<" "<<ans[i].v<<" "<<ans[i].c<<"\n";
    return 0;
}