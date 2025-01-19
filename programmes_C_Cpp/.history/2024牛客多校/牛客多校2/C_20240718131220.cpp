#pragma GCC optimize(1)
#pragma GCC optimize(2)
#pragma GCC optimize(3,"Ofast","inline")
#include<bits/stdc++.h>
using namespace std;
const int inf=0x3f3f3f3f;
int f[10010],dfn[10010],vis[10010],w[10010],ans[10010],frm[10010];
int n,m,idx,cnt,maxn;
vector<int>e[10010],g[10010];
map<int,int>mp;
stack<int>s;
int findSet(int x){return f[x]==x?dfn[x]:f[x]=findSet(f[dfn[x]]);}
void tarjan(int u){
    dfn[u]=f[u]=++idx;
    s.push(u);
    vis[u]=1;
    for(auto v:e[u]){
        if(!dfn[v]){
            tarjan(v);
            f[u]=min(f[v],f[u]);
        }
        else if(vis[v]) f[u]=min(f[v],f[u]);
    }
    int tmp;
    if(dfn[u]==f[u]) {
        mp[f[u]]=++cnt;
        w[cnt]=0;
        do{
            tmp=s.top();s.pop();
            vis[tmp]=0;
            g[cnt].push_back(tmp);
            f[tmp]=f[u];
            w[cnt]+=frm[tmp];
        }while(u!=tmp);
    }
}
int dfs(int x){
    int res=0;
    ans[x]=w[x];
    for(auto v:g[x])
        for(auto k:e[v]){
            int b=mp[f[k]];
            if(ans[b]==-1) dfs(b);
            if(b!=x) res=max(res,ans[b]);
        }
    return ans[x]+=res;
}
int main(int argc,const char*argv[]){
    ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    cin>>n>>m;
    for(int i=1;i<=n;++i) cin>>frm[i];
    for(int i=1,x,y;i<=m;++i){
        cin>>x>>y;
        if(x==y) m--,i--;
        else e[x].push_back(y);
    }
    for(int i=1;i<=n;++i) if(!dfn[i]) tarjan(i);
    fill(ans+1,ans+1+cnt,-1);
    for(int i=1;i<=cnt;++i){
        if(ans[i]==-1) dfs(i);
        maxn=max(maxn,ans[i]);
    }
    cout<<maxn;
    return 0;
}