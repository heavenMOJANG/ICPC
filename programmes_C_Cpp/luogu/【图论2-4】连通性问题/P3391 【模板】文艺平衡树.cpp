#pragma GCC optimize(1)
#pragma GCC optimize(2)
#pragma GCC optimize(3,"Ofast","inline")
#include<bits/stdc++.h>
typedef long long ll;
using namespace std;
constexpr ll inf=0x7fffffff;
constexpr ll M=1e5+10;
ll n,m,cnt,root;
struct Node{ll l,r,val,pri,siz,lazy;}t[M];
void newNode(ll x){
    cnt++;
    t[cnt].siz=1;
    t[cnt].l=t[cnt].r=0;
    t[cnt].pri=rand();
    t[cnt].val=x;
}
void update(ll u){t[u].siz=t[t[u].l].siz+t[t[u].r].siz+1;}
void pushDown(ll u){
    if(t[u].lazy){
        swap(t[u].l,t[u].r);
        t[t[u].l].lazy^=1;
        t[t[u].r].lazy^=1;
        t[u].lazy=0;
    }
}
void split(ll u,ll x,ll&L,ll&R){
    if(u==0){L=R=0;return;}
    pushDown(u);
    if(t[t[u].l].siz+1<=x){
        L=u;
        split(t[u].r,x-t[t[u].l].siz-1,t[u].r,R);
    }
    else{
        R=u;
        split(t[u].l,x,L,t[u].l);
    }
    update(u);
}
ll merge(ll L,ll R){
    if(L==0||R==0) return L+R;
    if(t[L].pri>t[R].pri){
        pushDown(L);
        t[L].r=merge(t[L].r,R);
        update(L);
        return L;
    }
    else{
        pushDown(R);
        t[R].l=merge(L,t[R].l);
        update(R);
        return R;
    }
}
void inOrder(ll u){
    if(u==0) return;
    pushDown(u);
    inOrder(t[u].l);
    cout<<t[u].val<<" ";
    inOrder(t[u].r);
}
void solve(){
    srand(time(NULL));
    cin>>n>>m;
    for(ll i=1;i<=n;++i){newNode(i);root=merge(root,cnt);}
    for(ll i=1,l,r;i<=m;++i){
        cin>>l>>r;
        ll L,R,p;
        split(root,r,L,R);
        split(L,l-1,L,p);
        t[p].lazy^=1;
        root=merge(merge(L,p),R);
    }
    inOrder(root);
    return;
}
int main(int argc,const char*argv[]){
    ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    ll _=1;
    while(_--) solve();
    return 0;
}
