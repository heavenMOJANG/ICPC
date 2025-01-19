#pragma GCC optimize(1)
#pragma GCC optimize(2)
#pragma GCC optimize(3,"Ofast","inline")
#include<bits/stdc++.h>
#define int long long
using namespace std;
constexpr int inf=0x7fffffff;
struct DSU{
    vector<int>p;
    DSU(int n):p(n+1){iota(p.begin(),p.end(),0);}
    int findSet(int x){return p[x]==x?x:p[x]=findSet(p[x]);}
    int same(int x,int y){return findSet(x)==findSet(y);}
    int merge(int x,int y){
        x=findSet(x),y=findSet(y);
        if(x==y)return 0;
        p[y]=x;
        return 1;
    }
};
void solve(){
    int n,c;cin>>n>>c;
    vector<array<int,3>>p;
    p.reserve(n*n);
    for(int i=0;i<n;++i)
        for(int j=0,x;j<n;++j){
            cin>>x;
            if(x!=0&&i<j) p.push_back({x,i,j});
        }
    sort(p.begin(),p.end());
    int minn=inf;
    for(int i=1;i<1<<n;++i){
        int s=__builtin_popcount(i)*c;
        DSU dsu(n);
        int cnt=0;
        for(auto [w,a,b]:p)
            if ((i>>a&1)||(i>>b&1)){
                if(dsu.merge(a,b))
                    s+=w,cnt++;
            }
        if(cnt==n-1) minn=min(minn,s);
    }
    cout<<minn<<"\n";
    return;
}
signed main(){
    ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    int _=1;cin>>_;
    while(_--) solve();
    return 0;
}
