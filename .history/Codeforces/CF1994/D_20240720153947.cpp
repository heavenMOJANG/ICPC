#pragma GCC optimize(1)
#pragma GCC optimize(2)
#pragma GCC optimize(3,"Ofast","inline")
#include<bits/stdc++.h>
#define int long long
#define pii pair<int,int>
using namespace std;
constexpr int inf=0x7fffffff;
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
void solve(){
    int n;cin>>n;
    vector<int>a(n+1);
    for(int i=1;i<=n;++i) cin>>a[i];
    vector<pii>ans;
    DSU dsu(n);
    for(int i=n-1;i>=1;--i){
        vector<int>f(i,-1);
        for(int j=1;j<=n;++j)
            if(dsu.find(j)==j){
                int r=a[j]%i;
                if(f[r]!=-1){
                    dsu.merge(f[r],j);
                    ans.emplace_back(make_pair(f[r],j));
                    break;
                }
                else f[r]=j;
            }
    }
    cout<<"YES\n";
    for(int i=ans.size()-1;i>=0;--i) cout<<ans[i].first<<" "<<ans[i].second<<"\n";
    return;
}
signed main(){
    cin.tie(0)->sync_with_stdio(0);
    int _=1;cin>>_;
    while(_--) solve();
    return 0;
}