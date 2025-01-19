#pragma GCC optimize(1)
#pragma GCC optimize(2)
#pragma GCC optimize(3,"Ofast","inline")
#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
ll n,m,cnt,ind[1010],head[1010],idx,a[1010],st[1010],dp[1010],vis[1010][1010],maxn;
struct Edge{ll to,nxt,w;}edge[1000010];
void add_edge(ll u,ll v,ll w){edge[idx]={v,head[u],w},head[u]=idx++;}
void topSort(){
    queue<ll>q;
    for(ll i=1;i<=n;i++) if(!ind[i]) q.push(i);
    while(!q.empty()){
        ll u=q.front();q.pop();
        for(ll i=head[u];~i;i=edge[i].nxt){
            ll v=edge[i].to;
            ind[v]--;
            if(!ind[v]){
                q.push(v);
                dp[v]=max(dp[v],dp[u]+1);
                maxn=max(dp[v],maxn);
            }
        }
    }
}
int main(int argc,const char*argv[]){
    ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
	memset(head,-1,sizeof(head));
    cin>>n>>m;
    for(ll i=1,s;i<=m;++i){
        memset(a,0,sizeof(a));
        memset(st,0,sizeof(st));
        cin>>s;
        for(ll j=1;j<=s;++j) cin>>a[j],st[a[j]]=1;
        for(ll j=a[1];j<=a[s];++j)
            if(!st[j]) for(ll k=1;k<=s;++k) if(!vis[j][a[k]]) add_edge(j,a[k],1),ind[a[k]]++,vis[j][a[k]]=1;
    }
    topSort();
	cout<<maxn+1;
    return 0;
}