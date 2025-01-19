#pragma GCC optimize(1)
#pragma GCC optimize(2)
#pragma GCC optimize(3,"Ofast","inline")
#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
ll n,res,len[10010],dp[10010],ind[10010];
vector<ll>g[10010];
void topSort(){
    queue<ll>q;
    for (ll i=1;i<=n;++i) if(!ind[i]) q.push(i);
    while(!q.empty()){
        ll u=q.front();q.pop();
        for(ll i=0;i<g[u].size();++i){
            ll v=g[u][i];
            ind[v]--;
            dp[v]=max(dp[v],dp[u]+len[v]);
            if (!ind[v]) q.push(v);
        }
    }
}
int main(int argc,const char*argv[]){
    ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    cin>>n;
    for(ll i=1,v,u;i<=n;++i){
        cin>>v>>len[v],dp[v]=len[v];
        while (cin>>u&&u){
            g[u].push_back(v);
            ind[v]++;
        }
    }
    topSort();
    for(ll i=1;i<=n;++i) res=max(res,dp[i]);
    cout<<res;
    return 0;
}