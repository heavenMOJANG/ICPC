#include <bits/stdc++.h>
using namespace std;
using ll = long long;
int n,k;
vector<ll>a;
vector<vector<int>>g;
vector<vector<array<ll,2>>>f;
void dfs(int u,int p){
    f[u].assign(k+1,{LLONG_MIN,LLONG_MIN});
    f[u][0][0]=0;
    for(int v:g[u]) if(v!=p){
        dfs(v,u);
        vector<array<ll,2>> h(k+1, {LLONG_MIN,LLONG_MIN});
        for(int i=0;i<=k;i++) for(int b1=0;b1<2;b1++){
            ll x=f[u][i][b1]; if(x<LLONG_MIN/2) continue;
            for(int j=0;j<=k-i;j++) for(int b2=0;b2<2;b2++){
                ll y=f[v][j][b2]; if(y<LLONG_MIN/2) continue;
                int t=i+j;
                ll z;
                // 不用边
                z = x + y + (b2? a[v]:0);
                if(t+b2<=k) h[t+b2][b1] = max(h[t+b2][b1], z);
                // 接用边
                if(b2==1 && b1==0){
                    z = x + y;
                    if(t<=k) h[t][1] = max(h[t][1], z);
                }
                // 新开单点
                if(b2==0 && t+1<=k){
                    z = x + y + a[v];
                    h[t+1][b1] = max(h[t+1][b1], z);
                }
            }
        }
        f[u].swap(h);
    }
}
int main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cin>>n>>k;
    a.resize(n+1);
    for(int i=1;i<=n;i++)cin>>a[i];
    g.assign(n+1,{});
    for(int i=1,u,v;i<n;i++){
        cin>>u>>v;
        g[u].push_back(v);
        g[v].push_back(u);
    }
    f.resize(n+1);
    dfs(1,0);
    ll ans=0;
    for(int i=0;i<=k;i++){
        ans = max(ans, f[1][i][0]);
        ans = max(ans, f[1][i][1] + a[1]);
    }
    cout<<ans;
    return 0;
}
