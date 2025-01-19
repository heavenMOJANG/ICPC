#pragma GCC optimize(1)
#pragma GCC optimize(2)
#pragma GCC optimize(3,"Ofast","inline")
#include<bits/stdc++.h>
#define int long long
#define double long double
using namespace std;
constexpr int inf=0x7fffffff;
int idx,prime[1000010],vis[1000010],cnt;
double dp[1000010];
void euler(int x){
    for(int i=2;i<=x;++i){
        if(!vis[i]) prime[idx++]=i;
        for(int j=0;j<idx&&i*prime[j]<=x;++j){
            vis[i*prime[j]]=1;
            if(i%prime[j]==0) break;
        }
    }
}
double dfs(int x){
    if(x==1) return 0.0;
    if(vis[x]) return dp[x];
    vis[x]=1;
    int n=0,m=0;
    double res=0.0;
    for(int i=0;i<idx&&prime[i]<=x;++i){
        n++;
        if(x%prime[i]==0){
            m++;
            res+=dfs(x/prime[i]);
        }
    }
    res=(res+n)/m;
    return dp[x]=res;
}
void solve(){
    int n;cin>>n;
    cout<<"Case "<<++cnt<<": "<<fixed<<setprecision(10)<<dfs(n)<<"\n";
    return;
}
signed main(){
    ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    euler(1000000);
    memset(vis,0,sizeof(vis));
    int _=1;cin>>_;
    while(_--) solve();
    return 0;
}
