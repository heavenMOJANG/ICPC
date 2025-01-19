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
    
    return;
}
signed main(){
    ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    int _=1;cin>>_;
    while(_--) solve();
    return 0;
}
