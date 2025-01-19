#pragma GCC optimize(1)
#pragma GCC optimize(2)
#pragma GCC optimize(3,"Ofast","inline")
#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef unsigned long long ull;
typedef pair<int,int>PII;
typedef pair<ll,ll>PLL;
const ll inf=0x7f;
ll dx[]={-1,1,0,0};
ll dy[]={0,0,-1,1};
ll n,cnt,root;
struct Node{ll ls,rs,key,pri,size;}tree[1000010];
void newNode(ll x){tree[++cnt]={0,0,x,rand(),1};}
void update(ll u){tree[u].size=tree[tree[u].ls].size+tree[tree[u].rs].size+1;}
void split(ll u,ll x,ll&l,ll&r){
    if(!u){l=r=0;return;}
    if(tree[u].key<=x){
        l=u;
        split(tree[u].rs,x,tree[u].rs,r);
    }
    else{
        r=u;
        split(tree[u].ls,x,l,tree[u].ls);
    }
    update(u);
}
ll merge(ll l,ll r){
    if(!l||!r) return l+r;
    if(tree[l].pri>tree[r].pri){
        tree[l].rs=merge(tree[l].rs,r);
        update(l);
        return l;
    }
    else{
        tree[r].ls=merge(l,tree[r].ls);
        update(r);
        return r;
    }
}
void insert(ll x){
    ll l,r;
    split(root,x,l,r);
    newNode(x);
    ll aa=merge(l,cnt);
    root=merge(aa,r);
}
void del(ll x){
    ll l,r,p;
    split(root,x,l,r);
    split(l,x-1,l,p);
    p=merge(tree[p].ls,tree[p].rs);
    root=merge(merge(l,p),r);
}
void Rank(ll x){
    ll l,r;
    split(root,x-1,l,r);
    cout<<tree[l].size+1<<"\n";
    root=merge(l,r);
}
ll kth(ll u,ll k){
    if(k==tree[tree[u].ls].size+1) return u;
    if(k<=tree[tree[u].ls].size) return kth(tree[u].ls,k);
    return kth(tree[u].rs,k-tree[tree[u].ls].size-1);
}
void precursor(ll x){
    ll l,r;
    split(root,x-1,l,r);
    cout<<tree[kth(l,tree[l].size)].key<<"\n";
    root=merge(l,r);
}
void successor(ll x){
    ll l,r;
    split(root,x,l,r);
    cout<<tree[kth(r,1)].key<<"\n";
    root=merge(l,r);
}
int main(int argc,const char*argv[]){
    ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    srand(time(NULL));
    cin>>n;
    while(n--){
        ll op,x;cin>>op>>x;
        switch(op){
            case 1:insert(x);break;
            case 2:del(x);break;
            case 3:Rank(x);break;
            case 4:cout<<tree[kth(root,x)].key<<"\n";break;
            case 5:precursor(x);break;
            case 6:successor(x);break;
        }
    }
    return 0;
}