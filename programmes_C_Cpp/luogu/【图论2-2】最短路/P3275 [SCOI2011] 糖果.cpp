#pragma GCC optimize(1)
#pragma GCC optimize(2)
#pragma GCC optimize(3,"Ofast","inline")
#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
constexpr ll inf=0x7fffffff;
constexpr ll N=100010;
struct Edge{ll to,nxt,w;}edge[3*N],E[3*N];
ll n,m,head[N],H[N],dis[N],idx,dfn[N],low[N],tim,col[N],sum[N],cnt,flag=1,ind[N],dp[N];
stack<ll>st;
queue<ll>q;
void addEdge(Edge*e,ll*h,ll u,ll v,ll w){e[idx]={v,h[u],w},h[u]=idx++;}
void tarjan(ll u){
    dfn[u]=low[u]=++tim;
    st.push(u);
    for(ll i=head[u];~i;i=edge[i].nxt){
        ll v=edge[i].to;
        if(!dfn[v]){
            tarjan(v);
            low[u]=min(low[u],low[v]);
        }
        else if(!col[v]) low[u]=min(low[u],dfn[v]);
    }
    if(low[u]==dfn[u]){
        sum[++cnt]=1;
        while(st.top()!=u){
            col[st.top()]=cnt;
            sum[cnt]++;
            q.push(st.top());st.pop();
        }
        col[u]=cnt;
        q.push(u);
        st.pop();
        while(!q.empty()){
            ll t=q.front();
            for(ll i=head[t];~i;i=edge[i].nxt)
                if(col[edge[i].to]==cnt&&edge[i].w==1) flag=0;
            q.pop();
        }
    }
    return;
}
void topoSort(){
    q.push(col[0]);
    while(!q.empty()){
        ll u=q.front();q.pop();
        for(ll i=H[u];~i;i=E[i].nxt){
            int v=E[i].to;
            dp[v]=max(dp[u]+E[i].w,dp[v]);
            ind[v]--;
            if(!ind[v]) q.push(v);
        }
    }
}
void solve(){
    memset(head,-1,sizeof(head));
    memset(H,-1,sizeof(H));
    cin>>n>>m;
    for(ll i=1;i<=n;++i) addEdge(edge,head,0,i,1);
    for(ll i=1,op,u,v;i<=m;++i){
        cin>>op>>u>>v;
        switch(op){
            case 1:addEdge(edge,head,u,v,0);addEdge(edge,head,v,u,0);break;
            case 2:addEdge(edge,head,u,v,1);break;
            case 3:addEdge(edge,head,v,u,0);break;
            case 4:addEdge(edge,head,v,u,1);break;
            case 5:addEdge(edge,head,u,v,0);break;
        }
    }
    tarjan(0);
    if(!flag){puts("-1");return;}
    idx=0;
    for(ll u=0;u<=n;++u)
        for(ll i=head[u];~i;i=edge[i].nxt){
            if(col[u]==col[edge[i].to]) continue;
            addEdge(E,H,col[u],col[edge[i].to],edge[i].w);
            ind[col[edge[i].to]]++;
        }
    topoSort();
    ll res=0;
    for(ll i=1;i<=cnt;++i) res+=dp[i]*sum[i];
    cout<<res;
    return;
}
int main(int argc,const char*argv[]){
    ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    ll _=1;
    while(_--) solve();
    return 0;
}