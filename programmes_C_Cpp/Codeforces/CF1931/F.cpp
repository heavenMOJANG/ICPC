#pragma GCC optimize(1)
#pragma GCC optimize(2)
#pragma GCC optimize(3,"Ofast","inline")
#include<bits/stdc++.h>
#define int long long
using namespace std;
constexpr int inf=0x7fffffff;
const int N = 2e5 + 10;
int n,k,a[N],d[N];
vector<int> g[N];
int topo(int n){
    queue<int>q;
    for(int i=1;i<=n;++i) if(!d[i]) q.push(i);
    while(!q.empty()){
        int u=q.front();
        q.pop();
        for(int v:g[u]){
            --d[v];
            if(d[v]==0) q.push(v);
        }
    }
    for(int i=1;i<=n;++i) if(d[i]) return 0;
    return 1;
}
void solve(){
    cin>>n>>k;
    for(int i=1;i<=n;++i){
        g[i].clear();
        d[i]=0;
    }
    for(int i=1;i<=k;++i) {
        for(int j=1;j<=n;++j) cin>>a[j];
        for (int j=2;j<n;++j){
            g[a[j]].push_back(a[j+1]);
            d[a[j+1]]++;
        }
    }
    cout<<(topo(n)?"YES\n":"NO\n");
    return;
}
signed main(){
    ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    int _=1;cin>>_;
    while(_--) solve();
    return 0;
}
