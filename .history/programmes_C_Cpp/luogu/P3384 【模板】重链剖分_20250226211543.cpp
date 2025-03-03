#pragma GCC optimize(1)
#pragma GCC optimize(2)
#pragma GCC optimize(3,"Ofast","inline")
#include <bits/stdc++.h>
using namespace std;
#define int long long
const int INF = 0x7fffffff;
const int N = 1e5 + 10;
struct Edge{ int to,nxt; } e[N << 1];
struct Node { int val, tag; } t[N << 2];
int n, m, r, mod;
int head[N << 1], idx, w[N], w_new[N];
void addEdge(int u,int v){
    e[idx] = {v, head[u]}, head[u] = idx ++;
    e[idx] = {u, head[v]}, head[v] = idx ++;
}
void pushUp(int p) { (t[p].val += t[p << 1].val + t[p << 1 | 1].val) %= mod; }
void addTag(int p, int pl, int pr, int d) {
    t[p].tag += d;
    (t[p].val += (t[p].val + d * (pr - pl + 1))) %= mod;
}
void pushDown(int p, int pl, int pr){
    if (t[p].tag) {
        int mid = pl + pr >> 1;
        addTag(p << 1, pl, mid, t[p].tag);
        addTag(p << 1 | 1, mid + 1, pr, t[p].tag);
        t[p].tag = 0;
    }
}
void build (int p, int pl, int pr) {
    if (pl == pr) {
        t[p].val = w_new[pl] % mod;
        return;
    }
    int mid = pl + pr >> 1;
    build(p << 1, pl, mid);
    build(p << 1 | 1, mid + 1, pr);
    pushUp(p);
}
void update(int L, int R, int p, int pl, int pr, int d) {
    if (L <= pl && pr <= R) {
        addTag(p, pl, pr, d);
        return;
    }
    pushDown(p, pl, pr);
    int mid = pl + pr >> 1;
    if (L <= mid) update(L, R, p << 1, pl, mid, d);
    if (R > mid) update(L, R, p << 1 | 1, mid + 1, pr, d);
    pushUp(p);
}
int query(int L, int R, int p, int pl, int pr) {
    if (L <= pl && pr <= R) return t[p].val % mod;
    pushDown(p, pl, pr);
    int mid = pl + pr >> 1, res{};
    if (L <= mid) (res += query(L, R, p << 1, pl, mid)) %= mod;
    if (R > mid) (res += query(L, R, p << 1 | 1, mid + 1, pr)) %= mod;
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