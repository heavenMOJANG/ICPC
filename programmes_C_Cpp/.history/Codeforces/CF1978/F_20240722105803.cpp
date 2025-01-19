#pragma GCC optimize(1)
#pragma GCC optimize(2)
#pragma GCC optimize(3,"Ofast","inline")
#include<bits/stdc++.h>
#define int long long
using namespace std;
constexpr int inf=0x7fffffff;
constexpr int N=1e6+10;
struct DSU{
    vector<int>f;
    DSU(int n):f(n+1){
        iota(f.begin(),f.end(),0);
    }
    int find(int x){
        return f[x]==x?f[x]:f[x]=find(f[x]);
    }
    int same(int x,int y){
        return find(x)==find(y);
    }
    int merge(int x,int y){
        x=find(x),y=find(y);
        if(x==y) return 0;
        f[y]=x;
        return 1;
    }
};
int vis[N],prime[N],minp[N],idx;
void eulerSteve(){
    vis[1]=1;
    for(int i=2;i<N;++i){
        if(!vis[i]){
            prime[idx++]=i;
            minp[i]=i;
        }
        for(int j=0;i*prime[j]<N;++j){
            vis[i*prime[j]]=1;
            minp[i*prime[j]]=prime[j];
            if(i%prime[j]==0) break;
        }
    }
}
void solve(){
    int n,k;cin>>n>>k;
    vector<int>a(2*n);
    for(int i=0;i<n;++i) cin>>a[i],a[i+n]=a[i];
    DSU dsu(n*2-1ll);
    vector<int>p;
    return;
}
signed main(){
    cin.tie(0)->sync_with_stdio(0);
    int _=1;cin>>_;
    while(_--) solve();
    return 0;
}