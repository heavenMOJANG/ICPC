#pragma GCC optimize(1)
#pragma GCC optimize(2)
#pragma GCC optimize(3,"Ofast","inline")
#include<bits/stdc++.h>
#define int long long
using namespace std;
constexpr int inf=0x7fffffff;
constexpr int N=1e6+10;
int vis[N],prime[N],minp[N],idx;
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
vector<int>pos[N];
void solve(){
    int n,k;cin>>n>>k;
    vector<int>a(2*n);
    for(int i=0;i<n;++i) cin>>a[i],a[i+n]=a[i];
    DSU dsu(2*n-1);
    vector<int>p;
    for(int i=1;i<2*n;++i){
        int x=a[i];
        while(x>1){
            int t=minp[x];
            pos[t].emplace_back(i);
            p.emplace_back(t);
            while(x%t==0) x/=t;
        }
    }
    sort(p.begin(),p.end());
    p.erase(unique(p.begin(),p.end(),p.end()));
    for(auto x:p){
        for(int i=0;i+1<pos[x].size();++i){
            int p1=pos[x][i],p2=pos[x][i+1];
            if(p2-p1<=k) dsu.merge(p1,p2);
        }
        pos[x].clear();
    }
    int ans=0;
    for(int i=1;i<2*n;++i) ans+=(dsu.find(i)==i);
    for(int i=1;i<2*n;++i)
        if(a[i]==1){
            int tmp=(i<=n?i:2*n-i);
            ans+=tmp-1;
        }
    cout<<ans<<"\n";
    return;
}
signed main(){
    cin.tie(0)->sync_with_stdio(0);
    int _=1;cin>>_;
    while(_--) solve();
    return 0;
}