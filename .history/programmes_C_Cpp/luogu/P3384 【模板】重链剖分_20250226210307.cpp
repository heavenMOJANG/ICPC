#pragma GCC optimize(1)
#pragma GCC optimize(2)
#pragma GCC optimize(3,"Ofast","inline")
#include <bits/stdc++.h>
using namespace std;
#define int long long
const int inf=0x7f;
const int N = 1e5 + 10;
struct Edge{int to,nxt;}edge[2*N];
int n,m,r,mod;
int head[2*N],idx,w[N],w_new[N],tree[N<<2],tag[N<<2];
void add_edge(int u,int v){
    edge[idx]={v,head[u]};
    head[u]=idx++;
}
void add_tag(int k,int l,int r,int d){        
    tag[k]+=d;
    tree[k]=(tree[k]+d*(r-l+1))%mod;
}
void push_up(int k){tree[k]=(tree[k<<1]+tree[k<<1|1])%mod;}
void push_down(int k,int l,int r){
    if(tag[k]){
        int mid=(l+r)>>1;
        add_tag(k<<1,l,mid,tag[k]);
        add_tag(k<<1|1,mid+1,r,tag[k]);
        tag[k]=0;
    }
}
void build(int k,int l,int r){
    tag[k]=0;
    if(l==r){tree[k]=(w_new[l])%mod;return;}
    int mid=(l+r)>>1;
    build(k<<1,l,mid);
    build(k<<1|1,mid+1,r);
    push_up(k);
}
void update(int L,int R,int k,int l,int r,int d){
    if(L<=l&&r<=R){add_tag(k,l,r,d);return;}
    push_down(k,l,r);
    int mid=(l+r)>>1;
    if(L<=mid) update(L,R,k<<1,l,mid,d);
    if(R>mid) update(L,R,k<<1|1,mid+1,r,d);
    push_up(k);
}
int query(int L,int R,int k,int l,int r){
    if(l>=L&&R>=r) return tree[k]%=mod;
    push_down(k,l,r);
    int res=0;
    int mid=(l+r)>>1;
    if(L<=mid) res+=query(L,R,k<<1,l,mid);
    if(R>mid) res+=query(L,R,k<<1|1,mid+1,r);
    return res;
}
int son[N],id[N],fa[N],dep[N],siz[N],top[N];
void dfs1(int u,int father){
    dep[u]=dep[father]+1;
    fa[u]=father;
    siz[u]=1;
    for(int i=head[u];~i;i=edge[i].nxt){
        int v=edge[i].to;
        if(v!=father){
            fa[v]=u;
            dfs1(v,u);
            siz[u]+=siz[v];
            if(!son[u]||siz[son[u]]<siz[v]) son[u]=v;
        }
    }
}
int num=0;
void dfs2(int u,int topx){
    id[u]=++num;
    w_new[num]=w[u];
    top[u]=topx;
    if(!son[u]) return;
    dfs2(son[u],topx);
    for(int i=head[u];~i;i=edge[i].nxt){
        int v=edge[i].to;
        if(v!=fa[u]&&v!=son[u]) dfs2(v,v);
    }
}
void update_range(int u,int v,int z){
    while(top[u]!=top[v]){
        if(dep[top[u]]<dep[top[v]]) swap(u,v);
        update(id[top[u]],id[u],1,1,n,z);
        u=fa[top[u]];
    }
    if(dep[u]>dep[v]) swap(u,v);
    update(id[u],id[v],1,1,n,z);
}
int query_range(int u,int v){
    int res=0;
    while(top[u]!=top[v]){
        if(dep[top[u]]<dep[top[v]]) swap(u,v);
        res=(res+query(id[top[u]],id[u],1,1,n))%mod;
        u=fa[top[u]];
    }
    if(dep[u]>dep[v]) swap(u,v);
    return res=(res+query(id[u],id[v],1,1,n))%mod;
}
void update_tree(int u,int k){update(id[u],id[u]+siz[u]-1,1,1,n,k);}
int query_tree(int u){return query(id[u],id[u]+siz[u]-1,1,1,n)%mod;}
int main(int argc,const char*argv[]){
    ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    memset(head,-1,sizeof(head));
    cin>>n>>m>>r>>mod;
    for(int i=1;i<=n;++i) cin>>w[i];
    for(int i=1,u,v;i<n;++i) cin>>u>>v,add_edge(u,v),add_edge(v,u);
    dfs1(r,0);
    dfs2(r,r);
    build(1,1,n);
    while(m--){
        int k,x,y,z;cin>>k;
        switch(k){
            case 1:cin>>x>>y>>z;update_range(x,y,z);break;
            case 2:cin>>x>>y;cout<<query_range(x,y)<<"\n";break;
            case 3:cin>>x>>y;update_tree(x,y);break;
            case 4:cin>>x;cout<<query_tree(x)<<"\n";break;
        }
    }
    return 0;
}